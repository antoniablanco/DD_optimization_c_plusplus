#include "KnapsackProblem.h"
#include "utils.h"
#include "DD.h"
#include "LinearObjectiveDP.h"
#include "ObjectiveFunction.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <list>
#include <random>

using namespace std;



int main() {
    
    
    // Valores construcción knapsack
    vector<vector<int>> matrix_of_wheight = {{3, 3, 4, 6}};
    vector<int> right_side_of_restrictions = {6};

    
    vector<int> initial_state = {0, 0};
    vector<pair<string, vector<int>>> variables = {
        make_pair("x_1", vector<int>{0, 1}), 
        make_pair("x_2", vector<int>{0, 1}),
        make_pair("x_3", vector<int>{0, 1}), 
        make_pair("x_4", vector<int>{0, 1})
    };
    

    // 67.789444/ 66.876237 segundos en c++
    // 51.712515115737915/ 55.72262930870056 en python
    // Configurar el generador de números aleatorios 
    
    /*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    // Crear la matriz
    vector<vector<int>> matrix_of_wheight(1, std::vector<int>(1000));

    // Iterar sobre la matriz y asignar números aleatorios
    for (size_t j = 0; j < matrix_of_wheight[0].size(); ++j) {
        matrix_of_wheight[0][j] = dis(gen);
    }

    vector<int> right_side_of_restrictions = {100};

    // Valores construcción abstract problem
    vector<int> initial_state = {0, 0};
    
    // Crear el vector de variables
    std::vector<std::pair<std::string, std::vector<int>>> variables;

    // Agregar mil variables al vector
    for (int i = 1; i <= 1000; ++i) {
        std::string variable_name = "x_" + std::to_string(i);
        variables.emplace_back(make_pair(variable_name, vector<int>{0,1}));
    }
    
    vector<int> objective_weights(vector<int>(1000)); // Time: 3.89174 seconds
    for (size_t j = 0; j < objective_weights.size(); ++j) {
        objective_weights[j] = dis(gen);
    }
    */

    KnapsackProblem knapsack_instance(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
    DD dd_instance(knapsack_instance, false);

    Graph graph = dd_instance.get_desition_diagram();
    cout << "Nodes: " << graph.nodes.size() << endl;

    //dd_instance.create_reduce_desition_diagram(false);
    //dd_instance.create_restricted_desition_diagram(3 ,false);
    //dd_instance.create_relaxed_desition_diagram(3 ,true);

    //cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << endl; //Funciona bien

    //dd_instance.export_graph_file("knapsack_file");

    
    // Resolución del diagrama
    vector<int> objective_weights = {-5, 1, 18, 17};

    ObjectiveFunction objective_function_instance = ObjectiveFunction(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP(objective_weights, "max");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << objective_function_instance.get_the_solution().value<< endl;
    cout << objective_function_instance.get_the_solution().path<< endl;
    
   
    return 0;
}
