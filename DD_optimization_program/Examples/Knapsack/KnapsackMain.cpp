
#include "Node.h"
#include "Arc.h"
#include "Graph.h"
#include "KnapsackProblem.h"
#include "utils.h"
#include "DD.h"

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
    
    cout << "Variables domain: " << endl;
    for (const auto& pair : knapsack_instance.variables_domain ) {
        std::cout << pair.first << ": ";
        for (int value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    DD dd_instance(knapsack_instance);

    cout << "DD: " << to_string_int_vector(dd_instance.problem.initial_state) << endl;
    cout << "Variables: " << to_string_string_vector(dd_instance.problem.ordered_variables) << endl;

    cout << "Time: " << dd_instance.get_dd_builder_time() << endl; 

    return 0;
}
