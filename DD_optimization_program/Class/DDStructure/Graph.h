
#ifndef DD_OPTIMIZATION_PROGRAM_GRAPH_H
#define DD_OPTIMIZATION_PROGRAM_GRAPH_H

#include "Node.h"
#include "Arc.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Graph {
public:
    Graph(Node* initial_node);

    Graph() = default;

    vector<Node*> nodes;
    vector<vector<Node*>> structure;
    int actual_layer;

    bool operator==(const Graph &other) const;

    void add_node(Node* node);

    void add_new_layer();

    void eliminate_node_and_his_arcs(Node& node);

    void remove_node(Node& node);

    ~Graph() = default;

private:
    bool compare_two_nodes(const Node& nodeOne, const Node& nodeTwo) const;
    void remove_node_from_layer(Node& node);
};


#endif //DD_OPTIMIZATION_PROGRAM_GRAPH_H
