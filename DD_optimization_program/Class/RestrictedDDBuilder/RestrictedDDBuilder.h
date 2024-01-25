#ifndef DD_OPTIMIZATION_PROGRAM_RESTRICTEDDDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_RESTRICTEDDDBUILDER_H

#include "AbstractDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class RestrictedDDBuilder: public AbstractDDBuilder {
    public:
        RestrictedDDBuilder(AbstractProblem& problem, int max_width);

    private:
        int max_width;
        void specific_layer_function() override;
        void specific_final_function() override;
        
        void eliminate_nodes_when_width_is_greater_than_w();
        bool width_is_greater_than_w();
        void eliminate_nodes(vector<Node*> nodes_to_eliminate);
        void eliminate_nodes_without_out_arcs();
        void adjust_node_number();

};

#endif //DD_OPTIMIZATION_PROGRAM_RESTRICTEDDDBUILDER_H