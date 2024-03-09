//
// Created by antonia blanco on 12-02-24.
//

#include "Arc.h"
#include "Node.h"

#include <string>

template <typename T>
Arc<T>::Arc(Node<T>* out_node, Node<T>* in_node, int variable_value, string variable_id)
        : out_node(out_node), in_node(in_node), variable_value(variable_value), variable_id(variable_id) {}

template <typename T>
string Arc<T>::to_string() const {
    return "arc_" + std::to_string(out_node->get_id()) + "_" + std::to_string(in_node->get_id());
}

template <typename T>
ostream& operator<<(std::ostream& os, const Arc<T>& arc) {
    os << "arc_" << std::to_string(arc.out_node->get_id()) << "_" + std::to_string(arc.in_node->get_id());
    return os;
}

template <typename T>
bool Arc<T>::operator==(const Arc<T> &other) const {
    return out_node->id == other.out_node->id and in_node->id == other.in_node->id and
           variable_value == other.variable_value and variable_id == other.variable_id;
}


