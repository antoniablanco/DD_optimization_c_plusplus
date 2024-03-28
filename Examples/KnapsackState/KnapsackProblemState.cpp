#include "KnapsackProblemState.h"

State::State(vector<int> value) : value(value) {}

bool State::operator==(const State& other) const {
    return value == other.value;
}


KnapsackProblemState::KnapsackProblemState( State &initial_state, const vector<pair<string, vector<int>>>& variables,
                                 vector<vector<int>> matrix_of_wheight, vector<int> right_side_of_restrictions)
        : AbstractProblem(initial_state, variables),
          matrix_of_wheight(matrix_of_wheight),
          right_side_of_restrictions(right_side_of_restrictions)
{
    check_atributes(variables, initial_state);
}

void KnapsackProblemState::check_atributes(const vector<pair<string, vector<int>>>& variables, State& initial_state) {
    check_same_len_matrix_and_right_side(initial_state);
    check_same_len_rows_matrix_and_variables(variables);
}

void KnapsackProblemState::check_same_len_matrix_and_right_side(State& initial_state) {
    assert(matrix_of_wheight.size() == right_side_of_restrictions.size() && "matrix_of_wheight and right_side_of_restrictions must have the same length");

    assert((initial_state.value.size() == right_side_of_restrictions.size() || initial_state.value.size() == 2 * right_side_of_restrictions.size()) &&
           "initial_state and right_side_of_restrictions must have the same length");
}

void KnapsackProblemState::check_same_len_rows_matrix_and_variables(const vector<pair<string, vector<int>>>& variables) {
    for (auto &row: matrix_of_wheight) {
        assert(variables.size() == row.size() &&
               "matrix_of_wheight and variables must have the same length");
    }
}

bool KnapsackProblemState::equals(const State& state_one, const State& state_two) const {
    return state_one.value == state_two.value;
}

pair<State, bool> KnapsackProblemState::transition_function(const State& previous_state, const string& variable_id, int variable_value) const {

    bool isFeasible = true;
    vector<int> state = {};

    for (size_t row = 0; row < matrix_of_wheight.size(); ++row) {
        const vector<int>& row_of_matrix = matrix_of_wheight[row];
        int new_state = previous_state.value[row] + row_of_matrix[stoi(variable_id.substr(2)) - 1] * variable_value;
        state.push_back(new_state);
        state.push_back(new_state);

        bool isFeasible_this_row = state[row] <= right_side_of_restrictions[row];
        isFeasible = isFeasible && isFeasible_this_row;
    }

    State new_state = State(state);
    return make_pair(new_state, isFeasible);
}

int KnapsackProblemState::get_priority_for_discard_node(const State& state) const {
    int total = 0;
    for (int i : state.value) {
        total += i;
    }
    return -total;
}

int KnapsackProblemState::get_priority_for_merge_nodes(const int node_id, const State& state) const {
    if (state.value[0] != state.value[1]) {
        return -50000;
    }
    return -node_id;
}

State KnapsackProblemState::merge_operator(const State& state_one, const State& state_two) const {
    vector<int> state = {};

    state.push_back(state_one.value[0]);
    state.push_back(state_two.value.back());

    sort(state.begin(), state.end());

    State new_state = State(state);
    return new_state;
}

string KnapsackProblemState::get_state_as_string(const State& state) const {
    string result = "[";
    for (int i = 0; i < state.value.size(); ++i) {
        result += std::to_string(state.value[i]);
        if (i != state.value.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
