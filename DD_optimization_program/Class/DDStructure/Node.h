
#ifndef DD_OPTIMIZATION_PROGRAM_NODE_H
#define DD_OPTIMIZATION_PROGRAM_NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Arc;

class Node {
public:
    Node(int id, vector<int> state);
    Node() = default;
    int id;
    vector<int> state;
    list<Arc> in_arcs;
    list<Arc> out_arcs;

    std::string to_string() const;
    bool operator==(const Node &other) const;
    void add_in_arc(Arc& arc);
    void add_out_arc(Arc& arc);
    void remove_in_arc(Arc& arc);
    void remove_out_arc(Arc& arc);
};

#endif //DD_OPTIMIZATION_PROGRAM_NODE_H
