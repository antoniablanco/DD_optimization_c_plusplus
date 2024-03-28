#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
#include <ctime>

#include "KnapsackProblemState.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

using namespace std;


int main() {

    
    // Ejemplo utilizado en los tests
    vector<vector<int>> matrix_of_weight = {{3, 3, 4, 6}};
    vector<int> right_side_of_restrictions = {6};

    State initial_state = State({0, 0});
    vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}),
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}),
            make_pair("x_4", vector<int>{0, 1})
    };

    vector<int> objective_weights = {-5, 1, 18, 17};
    int width = 3;
    

   /*
    // Se realiza la lectura de los datos necesarios
    string source_directory = fs::current_path().parent_path().string();
    auto& filename = "knapsack_instance_v300_d100_seed1.txt";
    string file_path = source_directory + "/DataInstances/txt/" + filename;

    ifstream input(file_path);
    if( !input.is_open() ) {
        cerr << "Error: could not open file " << filename << endl;
        exit(1);
    }

    vector<int> initial_state = {0, 0};
    int variable_length;
    vector<int> right_side_of_restrictions;
    int width;
    vector<vector<int>> matrix_of_weight;
    vector<int> objective_weights;

    input >> variable_length;

    vector<int> right_side_of_restrictions_row;
    int value;
    input >> value;
    right_side_of_restrictions_row.push_back(value);
    right_side_of_restrictions.push_back(value);
    

    input >> width;
    vector<int> row;
    for (int j = 0; j < variable_length; j++) {
        int value;
        input >> value;
        row.push_back(value);
    }
    matrix_of_weight.push_back(row);

    for (int i = 0; i < variable_length; i++) {
        int value;
        input >> value;
        objective_weights.push_back(value);
    }

    std::vector<std::pair<std::string, std::vector<int>>> variables;
    for (int i = 1; i <= variable_length; ++i) {
        std::string variable_name = "x_" + std::to_string(i);
        variables.emplace_back(make_pair(variable_name, vector<int>{0,1}));
    }
    */

    // Crear los diagramas de decisión
    KnapsackProblemState knapsack_instance(initial_state, variables, matrix_of_weight, right_side_of_restrictions);
    DD<State> dd_instance(knapsack_instance, false);

    Graph creation_graph = dd_instance.get_desition_diagram();
    cout << "Creation Time: " << dd_instance.get_dd_builder_time() << ", Nodes: " << creation_graph.nodes.size() << ";    ";

    
    dd_instance.create_reduce_decision_diagram(false);
    Graph reduce_graph = dd_instance.get_desition_diagram();
    cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << ", Nodes: " << reduce_graph.nodes.size() << ";    ";

    cout << "(Width: " << width << ") ";
    dd_instance.create_restricted_decision_diagram(width, true);
    Graph restricted_graph = dd_instance.get_desition_diagram();
    cout << "Restricted time: " << dd_instance.get_restricted_dd_builder_time() << ", Nodes: " << restricted_graph.nodes.size() << ";    ";
    
    
    dd_instance.create_relaxed_decision_diagram(width, false);
    Graph relaxed_graph = dd_instance.get_desition_diagram();
    cout << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << ", Nodes: " << relaxed_graph.nodes.size() << ";    ";

    dd_instance.export_graph_file("knapsack_file");

    // Resolución del diagrama
    ObjectiveFunction objective_function_instance = ObjectiveFunction<State>(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<State>(objective_weights, "max");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << "LinearDp time: " << objective_function_instance.get_time() << "\n";
    cout << objective_function_instance.get_the_solution().value<< endl;
    
    
    return 0;
}