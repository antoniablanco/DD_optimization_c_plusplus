
#include "Node.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


template <typename T>
Node<T>::Node(int node_id, T state) : id(node_id), state(state) {}

template <typename T>
Node<T>::~Node() {
}

template <typename T>
string Node<T>::to_string() const {
    return "u_" + std::to_string(id)  + " ";
}


template <typename T>
ostream& operator<<(std::ostream& os, const Node<T> node) {
    os << "u_" + std::to_string(node.id)  + " ";
    return os;
}


template <typename T>
bool Node<T>::operator==(const Node<T> &other) const {
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

template <typename T>
T Node<T>::get_state() const {
    return state;
}

template <typename T>
void Node<T>::add_in_arc(Arc<T>* arc) {
    in_arcs.push_back(arc);
}

template <typename T>
void Node<T>::add_out_arc(Arc<T>* arc) {
    out_arcs.push_back(arc);
}