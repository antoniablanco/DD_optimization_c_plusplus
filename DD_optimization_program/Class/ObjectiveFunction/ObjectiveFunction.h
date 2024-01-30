#ifndef DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H
#define DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

#include "Graph.h"
#include "AbstractObjective.h"
#include "ObjectiveStructure.h"
#include "DD.h"

using namespace std;

class ObjectiveFunction {
    public:
    ObjectiveFunction(DD dd);
    ObjectiveStruct answer;

    void set_objective_function(AbstractObjective& objective_function);
    ObjectiveStruct solve_dd();
    string get_time();
    ObjectiveStruct get_the_solution();

    private:
    Graph graph;
    chrono::duration<double> time;
    AbstractObjective* objective_function;

    void check_if_objective_is_set();
};

#endif //DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H