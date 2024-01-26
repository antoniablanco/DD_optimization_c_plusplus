#include "RestrictedDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


RestrictedDDBuilder::RestrictedDDBuilder(AbstractProblem& problem, int max_width) : 
AbstractDDBuilder(problem), max_width(max_width) {}

void RestrictedDDBuilder::specific_layer_function() {
    eliminate_nodes_when_width_is_greater_than_w();
}

void RestrictedDDBuilder::specific_final_function() {
    eliminate_nodes_without_out_arcs();
    adjust_node_number();
}

void RestrictedDDBuilder::eliminate_nodes_when_width_is_greater_than_w() {
    if (width_is_greater_than_w()) {
        vector<Node*> ordered_nodes = graph->structure.back();
        sort(ordered_nodes.begin(), ordered_nodes.end(), [this](Node* node1, Node* node2) {
            return problem.get_priority_for_discard_node(node1->state) <
                    problem.get_priority_for_discard_node(node2->state);
        });

        vector<Node*> nodesToEliminate(ordered_nodes.begin() + max_width, ordered_nodes.end());

        eliminate_nodes(nodesToEliminate);
    }
}

bool RestrictedDDBuilder::width_is_greater_than_w() {
    return graph -> structure.back().size() > max_width;
}

void RestrictedDDBuilder::eliminate_nodes(vector<Node*> nodes_to_eliminate) {
    for (Node* node : nodes_to_eliminate) {
        graph->eliminate_node_and_his_arcs(*node);
        };
}

void RestrictedDDBuilder::eliminate_nodes_without_out_arcs() {
    vector<vector<Node*>> nodesInLayers = graph->structure;
    reverse(nodesInLayers.begin(), nodesInLayers.end());

    for (size_t i = 1; i < nodesInLayers.size(); ++i) {
        for (Node* node : nodesInLayers[i]) {
            if (node->out_arcs.empty()) {
                graph->eliminate_node_and_his_arcs(*node);
            }
        }
    }
}

void RestrictedDDBuilder::adjust_node_number() {
    int initial_node_number = 0;
    for (vector<Node*> layer : graph->structure) {
        for (Node* node : layer) {
            node->id = initial_node_number;
            initial_node_number++;
        }
    }
}


