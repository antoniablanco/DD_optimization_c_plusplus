
#ifndef DD_OPTIMIZATION_PROGRAM_GRAPH_H
#define DD_OPTIMIZATION_PROGRAM_GRAPH_H

#include "Node.h"
#include "Arc.h"

#include <iostream>
#include <string>
#include <vector>



class Graph {
public:
    Graph(Node& initial_node);

    std::vector<Node> nodes;
    std::vector<std::vector<Node>> structure;
    int actual_layer;

    bool operator==(const Graph &other) const;

    void add_node(Node& node);

    void add_new_layer();

    void eliminate_node_and_his_arcs(Node& node);

    void remove_node(Node& node);

private:
    bool compare_two_nodes(const Node& nodeOne, const Node& nodeTwo) const;
    void remove_node_from_layer(Node& node);
};


#endif //DD_OPTIMIZATION_PROGRAM_GRAPH_H
