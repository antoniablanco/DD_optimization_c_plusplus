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

using namespace std;



int main() {
    
    // Valores construcción knapsack
    vector<vector<int>> matrix_of_wheight = {{3, 3, 4, 6}};
    vector<int> right_side_of_restrictions = {6};

    // Valores construcción abstract problem
    vector<int> initial_state = {0, 0};
    vector<pair<string, vector<int>>> variables = {
        make_pair("x_1", vector<int>{0, 1}), 
        make_pair("x_2", vector<int>{0, 1}),
        make_pair("x_3", vector<int>{0, 1}), 
        make_pair("x_4", vector<int>{0, 1})
    };
    

    KnapsackProblem knapsack_instance(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
    DD dd_instance(knapsack_instance, false);

    Graph graph = dd_instance.get_desition_diagram();
    cout << "Nodes: " << graph.nodes.size() << endl;

    //dd_instance.create_reduce_desition_diagram(false);
    //dd_instance.create_restricted_desition_diagram(3 ,false);
    //dd_instance.create_relaxed_desition_diagram(3 ,true);

    cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << endl; //Funciona bien

    Graph graph2 = dd_instance.get_desition_diagram();
    cout << "Nodes: " << graph2.nodes.size() << endl;

    // Resolución del diagrama
    ObjectiveFunction objective_function_instance = ObjectiveFunction(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP({-5, 1, 18, 17}, "max");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << objective_function_instance.get_the_solution().value<< endl;
    
    return 0;
}
