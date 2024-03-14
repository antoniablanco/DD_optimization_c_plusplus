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
#include "Data.cpp"

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


    // Crear el archivo de escritura de las estadísticas
    string file_name = "knapsack_statistics";
    string source_directory = fs::current_path().parent_path().string();
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
    (*file) << "Variable length: 100;   right_side: 5029;   dis(1, 100); " << "  ";

    // Crear los diagramas de decisión
    KnapsackProblem knapsack_instance(initial_state, variables, matrix_of_weight, right_side_of_restrictions);
    DD<vector<int>> dd_instance(knapsack_instance, false);

    Graph creation_graph = dd_instance.get_desition_diagram();
    (*file) << "Creation Time: " << dd_instance.get_dd_builder_time() << ", Nodes: " << creation_graph.nodes.size() << ";    ";
    dd_instance.create_reduce_decision_diagram(false);
    Graph reduce_graph = dd_instance.get_desition_diagram();
    (*file) << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << ", Nodes: " << reduce_graph.nodes.size() << ";    ";

    int width = 200;
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
