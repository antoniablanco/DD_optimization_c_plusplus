#include "RelaxedDDBuilder.h"

#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
RelaxedDDBuilder<T>::RelaxedDDBuilder(AbstractProblem<T>& problem, int max_width) :
        AbstractDDBuilder<T>(problem), max_width(max_width) {
}

template <typename T>
void RelaxedDDBuilder<T>::specificLayerFunction() {
    merge_nodes_when_width_is_greater_than_w();
}

template <typename T>
void RelaxedDDBuilder<T>::specific_final_function() {
    adjust_node_number();
}

template <typename T>
void RelaxedDDBuilder<T>::merge_nodes_when_width_is_greater_than_w() {
    while (width_is_greater_than_w()) {
        vector<Node<T>*> ordered_nodes = this->graph->structure.back();

        sort(ordered_nodes.begin(), ordered_nodes.end(), [&](const Node<T>* node1, const Node<T>* node2) {
            return this->problem.get_priority_for_merge_nodes(node1->id, node1->state) >
                    this->problem.get_priority_for_merge_nodes(node2->id, node2->state);
        });

        merge_nodes(ordered_nodes[0], ordered_nodes[1]);
    }
}

template <typename T>
bool RelaxedDDBuilder<T>::width_is_greater_than_w() {
    return this->graph -> structure.back().size() > max_width;
}

template <typename T>
void RelaxedDDBuilder<T>::merge_nodes(Node<T>* node_to_remove, Node<T>* node_to_keep) {
    vector<int> new_state = this->problem.merge_operator(node_to_remove->state, node_to_keep->state);
    auto result = this->exist_node_with_same_state(new_state);
    bool exist_node = result.first;
    Node<T>* same_state_node = result.second;

    if (exist_node and (same_state_node!=node_to_keep) and (same_state_node!=node_to_remove)){
        merge_with_an_existing_node(node_to_remove, node_to_keep, same_state_node);
    }
    else {
        merge_when_doesnt_exist_node(node_to_remove, node_to_keep, new_state);
    }
}

template <typename T>
void RelaxedDDBuilder<T>::merge_with_an_existing_node(Node<T>* node_one, Node<T>* node_two, Node<T>* exist_node) {
    redirect_in_arcs(node_one, exist_node);
    redirect_in_arcs(node_two, exist_node);
    delete_node(node_one);
    delete_node(node_two);
}

template <typename T>
void RelaxedDDBuilder<T>::merge_when_doesnt_exist_node(Node<T>* node_to_remove, Node<T>* node_to_keep, vector<int> new_state) {
    redirect_in_arcs(node_to_remove, node_to_keep);
    change_new_state(node_to_keep, std::move(new_state));
    delete_node(node_to_remove);
}

template <typename T>
void RelaxedDDBuilder<T>::redirect_in_arcs(Node<T>* node_to_remove, Node<T>* node_to_keep) {

    for (Arc<T>* arc : node_to_remove->in_arcs) {
        arc->in_node = node_to_keep;

        if (std::find(node_to_keep->in_arcs.begin(), node_to_keep->in_arcs.end(), arc) == node_to_keep->in_arcs.end()) {
            node_to_keep->add_in_arc(arc);
        }
    }
    node_to_remove->in_arcs.clear();
}

template <typename T>
void RelaxedDDBuilder<T>::change_new_state(Node<T>* node, vector<int> new_state) {
    node->state = std::move(new_state);
}

template <typename T>
void RelaxedDDBuilder<T>::delete_node(Node<T>* node_to_remove) {
    this->graph->remove_node(*node_to_remove);
    delete node_to_remove;
}

template <typename T>
void RelaxedDDBuilder<T>::adjust_node_number() {
    int initial_node_number = 0;
    for (const vector<Node<T>*>& layer : this->graph->structure) {
        for (Node<T>* node : layer) {
            node->id = initial_node_number;
            initial_node_number++;
        }
    }
}