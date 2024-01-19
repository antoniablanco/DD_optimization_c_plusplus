
#ifndef DD_OPTIMIZATION_PROGRAM_ARC_H
#define DD_OPTIMIZATION_PROGRAM_ARC_H

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Node;

template <typename T>
class Arc {
public:
    Arc(Node<T>* out_node, Node<T>* in_node, int variable_value, std::string variable_id);
    Node<T>* out_node;
    Node<T>* in_node;
    int variable_value;
    std::string variable_id;
    std::string to_string();
};

#endif //DD_OPTIMIZATION_PROGRAM_ARC_H
