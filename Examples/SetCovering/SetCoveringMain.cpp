#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "SetCoveringProblem.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    uniform_int_distribution<> dis_zero_one(0, 1);
    int variables_length = 100;
    int restrictions_length = 20;

    // Tiempos: para 100 y 20
    // Creación dd: 28.004 en c++  (Nodes: 362116)
    // Reduce dd:
    // Restricted dd:
    // Relaxed dd:
    // LinearDp:  seconds

    vector<vector<int>> matrix_of_wheight(restrictions_length, std::vector<int>(variables_length));
    for (size_t row = 0; row < matrix_of_wheight.size(); ++row) {
        for (size_t j = 0; j < matrix_of_wheight[row].size(); ++j) {
            matrix_of_wheight[row][j] = dis_zero_one(gen);
        }
    }

    vector<int> right_side_of_restrictions(restrictions_length, 1);

    vector<int> initial_state = {};
    initial_state.reserve(restrictions_length);
    for (int i = 0; i < restrictions_length; ++i) {
        initial_state.push_back(i+1);
    }

    std::vector<std::pair<std::string, std::vector<int>>> variables;
    for (int i = 1; i <= variables_length; ++i) {
        std::string variable_name = "x_" + std::to_string(i);
        variables.emplace_back(make_pair(variable_name, vector<int>{0,1}));
    }

    vector<int> objective_weights = {};
    for (size_t j = 0; j < variables_length; ++j) {
        objective_weights.push_back(dis(gen));
    }

    /*
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
    vector<int> objective_weights = {2, 1, 4, 3, 4, 3};
    */

    SetCoveringProblem set_covering_instance(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
    DD<vector<int>> dd_instance(set_covering_instance, false);


    Graph pre_graph = dd_instance.get_desition_diagram();
    cout << "Nodes: " << pre_graph.nodes.size() << endl;
    cout << "Creation Time: " << dd_instance.get_dd_builder_time() << endl;

    dd_instance.create_reduce_decision_diagram(false);
    cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << endl;

    dd_instance.create_restricted_decision_diagram(60, false);
    cout << "Restricted time: " << dd_instance.get_restricted_dd_builder_time() << endl;

    dd_instance.create_relaxed_decision_diagram(60, false);
    cout << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << endl;

    Graph post_graph = dd_instance.get_desition_diagram();
    cout << "Nodes: " << post_graph.nodes.size() << endl;

    dd_instance.export_graph_file("set_covering_file");


    ObjectiveFunction objective_function_instance = ObjectiveFunction<vector<int>>(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<vector<int>>(objective_weights, "min");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << objective_function_instance.get_the_solution().value<< endl;
    cout << objective_function_instance.get_the_solution().path<< endl;
    cout << "LinearDp time: " << objective_function_instance.get_time() << endl;

    return 0;
}
