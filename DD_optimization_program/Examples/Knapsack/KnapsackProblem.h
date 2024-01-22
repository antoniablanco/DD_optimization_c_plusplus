//
// Created by antonia blanco on 21-01-24.
//

#ifndef DD_OPTIMIZATION_PROGRAM_KNAPSACKPROBLEM_H
#define DD_OPTIMIZATION_PROGRAM_KNAPSACKPROBLEM_H

#include "MyExceptions.h"
#include "AbstractProblemClass.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>

class KnapsackProblem : public AbstractProblem {
public:
    KnapsackProblem(vector<int>& initial_state, const vector<pair<string, vector<int>>>& variables, 
    vector<vector<int>> matrix_of_wheight, vector<int> right_side_of_restrictions);

    bool equals(const vector<int>& state_one, const vector<int>& state_two) const override;
    pair<vector<int>, bool> transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const override;
    int get_priority_for_discard_node(const vector<int>& state) const override;
    int get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const override;
    const vector<int> merge_operator(const vector<int>& state_one, const vector<int>& state_two) const override;


private:
    vector<vector<int>> matrix_of_wheight;
    vector<int> right_side_of_restrictions;
    void check_atributes(const vector<pair<string, vector<int>>>& variables, vector<int>& initial_state);
    void check_same_len_matrix_and_right_side(vector<int>& initial_state);
    void check_same_len_rows_matrix_and_variables(const vector<pair<string, vector<int>>>& variables);

};

#endif //DD_OPTIMIZATION_PROGRAM_KNAPSACKPROBLEM_H
