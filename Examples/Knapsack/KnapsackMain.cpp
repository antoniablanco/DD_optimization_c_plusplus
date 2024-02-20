#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "KnapsackProblem.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

using namespace std;


int main() {

    // Tiempos:
    // Creación dd: 67.789444 en c++ y en python fue: 51.712515115737915
    // Reduce dd: 40.130613
    // Restricted dd: 0.19868
    // Relaxed dd: 65.879433
    // LinearDp: 3.89174 seconds

    // Configurar el generador de números aleatorios


    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    vector<vector<int>> matrix_of_wheight(1, std::vector<int>(1000));
    for (size_t j = 0; j < matrix_of_wheight[0].size(); ++j) {
        matrix_of_wheight[0][j] = dis(gen);
    }

    vector<int> right_side_of_restrictions = {100};

    vector<int> initial_state = {0, 0};

    std::vector<std::pair<std::string, std::vector<int>>> variables;
    for (int i = 1; i <= 1000; ++i) {
        std::string variable_name = "x_" + std::to_string(i);
        variables.emplace_back(make_pair(variable_name, vector<int>{0,1}));
    }

    vector<int> objective_weights(vector<int>(1000));
    for (size_t j = 0; j < objective_weights.size(); ++j) {
        objective_weights[j] = dis(gen);
    }


    /*
    vector<vector<int>> matrix_of_wheight = {{3, 3, 4, 6}};
    vector<int> right_side_of_restrictions = {6};

    vector<int> initial_state = {0, 0};
    vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}),
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}),
            make_pair("x_4", vector<int>{0, 1})
    };

    vector<int> objective_weights = {-5, 1, 18, 17};
    */
    KnapsackProblem knapsack_instance(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
    cout << knapsack_instance.get_state_as_string(initial_state)<<endl;

    DD<vector<int>> dd_instance(knapsack_instance, false);

    Graph pre_graph = dd_instance.get_desition_diagram();
    cout << "Nodes: " << pre_graph.nodes.size() << endl;
    cout << "Creation Time: " << dd_instance.get_dd_builder_time() << endl;

    dd_instance.create_reduce_decision_diagram(false);
    cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << endl;

    dd_instance.create_restricted_decision_diagram(70, false);
    cout << "Restricted time: " << dd_instance.get_restricted_dd_builder_time() << endl;

    dd_instance.create_relaxed_decision_diagram(70, false);
    cout << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << endl;

    dd_instance.export_graph_file("knapsack_file");

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
