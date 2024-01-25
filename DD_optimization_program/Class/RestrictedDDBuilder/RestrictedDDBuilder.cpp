#include "RestrictedDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


RestrictedDDBuilder::RestrictedDDBuilder(AbstractProblem& problem, int max_width) : 
AbstractDDBuilder(problem), max_width(max_width) {}

void RestrictedDDBuilder::specific_layer_function() {
    eliminate_nodes_when_width_is_greater_than_w();
}

void RestrictedDDBuilder::specific_final_function() {
    eliminate_nodes_without_out_arcs();
    adjust_node_number();
}

void RestrictedDDBuilder::eliminate_nodes_when_width_is_greater_than_w() {
    
}

void RestrictedDDBuilder::width_is_greater_than_w() {
    
}

void RestrictedDDBuilder::eliminate_nodes() {
    
}

void RestrictedDDBuilder::eliminate_nodes_without_out_arcs() {
    
}

void RestrictedDDBuilder::adjust_node_number() {
    
}


