//
// Created by antonia blanco on 18-01-24.
//

#include "Graph.h"
#include "Node.h"

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
Graph<T>::Graph(Node<T>* initial_node) : nodes(), structure(), actual_layer(0) {
    nodes.push_back(initial_node);
    structure.push_back({initial_node});
}

template <typename T>
bool Graph<T>::operator==(const Graph<T> &other) const {
    bool result = true;

    for (size_t i = 0; i < structure.size(); ++i) {
        if (structure[i].size() != other.structure[i].size()) {
            return false;
        }

        bool there_is_equal_node = false;

        for (size_t j = 0; j < structure[i].size(); ++j) {
            const Node<T> node = structure[i][j];

            for (size_t k = 0; k < other.structure[i].size(); ++k) {
                const Node<T> other_node = other.structure[i][k];

                if (node->state == other_node->state) {
                    there_is_equal_node = there_is_equal_node || compare_two_nodes(node, other_node);
                }
            }
        }
    }

    return result;
}

template <typename T>
bool Graph<T>::compare_two_nodes(const Node<T>& nodeOne, const Node<T>& nodeTwo) const {
    bool return_in_arcs = true;
    for (auto& arc : nodeOne.in_arcs) {
        bool there_is_equal_arc = false;

        for (auto& other_arc : nodeTwo.in_arcs) {
            if (arc.variable_value == other_arc.variable_value and arc.out_node.state==other_arc.out_node.state) {
                there_is_equal_arc = true;
            }
        }
        return_in_arcs = return_in_arcs && there_is_equal_arc;
    }

    bool return_out_arcs = true;
    for (auto& arc : nodeOne.out_arcs) {
        bool there_is_equal_arc = false;

        for (auto& other_arc : nodeTwo.out_arcs) {
            if (arc.variable_value == other_arc.variable_value and arc.in_node.state==other_arc.in_node.state) {
                there_is_equal_arc = true;
            }
        }
        return_out_arcs = return_out_arcs && there_is_equal_arc;
    }

    return return_in_arcs && return_out_arcs;
}

template <typename T>
void Graph<T>::add_node(Node<T>& node) {
    auto iterator = find(nodes.begin(), nodes.end(), node);
    if (iterator == nodes.end()) {
        nodes.push_back(node);
        structure[actual_layer].push_back(node);
    }
}

template <typename T>
void Graph<T>::add_new_layer() {
    actual_layer++;
    structure.push_back({});
}

template <typename T>
void Graph<T>::eliminate_node_and_his_arcs(Node<T>& node) {
    remove_node_from_layer(node);

    for (auto& arc : node.in_arcs) {
        arc.out_node.out_arcs.erase(
                remove(arc.out_node.out_arcs.begin(), arc.out_node.out_arcs.end(), arc),
                arc.out_node.out_arcs.end()
        );

        delete arc;
    }

    node.in_arcs.clear();
    remove_node(node);
    delete node;
}

template <typename T>
void Graph<T>::remove_node(Node<T>& node) {
    auto iterator = find(nodes.begin(), nodes.end(), node);

    if (iterator != nodes.end()) {
        nodes.erase(iterator);
        remove_node_from_layer(node);
    }
}

template <typename T>
void Graph<T>::remove_node_from_layer(Node<T>& node) {
    for (auto& layer : structure) {
        auto iterator = find(layer.begin(), layer.end(), node);

        if (iterator != layer.end()) {
            layer.erase(iterator);
        }
    }
}