
#include "Arc.h"
#include "Node.h"

#include <string>

Arc::Arc(Node* out_node, Node* in_node, int variable_value, string variable_id)
        : out_node(out_node), in_node(in_node), variable_value(variable_value), variable_id(variable_id) {}

string Arc::to_string() const {
    return "arc_" + std::to_string(out_node->id) + "_" + std::to_string(in_node->id);
}

bool Arc::operator==(const Arc &other) const {
    return out_node->id == other.out_node->id and in_node->id == other.in_node->id and
           variable_value == other.variable_value and variable_id == other.variable_id;
}