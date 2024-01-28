#ifndef DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H
#define DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

#include "Graph.h"
#include "AbstractObjective.h"

using namespace std;

class ObjectiveFunction {
    public:
    ObjectiveFunction(Graph graph);
    tuple<int, string, vector<Arc*>> answer;

    void set_objective_function(AbstractObjective& objective_function);
    tuple<int, string, vector<Arc*>> solve_dd();
    string get_time();
    tuple<int, string, vector<Arc*>> get_the_solution();

    private:
    Graph graph;
    chrono::duration<double> time;

    void check_if_objective_is_set();
};

#endif //DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H