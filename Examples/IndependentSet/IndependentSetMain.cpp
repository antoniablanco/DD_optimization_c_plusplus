#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "IndependentSetProblem.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    int variables_length = 50;
    uniform_int_distribution<> dis_thousand(1, variables_length);

    map<string, vector<int>> dict_node_neighbors;
    for (int i = 0; i < variables_length; ++i) {
        dict_node_neighbors["x_" + to_string(i+1)] = vector<int>();
    }

    for (int i = 1; i <= variables_length; ++i) {
        string i_variable_name = "x_" + to_string(i);
        for (int j = 1; j <= dis_thousand(gen); ++j) {
            int number = dis_thousand(gen);
            string number_variable_name = "x_" + to_string(number);
            if (i != number ) {
                if (find(dict_node_neighbors[i_variable_name].begin(), dict_node_neighbors[i_variable_name].end(), number) == dict_node_neighbors[i_variable_name].end()) {
                    dict_node_neighbors[i_variable_name].push_back(number);
                }
                if (find(dict_node_neighbors[number_variable_name].begin(), dict_node_neighbors[number_variable_name].end(), i) == dict_node_neighbors[number_variable_name].end()) {
                    dict_node_neighbors[number_variable_name].push_back(i);
                }
            }
        }
    }

    vector<int> initial_state = {};
    initial_state.reserve(variables_length);
    for (int i = 0; i < variables_length; ++i) {
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
    map<string, vector<int>> dict_node_neighbors;
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
    vector<int> objective_weights = {3, 4, 2, 2, 7, 1};
    */

    IndependentSetProblem independent_set_instance(initial_state, variables, dict_node_neighbors);
    DD<vector<int>> dd_instance(independent_set_instance, false);

    cout << "Creation Time: " << dd_instance.get_dd_builder_time() << endl;

    dd_instance.create_reduce_decision_diagram(false);
    cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << endl;

    dd_instance.create_restricted_decision_diagram(80, false);
    cout << "Restricted time: " << dd_instance.get_restricted_dd_builder_time() << endl;

    dd_instance.create_relaxed_decision_diagram(80, false);
    cout << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << endl;

    Graph post_graph = dd_instance.get_desition_diagram();

    dd_instance.export_graph_file("independent_set_file");


    // Resolución del diagrama
    ObjectiveFunction objective_function_instance = ObjectiveFunction<vector<int>>(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<vector<int>>(objective_weights, "max");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << objective_function_instance.get_the_solution().value<< endl;
    cout << objective_function_instance.get_the_solution().path<< endl;
    cout << "LinearDp time: " << objective_function_instance.get_time() << endl;

    return 0;
}
