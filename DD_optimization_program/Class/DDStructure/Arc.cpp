
#include "Arc.h"
#include "Node.h"

#include <string>

using namespace std;

template <typename T>
Arc<T>::Arc(Node<T>* out_node, Node<T>* in_node, int variable_value, string variable_id)
        : out_node(out_node), in_node(in_node), variable_value(variable_value), variable_id(variable_id) {}

template <typename T>
string Arc<T>::to_string() {
    return "arc_" + to_string(out_node->id) + "_" + to_string(in_node->id);
}