#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
#include <ctime>

#include "KnapsackProblem.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

using namespace std;


int main() {

    /*
    // Ejemplo utilizado en los tests
    vector<vector<int>> matrix_of_weight = {{3, 3, 4, 6}};
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

    // Se realiza la lectura de los datos necesarios
    string source_directory = fs::current_path().parent_path().string();
    auto& filename = "knapsack_instance_v1000_d10_seed1.txt";
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


    // Crear el archivo de escritura de las estadísticas
    string file_name = "knapsack_statistics";
    string full_file_path = source_directory + "/Examples/Knapsack/" + file_name + ".txt";
    auto* file = new ofstream(full_file_path, std::ios::app);

    // Obtener información horaria de la ejecución
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);
    char buffer[80];
    std::strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", local_time);
    (*file) << "[" << buffer << "]" << "  ";

    // Información sobre el problema creado
    (*file) << "File_name: "<< filename << "  ";

    // Crear los diagramas de decisión
    KnapsackProblem knapsack_instance(initial_state, variables, matrix_of_weight, right_side_of_restrictions);
    DD<vector<int>> dd_instance(knapsack_instance, false);

    Graph creation_graph = dd_instance.get_desition_diagram();
    (*file) << "Creation Time: " << dd_instance.get_dd_builder_time() << ", Nodes: " << creation_graph.nodes.size() << ";    ";

    dd_instance.create_reduce_decision_diagram(false);
    Graph reduce_graph = dd_instance.get_desition_diagram();
    (*file) << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << ", Nodes: " << reduce_graph.nodes.size() << ";    ";

    (*file) << "(Width: " << width << ") ";
    dd_instance.create_restricted_decision_diagram(width, false);
    Graph restricted_graph = dd_instance.get_desition_diagram();
    (*file) << "Restricted time: " << dd_instance.get_restricted_dd_builder_time() << ", Nodes: " << restricted_graph.nodes.size() << ";    ";

    dd_instance.create_relaxed_decision_diagram(width, false);
    Graph relaxed_graph = dd_instance.get_desition_diagram();
    (*file) << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << ", Nodes: " << relaxed_graph.nodes.size() << ";    ";

    dd_instance.export_graph_file("knapsack_file");

    // Resolución del diagrama
    ObjectiveFunction objective_function_instance = ObjectiveFunction<vector<int>>(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<vector<int>>(objective_weights, "max");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    (*file) << "LinearDp time: " << objective_function_instance.get_time() << "\n";
    cout << objective_function_instance.get_the_solution().value<< endl;

    file->close();
    
    return 0;
}
