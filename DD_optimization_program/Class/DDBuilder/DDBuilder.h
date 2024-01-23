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
        void specific_layer_function() const override;
        void specific_final_function() const override;
};