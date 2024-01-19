
#ifndef DD_OPTIMIZATION_PROGRAM_GRAPH_H
#define DD_OPTIMIZATION_PROGRAM_GRAPH_H

#include "Node.h"
#include "Arc.h"

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Graph {
public:
    Graph(Node<T>* initial_node);

    std::vector<Node<T>*> nodes;
    std::vector<std::vector<Node<T>*>> structure;
    int actual_layer;

    bool operator==(const Graph<T> &other) const;

    void add_node(Node<T>& node);

    void add_new_layer();

    void eliminate_node_and_his_arcs(Node<T>& node);

    void remove_node(Node<T> &node);

private:
    bool compare_two_nodes(const Node<T>& nodeOne, const Node<T>& nodeTwo) const;
    void remove_node_from_layer(Node<T>& node);
};
#endif //DD_OPTIMIZATION_PROGRAM_GRAPH_H
