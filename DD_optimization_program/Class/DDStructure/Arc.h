
#ifndef DD_OPTIMIZATION_PROGRAM_ARC_H
#define DD_OPTIMIZATION_PROGRAM_ARC_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node;

class Arc {
public:
    Arc(Node& out_node, Node& in_node, int variable_value, std::string variable_id);
    Node& out_node;
    Node& in_node;
    int variable_value;
    std::string variable_id;

    std::string to_string() const;
    bool operator==(const Arc &other) const;
};

#endif //DD_OPTIMIZATION_PROGRAM_ARC_H
