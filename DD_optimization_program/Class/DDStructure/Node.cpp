// Node.cpp

#include "Node.h"
#include "Arc.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
Node<T>::Node(int id, T state) : id(id), state(state), in_arcs(), out_arcs() {}

template <typename T>
string Node<T>::to_string() {
    return "u_" + to_string(id)  + " " + to_string(state);
}

template <typename T>
void Node<T>::add_in_arc(Arc<T>* arc) {
    in_arcs.push_back(arc);
}

template <typename T>
void Node<T>::add_out_arc(Arc<T>* arc) {
    out_arcs.push_back(arc);
}

template <typename T>
void Node<T>::remove_in_arc(Arc<T>* arc) {
    std::erase(out_arcs, arc);
}

template <typename T>
void Node<T>::remove_out_arc(Arc<T>* arc) {
    std::erase(out_arcs, arc);
}
