#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include "SetCoveringProblem.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

using namespace std;

int main() {
    vector<vector<int>> matrix_of_wheight = {{1, 1, 1, 0, 0, 0},
                                             {1, 0, 0, 1, 1, 0},
                                             {0, 1, 0, 1, 0, 1}};
    vector<int> right_side_of_restrictions = {1, 1, 1};


    vector<int> initial_state = {1, 2, 3};
    vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}),
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}),
            make_pair("x_4", vector<int>{0, 1}),
            make_pair("x_5", vector<int>{0, 1}),
            make_pair("x_6", vector<int>{0, 1})
    };

    SetCoveringProblem set_covering_instance(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
    cout << set_covering_instance.get_state_as_string(initial_state)<<endl;
    DD<vector<int>> dd_instance(set_covering_instance, false);


    Graph pre_graph = dd_instance.get_desition_diagram();
    cout << "Nodes: " << pre_graph.nodes.size() << endl;
    cout << "Creation Time: " << dd_instance.get_dd_builder_time() << endl;

    dd_instance.create_reduce_decision_diagram(false);
    cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << endl;

    dd_instance.create_restricted_decision_diagram(3, false);
    cout << "Restricted time: " << dd_instance.get_restricted_dd_builder_time() << endl;

    dd_instance.create_relaxed_decision_diagram(3, true);
    cout << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << endl;

    Graph post_graph = dd_instance.get_desition_diagram();
    cout << "Nodes: " << post_graph.nodes.size() << endl;

    dd_instance.export_graph_file("set_covering_file");


    vector<int> objective_weights = {2, 1, 4, 3, 4, 3};

    ObjectiveFunction objective_function_instance = ObjectiveFunction<vector<int>>(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<vector<int>>(objective_weights, "min");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << objective_function_instance.get_the_solution().value<< endl;
    cout << objective_function_instance.get_the_solution().path<< endl;
    cout << "LinearDp time: " << objective_function_instance.get_time() << endl;

    return 0;
}
