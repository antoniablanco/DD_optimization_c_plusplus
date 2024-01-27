#include "ReduceDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;


ReduceDDBuilder::ReduceDDBuilder(Graph* graph) : graph(graph), layer_working(graph->actual_layer) {
}

Graph ReduceDDBuilder::get_desition_diagram(bool should_visualize) {
    auto reversedStructure = graph->structure;
    reverse(reversedStructure.begin(), reversedStructure.end());

    for (const auto& layer : reversedStructure) {
        print_graph(should_visualize);
        layer_working -=1;
        reviewing_layer(layer);
    }

    specific_final_function();
    print_graph(should_visualize);
                
    return *graph;
}

void ReduceDDBuilder::reviewing_layer(vector<Node*> layer) {
    for (size_t i = 0; i < layer.size(); ++i) {
        Node* nodeOne = layer[i];

        vector<Node*> nodes(layer.begin() + i + 1, layer.end());

        while (!nodes.empty()) {
            Node* nodeTwo = nodes.front();
            nodes.erase(nodes.begin());

            if (checking_if_two_nodes_should_merge(nodeOne, nodeTwo)) {
                cout << "Merge: " << nodeOne->to_string() << " and " << nodeTwo->to_string() << endl;
                merge_nodes(nodeOne, nodeTwo);
            }
        }
    }
}

bool ReduceDDBuilder::checking_if_two_nodes_should_merge(Node* node_one, Node* node_two) {
    vector<string> PathsOfNodeOne = get_node_of_every_type_of_path(node_one);
    vector<string> PathsOfNodeTwo = get_node_of_every_type_of_path(node_two);
    cout << "Paths of node one: " << to_string_string_vector(PathsOfNodeOne) << endl;
    cout << "Paths of node two: " << to_string_string_vector(PathsOfNodeTwo) << endl;
    return PathsOfNodeOne == PathsOfNodeTwo;
}

vector<string> ReduceDDBuilder::get_node_of_every_type_of_path(Node* node) {
    vector<string> nodesOfPath = {};
    for (Arc* arc : node->out_arcs) {

        std::ostringstream ss;
        ss << arc->out_node->to_string() << "_" << to_string(arc->variable_value);

        nodesOfPath.push_back(ss.str());
    }
    return nodesOfPath;
}

void ReduceDDBuilder::merge_nodes(Node* node_one, Node* node_two) {
    std::pair<Node*, Node*> order = get_order_of_changin_nodes(node_one, node_two);
    Node* node_to_remove = order.first;
    Node* node_to_keep = order.second;

    redirect_in_arcs(node_to_remove, node_to_keep);
    delete_out_arcs(node_to_remove);
    delete_node(node_to_remove);
}

pair<Node*, Node*> ReduceDDBuilder::get_order_of_changin_nodes(Node* node_one, Node* node_two) {
    vector<Node*> current_layer = graph->structure[layer_working];

    auto find_node_one = find(current_layer.begin(), current_layer.end(), node_one);
    auto find_node_two = find(current_layer.begin(), current_layer.end(), node_two);

    if (find_node_one != current_layer.end() && find_node_two != current_layer.end()) {
        if (distance(current_layer.begin(), find_node_one) > distance(current_layer.begin(), find_node_two)) {
            return make_pair(node_one, node_two);
        } else {
            return make_pair(node_two, node_one);
        }
    } else {
        cout << "Error: No se encuentran los nodos en la capa actual" << endl;
        return std::make_pair(static_cast<Node*>(nullptr), static_cast<Node*>(nullptr));
}

}

void ReduceDDBuilder::redirect_in_arcs(Node* node_to_remove, Node* node_to_keep) {

    for (Arc* arc : node_to_remove->in_arcs) {
        arc->in_node = node_to_keep;

        if (find(node_to_keep->in_arcs.begin(), node_to_keep->in_arcs.end(), arc) == node_to_keep->in_arcs.end()) {
            node_to_keep->add_in_arc(arc);
        }
    }
    node_to_remove->in_arcs.clear();
}

void ReduceDDBuilder::delete_out_arcs(Node* node_to_remove) {
    for (Arc* arc : node_to_remove->out_arcs) {
        arc->out_node = nullptr;
    }
    node_to_remove->out_arcs.clear();
}

void ReduceDDBuilder::delete_node(Node* node_to_remove) {
    graph->remove_node(*node_to_remove);
    delete node_to_remove;
}

void ReduceDDBuilder::specific_final_function() {
    adjust_node_number();
}

void ReduceDDBuilder::adjust_node_number() {
    int initial_node_number = 0;
    for (vector<Node*> layer : graph->structure) {
        for (Node* node : layer) {
            node->id = initial_node_number;
            initial_node_number++;
        }
    }
}

void ReduceDDBuilder::print_graph(bool should_visualize) {
    if (should_visualize) {
        print();
    }
}

void ReduceDDBuilder::print() {
    
    cout << "" << endl;
    for (const auto& layer : graph->structure) {
        cout << "------------------------------------------------------" << endl;
        for (auto& node : layer) {
            string in_arcs_str;
            for (const auto& arc : node->in_arcs) {
                in_arcs_str += arc->to_string() + " ";
            }
            in_arcs_str = in_arcs_str.empty() ? "" : in_arcs_str.substr(0, in_arcs_str.size() - 1);
            cout << node->to_string() << "(" << in_arcs_str << ") ";
        }
        cout << "" << endl;
    }
}