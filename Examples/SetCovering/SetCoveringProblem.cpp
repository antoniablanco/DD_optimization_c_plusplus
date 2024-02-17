//
// Created by antonia blanco on 13-02-24.
//

#include "SetCoveringProblem.h"

SetCoveringProblem::SetCoveringProblem(vector<int> &initial_state, const vector<pair<string, vector<int>>>& variables,
                                       vector<vector<int>> matrix_of_wheight, vector<int> right_side_of_restrictions)
        : AbstractProblem(initial_state, variables),
          matrix_of_wheight(matrix_of_wheight),
          right_side_of_restrictions(right_side_of_restrictions)
{
    check_atributes(variables, initial_state);
}


void SetCoveringProblem::check_atributes(const vector<pair<string, vector<int>>>& variables, vector<int>& initial_state) {
    check_same_len_matrix_and_right_side(initial_state);
    check_same_len_rows_matrix_and_variables(variables);
}

void SetCoveringProblem::check_same_len_matrix_and_right_side(vector<int>& initial_state) {
    assert(matrix_of_wheight.size() == right_side_of_restrictions.size() && "matrix_of_wheight and right_side_of_restrictions must have the same length");

    assert((initial_state.size() == right_side_of_restrictions.size() || initial_state.size() == 2 * right_side_of_restrictions.size()) &&
           "initial_state and right_side_of_restrictions must have the same length");
}

void SetCoveringProblem::check_same_len_rows_matrix_and_variables(const vector<pair<string, vector<int>>>& variables) {
    for (auto &row: matrix_of_wheight) {
        assert(variables.size() == row.size() &&
               "matrix_of_wheight and variables must have the same length");
    }
}

bool SetCoveringProblem::equals(const vector<int>& state_one, const vector<int>& state_two) const {
    return unordered_set<int>(state_one.begin(), state_one.end()) == unordered_set<int>(state_two.begin(), state_two.end());
}

pair<vector<int>, bool> SetCoveringProblem::transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const {
    bool isFeasible = true;
    vector<int> new_state;

    if (variable_value == 0) {
        new_state = previous_state;
        for (int row : previous_state) {
            int maximo = matrix_of_wheight[row - 1].size() - distance(matrix_of_wheight[row - 1].rbegin(), find(matrix_of_wheight[row - 1].rbegin(), matrix_of_wheight[row - 1].rend(), 1));
            if (stoi(variable_id.substr(2)) >= maximo) {
                isFeasible = false;
            }
        }
    } else {
        for (int row : previous_state) {
            if (matrix_of_wheight[row - 1][stoi(variable_id.substr(2)) - 1] != 1) {
                new_state.push_back(row);
            }
        }
    }

    return make_pair(new_state, isFeasible);
}

int SetCoveringProblem::get_priority_for_discard_node(const vector<int>& state) const {
    return state.size();
}

int SetCoveringProblem::get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const {
    return state.size();
}

const vector<int> SetCoveringProblem::merge_operator(const vector<int>& state_one, const vector<int>& state_two) const {
    vector<int> new_state;
    set_intersection(state_one.begin(), state_one.end(), state_two.begin(), state_two.end(), back_inserter(new_state));
    return new_state;
}

const string SetCoveringProblem::get_state_as_string(const vector<int>& state) const {
    string result = "[";
    for (int i = 0; i < state.size(); ++i) {
        result += std::to_string(state[i]);
        if (i != state.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
