#ifndef DD_OPTIMIZATION_PROGRAM_ABSTRACTDDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_ABSTRACTDDBUILDER_H

#include "Node.h"
#include "Arc.h"
#include "Graph.h"
#include "AbstractProblemClass.h"
#include "utils.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>

class AbstractDDBuilder{
public:
    AbstractDDBuilder(AbstractProblem& problem);

    Graph graph;
    Graph get_desition_diagram(bool should_visualize);

    virtual ~AbstractDDBuilder() = default;

protected:
    int node_number;
    AbstractProblem& problem;
    vector<string> variables;
    map<string, vector<int>> variables_domain;

private:
    Graph initialize_graph(vector<int>& initial_state);
    void create_new_layer(int variable_id);
    void create_new_nodes_in_the_new_layer(int variable_id);
    void check_if_new_node_should_be_created(int variable_value, Node* existed_node, int variable_id);
    bool there_is_node_in_last_layer(int variable_id);
    void create_arcs_for_the_terminal_node(int variable_value, Node* existed_node, int variable_id);
    void create_rest_of_arcs(int variable_value, Node* existed_node, int variable_id, vector<int> node_state);
    pair<bool, Node*> exist_node_with_same_state(vector<int> node_state);
    void create_arc_for_the_new_node(Node* existed_node, Node* node_created, int variable_value, int variable_id);
    void print_graph(bool should_visualize);
    void print();
    
    virtual void specific_layer_function() const=0;
    virtual void specific_final_function() const=0;
};


#endif //DD_OPTIMIZATION_PROGRAM_ABSTRACTDDBUILDER_H