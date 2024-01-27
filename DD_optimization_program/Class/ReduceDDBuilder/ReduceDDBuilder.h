#ifndef DD_OPTIMIZATION_PROGRAM_REDUCEDDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_REDUCEDDBUILDER_H

#include "Node.h"
#include "Arc.h"
#include "Graph.h"
#include "utils.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ReduceDDBuilder{
public:
    ReduceDDBuilder(Graph* graph);

    Graph* graph;
    Graph get_desition_diagram(bool should_visualize);
    ~ReduceDDBuilder() = default;

private:
    int layer_working;

    void reviewing_layer(vector<Node*> layer);
    bool checking_if_two_nodes_should_merge(Node* node_one, Node* node_two);
    vector<string> get_node_of_every_type_of_path(Node* node);
    void merge_nodes(Node* node_one, Node* node_two);
    pair<Node*, Node*> get_order_of_changin_nodes(Node* node_one, Node* node_two);
    void redirect_in_arcs(Node* node_to_remove, Node* node_to_keep);
    void delete_out_arcs(Node* node_to_remove);
    void delete_node(Node* node_to_remove);
    void specific_final_function();
    void adjust_node_number();
    void print_graph(bool should_visualize);
    void print();
        
};

#endif //DD_OPTIMIZATION_PROGRAM_REDUCEDDBUILDER_H