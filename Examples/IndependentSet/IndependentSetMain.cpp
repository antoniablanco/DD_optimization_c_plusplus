#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include "IndependentSetProblem.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

using namespace std;

int main()
{   map<string, vector<int>> dict_node_neighbors;
    dict_node_neighbors["x_1"] = {2, 3};
    dict_node_neighbors["x_2"] = {1, 3, 4};
    dict_node_neighbors["x_3"] = {1, 2, 4};
    dict_node_neighbors["x_4"] = {2, 3, 5};
    dict_node_neighbors["x_5"] = {4};

    vector<int> initial_state = {1, 2, 3, 4, 5};
    vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}),
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}),
            make_pair("x_4", vector<int>{0, 1}),
            make_pair("x_5", vector<int>{0, 1})
    };

    IndependentSetProblem independent_set_instance(initial_state, variables, dict_node_neighbors);
    DD<vector<int>> dd_instance(independent_set_instance, false);

    cout << "Creation Time: " << dd_instance.getDdBuilderTime() << endl;

    dd_instance.createReduceDecisionDiagram(false);
    cout << "Reduce time: " << dd_instance.getReduceDdBuilderTime() << endl;

    dd_instance.createRestrictedDecisionDiagram(2, false);
    cout << "Restricted time: " << dd_instance.getRestrictedDdBuilderTime() << endl;

    dd_instance.createRelaxedDecisionDiagram(2, false);
    cout << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << endl;

    Graph post_graph = dd_instance.get_desition_diagram();

    dd_instance.export_graph_file("independent_set_file");


    // Resolución del diagrama
    vector<int> objective_weights = {3, 4, 2, 2, 7, 1};

    ObjectiveFunction objective_function_instance = ObjectiveFunction<vector<int>>(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<vector<int>>(objective_weights, "max");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << objective_function_instance.get_the_solution().value<< endl;
    cout << objective_function_instance.get_the_solution().path<< endl;
    cout << "LinearDp time: " << objective_function_instance.get_time() << endl;

    return 0;
}