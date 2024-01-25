#ifndef DD_OPTIMIZATION_PROGRAM_DDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_DDBUILDER_H

#include "AbstractDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class DDBuilder: public AbstractDDBuilder {
    public:
        DDBuilder(AbstractProblem& problem);
    private:
        void specific_layer_function() override;
        void specific_final_function() override;
};

#endif //DD_OPTIMIZATION_PROGRAM_DDBUILDER_H