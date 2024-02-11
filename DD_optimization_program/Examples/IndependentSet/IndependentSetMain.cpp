#include "IndependentSetProblem.h"
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
    
    IndependentSetProblem independent_set_instance(initial_state, variables, dict_node_neighbors);
    DD dd_instance(independent_set_instance, false);

    cout << "Creation Time: " << dd_instance.get_dd_builder_time() << endl;
    
    dd_instance.create_reduce_desition_diagram(false);
    cout << "Reduce time: " << dd_instance.get_reduce_dd_builder_time() << endl; 

    dd_instance.create_restricted_desition_diagram(2 ,false);
    cout << "Restricted time: " << dd_instance.get_restricted_dd_builder_time() << endl; 
    
    dd_instance.create_relaxed_desition_diagram(2, false);
    cout << "Relaxed time: " << dd_instance.get_relaxed_dd_builder_time() << endl; 


    dd_instance.export_graph_file("independent_set_file");

    
    // Resolución del diagrama
    vector<int> objective_weights = {3, 4, 2, 2, 7, 1};

    ObjectiveFunction objective_function_instance = ObjectiveFunction(dd_instance);
    LinearObjectiveDP linear_objective_instance = LinearObjectiveDP(objective_weights, "max");
    objective_function_instance.set_objective_function(linear_objective_instance);
    objective_function_instance.solve_dd();
    cout << objective_function_instance.get_the_solution().value<< endl;
    cout << objective_function_instance.get_the_solution().path<< endl;
    cout << "LinearDp time: " << objective_function_instance.get_time() << endl;
   
    return 0;
}
