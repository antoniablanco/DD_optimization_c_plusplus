// Node.cpp

#include "Node.h"
#include "Arc.h"
#include "utils.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

Node::Node(int node_id, vector<int> state) : id(node_id), state(state) {}

Node::~Node() {
    for (auto& arc : in_arcs) {
        delete arc;
    }
}

string Node::to_string() const {
    return "u_" + std::to_string(id)  + " ";
}

ostream& operator<<(std::ostream& os, const Node& node) {
    os << "u_" << std::to_string(node.id) << " " + to_string_int_vector(node.state);
    return os;
}

ostream& operator<<(std::ostream& os, const vector<int>& state) {
    os << "[";
    for (size_t i = 0; i < state.size(); ++i) {
        os << state[i];
        if (i != state.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

bool Node::operator==(const Node &other) const {
    bool same_in_arc;
    bool same_out_arc;
    if (in_arcs.size() == other.in_arcs.size()) {
        same_in_arc = std::equal(in_arcs.begin(), in_arcs.end(), other.in_arcs.begin());
    } else {
        same_in_arc = false;
    }
    if (out_arcs.size() == other.out_arcs.size()) {
        same_out_arc = std::equal(out_arcs.begin(), out_arcs.end(), other.out_arcs.begin());
    } else {
        same_out_arc = false;
    }
    return state == other.state and same_in_arc and same_out_arc;
}

void Node::add_in_arc(Arc* arc) {
    in_arcs.push_back(arc);
}

void Node::add_out_arc(Arc* arc) {
    out_arcs.push_back(arc);
}

