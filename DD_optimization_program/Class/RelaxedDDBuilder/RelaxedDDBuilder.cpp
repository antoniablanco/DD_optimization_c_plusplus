#include "RelaxedDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


RelaxedDDBuilder::RelaxedDDBuilder(AbstractProblem& problem, int max_width) : 
AbstractDDBuilder(problem), max_width(max_width) {}

void RelaxedDDBuilder::specific_layer_function() {
    merge_nodes_when_width_is_greater_than_w();
}

void RelaxedDDBuilder::specific_final_function() {
    adjust_node_number();
}

void RelaxedDDBuilder::merge_nodes_when_width_is_greater_than_w() {
    if (width_is_greater_than_w()) {
        vector<Node*> ordered_nodes = graph->structure.back();
        sort(ordered_nodes.begin(), ordered_nodes.end(), [this](Node* node1, Node* node2) {
            return problem.get_priority_for_discard_node(node1->state) <
                    problem.get_priority_for_discard_node(node2->state);
        });

        merge_nodes(ordered_nodes[0], ordered_nodes[1]);
    }
}

bool RelaxedDDBuilder::width_is_greater_than_w() {
    return graph -> structure.back().size() > max_width;
}

void RelaxedDDBuilder::merge_nodes(Node* node_to_remove, Node* node_to_keep) {
    vector<int> new_state = problem.merge_operator(node_to_remove->state, node_to_keep->state);
    auto result = exist_node_with_same_state(new_state);
    bool exist_node = result.first;
    Node* same_state_node = result.second;

    if (exist_node and (same_state_node!=node_to_keep) and (same_state_node!=node_to_remove)){
        merge_with_an_existing_node(node_to_remove, node_to_keep, same_state_node);
    }
    else {
        merge_when_doesnt_exist_node(node_to_remove, node_to_keep, new_state);
    }
}

void RelaxedDDBuilder::merge_with_an_existing_node(Node* node_one, Node* node_two, Node* exist_node) {
    redirect_in_arcs(node_one, exist_node);
    redirect_in_arcs(node_two, exist_node);
    delete_node(node_one);
    delete_node(node_two);
}

void RelaxedDDBuilder::merge_when_doesnt_exist_node(Node* node_to_remove, Node* node_to_keep, vector<int> new_state) {
    redirect_in_arcs(node_to_remove, node_to_keep);
    change_new_state(node_to_keep, new_state);
    delete_node(node_to_remove);
}

void RelaxedDDBuilder::redirect_in_arcs(Node* node_to_remove, Node* node_to_keep) {

    for (Arc* arc : node_to_remove->in_arcs) {
        arc->in_node = node_to_keep;

        if (std::find(node_to_keep->in_arcs.begin(), node_to_keep->in_arcs.end(), arc) == node_to_keep->in_arcs.end()) {
            node_to_keep->add_in_arc(arc);
        }
    }
    node_to_remove->in_arcs.clear();
}

void RelaxedDDBuilder::change_new_state(Node* node, vector<int> new_state) {
    node->state = new_state;
}

void RelaxedDDBuilder::delete_node(Node* node_to_remove) {
    graph->remove_node(*node_to_remove);
    delete node_to_remove;
}

void RelaxedDDBuilder::adjust_node_number() {
    int initial_node_number = 0;
    for (vector<Node*> layer : graph->structure) {
        for (Node* node : layer) {
            node->id = initial_node_number;
            initial_node_number++;
        }
    }
}