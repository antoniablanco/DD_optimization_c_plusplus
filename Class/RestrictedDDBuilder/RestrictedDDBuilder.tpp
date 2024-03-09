#include "RestrictedDDBuilder.h"

using namespace std;

template <typename T>
RestrictedDDBuilder<T>::RestrictedDDBuilder(AbstractProblem<T>& problem, int max_width) :
        AbstractDDBuilder<T>(problem), max_width(max_width) {}

template <typename T>
void RestrictedDDBuilder<T>::specificLayerFunction() {
    eliminate_nodes_when_width_is_greater_than_w();
}

template <typename T>
void RestrictedDDBuilder<T>::specific_final_function() {
    eliminate_nodes_without_out_arcs();
    adjust_node_number();
}

template <typename T>
void RestrictedDDBuilder<T>::eliminate_nodes_when_width_is_greater_than_w() {
    if (width_is_greater_than_w()) {
        vector<Node<T>*> ordered_nodes = this->graph->structure.back();
        sort(ordered_nodes.begin(), ordered_nodes.end(), [this](Node<T>* node1, Node<T>* node2) {
            return this->problem.get_priority_for_discard_node(node1->state) <
                    this->problem.get_priority_for_discard_node(node2->state);
        });

        vector<Node<T>*> nodesToEliminate(ordered_nodes.begin() + max_width, ordered_nodes.end());

        eliminate_nodes(nodesToEliminate);
    }
}

template <typename T>
bool RestrictedDDBuilder<T>::width_is_greater_than_w() {
    return this->graph -> structure.back().size() > max_width;
}

template <typename T>
void RestrictedDDBuilder<T>::eliminate_nodes(const vector<Node<T>*>& nodes_to_eliminate) {
    for (Node<T>* node : nodes_to_eliminate) {
        this->graph->eliminate_node_and_his_arcs(*node);
    };
}

template <typename T>
void RestrictedDDBuilder<T>::eliminate_nodes_without_out_arcs() {
    vector<vector<Node<T>*>> nodesInLayers = this->graph->structure;
    reverse(nodesInLayers.begin(), nodesInLayers.end());

    for (size_t i = 1; i < nodesInLayers.size(); ++i) {
        for (Node<T>* node : nodesInLayers[i]) {
            if (node->out_arcs.empty()) {
                this->graph->eliminate_node_and_his_arcs(*node);
            }
        }
    }
}

template <typename T>
void RestrictedDDBuilder<T>::adjust_node_number() {
    int initial_node_number = 0;
    for (const vector<Node<T>*>& layer : this->graph->structure) {
        for (Node<T>* node : layer) {
            node->set_id(initial_node_number);
            initial_node_number++;
        }
    }
}



