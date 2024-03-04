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

    // Configurar el generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    int variables_length = 1000;

    vector<vector<int>> matrix_of_wheight(1, std::vector<int>(variables_length));
    for (size_t j = 0; j < matrix_of_wheight[0].size(); ++j) {
        matrix_of_wheight[0][j] = dis(gen);
    }

    vector<int> right_side_of_restrictions = {100};

    vector<int> initial_state = {0, 0};

    std::vector<std::pair<std::string, std::vector<int>>> variables;
    for (int i = 1; i <= variables_length; ++i) {
        std::string variable_name = "x_" + std::to_string(i);
        variables.emplace_back(make_pair(variable_name, vector<int>{0,1}));
    }

    vector<int> objective_weights = {};
    for (size_t j = 0; j < variables_length; ++j) {
        objective_weights.push_back(dis(gen));
    }

    // Crear el archivo de escritura de las estadísticas
    string file_name = "knapsack_statistics";
    string source_directory = fs::current_path().parent_path().string();
    string full_file_path = source_directory + "/" + file_name + ".txt";
    auto* file = new ofstream(full_file_path, std::ios::app);

    // Obtener información horaria de la ejecución
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);
    char buffer[80];
    std::strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", local_time);
    (*file) << "[" << buffer << "]" << "  ";

    // Crear los diagramas de decisión
    KnapsackProblem knapsack_instance(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
    DD<vector<int>> dd_instance(knapsack_instance, false);

    Graph creation_graph = dd_instance.get_desition_diagram();
    (*file) << "Creation Time: " << dd_instance.get_dd_builder_time() << ", Nodes: " << creation_graph.nodes.size() << ";    ";

    dd_instance.create_reduce_decision_diagram(false);
    Graph reduce_graph = dd_instance.get_desition_diagram();
    (*file) << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << ", Nodes: " << reduce_graph.nodes.size() << ";    ";

    int width = 70;
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

    file->close();
    return 0;
}
