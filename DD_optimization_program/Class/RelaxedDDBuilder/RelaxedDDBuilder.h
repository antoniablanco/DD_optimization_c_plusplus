#ifndef DD_OPTIMIZATION_PROGRAM_RELAXEDDDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_RELAXEDDDBUILDER_H

#include "AbstractDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class RelaxedDDBuilder: public AbstractDDBuilder {
    public:
        RelaxedDDBuilder(AbstractProblem& problem, int max_width);

    private:
        int max_width;
        void specific_layer_function() override;
        void specific_final_function() override;
        
        void merge_nodes_when_width_is_greater_than_w();
        bool width_is_greater_than_w();
        void merge_nodes(Node* node_to_remove, Node* node_to_keep);
        void merge_with_an_existing_node(Node* node_one, Node* node_two, Node* exist_node);
        void merge_when_doesnt_exist_node(Node* node_to_remove, Node* node_to_keep, vector<int> new_state);
        void redirect_in_arcs(Node* node_to_remove, Node* node_to_keep);
        void change_new_state(Node* node, vector<int> new_state);
        void delete_node(Node* node_to_remove);
        void adjust_node_number();

};

#endif //DD_OPTIMIZATION_PROGRAM_RELAXEDDDBUILDER_H