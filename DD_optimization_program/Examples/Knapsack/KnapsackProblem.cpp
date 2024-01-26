//
// Created by antonia blanco on 21-01-24.
//

#include "KnapsackProblem.h"

using namespace std;

KnapsackProblem::KnapsackProblem(vector<int> &initial_state, const vector<pair<string, vector<int>>>& variables,
vector<vector<int>> matrix_of_wheight, vector<int> right_side_of_restrictions)
    : AbstractProblem(initial_state, variables),
    matrix_of_wheight(matrix_of_wheight),
    right_side_of_restrictions(right_side_of_restrictions)
    {   
        check_atributes(variables, initial_state);
    }


void KnapsackProblem::check_atributes(const vector<pair<string, vector<int>>>& variables, vector<int>& initial_state) {
    check_same_len_matrix_and_right_side(initial_state);
    check_same_len_rows_matrix_and_variables(variables);
    }

void KnapsackProblem::check_same_len_matrix_and_right_side(vector<int>& initial_state) {
        assert(matrix_of_wheight.size() == right_side_of_restrictions.size() && "matrix_of_wheight and right_side_of_restrictions must have the same length");
        
        assert((initial_state.size() == right_side_of_restrictions.size() || initial_state.size() == 2 * right_side_of_restrictions.size()) &&
               "initial_state and right_side_of_restrictions must have the same length");
    }

void KnapsackProblem::check_same_len_rows_matrix_and_variables(const vector<pair<string, vector<int>>>& variables) {
        for (auto &row: matrix_of_wheight) {
            assert(variables.size() == row.size() &&
                   "matrix_of_wheight and variables must have the same length");
        }
    }

bool KnapsackProblem::equals(const vector<int>& state_one, const vector<int>& state_two) const {
    return set<int>(state_one.begin(), state_one.end()) == set<int>(state_two.begin(), state_two.end());
    }

pair<vector<int>, bool> KnapsackProblem::transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const {
    
    bool isFeasible = true;
    vector<int> state = {};

    for (size_t row = 0; row < matrix_of_wheight.size(); ++row) {
        vector<int> lista_suma_variables = matrix_of_wheight[row];
        int new_state = previous_state[row] + lista_suma_variables[stoi(variable_id.substr(2)) - 1] * variable_value;
        state.push_back(new_state);
        state.push_back(new_state);

        bool isFeasible_this_row = state[row] <= right_side_of_restrictions[row];
        isFeasible = isFeasible && isFeasible_this_row;
        }

    return make_pair(state, isFeasible);
}

int KnapsackProblem::get_priority_for_discard_node(const vector<int>& state) const {
    int total = 0;
    for (size_t i=0; i < state.size(); ++i ) {
        total += state[i];
        }
    return -total;
    }

int KnapsackProblem::get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const {
    if (state[0] != state[1]) {
        return -500;
        }
    return -int(node_id);
}

const vector<int> KnapsackProblem::merge_operator(const vector<int>& state_one, const vector<int>& state_two) const {
    vector<int> state = {};
    
    state.push_back(state_one[0]);
    state.push_back(state_two.back());

    sort(state.begin(), state.end());

    return state;
    }

