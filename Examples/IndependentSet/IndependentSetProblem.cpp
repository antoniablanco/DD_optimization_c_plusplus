#include "IndependentSetProblem.h"
IndependentSetProblem::IndependentSetProblem(vector<int> &initial_state, vector<pair<string, vector<int>>>& variables,
                                             map<string, vector<int>> dict_node_neighbors)
        : AbstractProblem(initial_state, variables),
          dict_node_neighbors(dict_node_neighbors)
{
    check_atributes(variables);
}

void IndependentSetProblem::check_atributes(vector<pair<string, vector<int>>>& variables) {
    check_same_variables(variables);
    check_consistent_dictionary_of_neighbors();
}

void IndependentSetProblem::check_same_variables(vector<pair<string, vector<int>>>& variables) {
    assert(keysOfVector(variables) == keysToVector(dict_node_neighbors) && "Variables must be the same between dictionaries");
}

unordered_set<std::string> IndependentSetProblem::keysToVector(const map<string, vector<int>>& dict_node_neighbors) {
    std::unordered_set<std::string> result;
    for (const auto& entry : dict_node_neighbors) {
        result.insert(entry.first);
    }
    return result;
}

unordered_set<std::string> IndependentSetProblem::keysOfVector(vector<pair<string, vector<int>>>& variables) {
    std::unordered_set<std::string> result;
    for (const auto& entry : variables) {
        result.insert(entry.first);
    }
    return result;
}

void IndependentSetProblem::check_consistent_dictionary_of_neighbors() {
    for (const auto& entry : dict_node_neighbors) {
        for (int value : entry.second) {
            assert(isNeighborConsistent(entry.first, value) && "Dictionary of neighbors must be consistent");
        }
    }
}

bool IndependentSetProblem::isNeighborConsistent(const string& key, int value) {
    auto neighborEntry = dict_node_neighbors.find("x_" + to_string(value));
    return (neighborEntry != dict_node_neighbors.end()) &&
           (find(neighborEntry->second.begin(), neighborEntry->second.end(), stoi(key.substr(2))) != neighborEntry->second.end());
}

bool IndependentSetProblem::equals(const vector<int>& state_one, const vector<int>& state_two) const {
    return state_one == state_two;
}

pair<vector<int>, bool> IndependentSetProblem::transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const {
    bool isFeasible = true;
    vector<int> new_state = previous_state;

    if (variable_value == 0 && find(previous_state.begin(), previous_state.end(), stoi(variable_id.substr(2))) != previous_state.end()) {
        new_state.erase(remove(new_state.begin(), new_state.end(), stoi(variable_id.substr(2))), new_state.end());
    } else if (variable_value == 1 && find(previous_state.begin(), previous_state.end(), stoi(variable_id.substr(2))) != previous_state.end()) {
        new_state.erase(remove(new_state.begin(), new_state.end(), stoi(variable_id.substr(2))), new_state.end());

        for (int neighbor : dict_node_neighbors.at(variable_id)) {
            if (find(new_state.begin(), new_state.end(), neighbor) != new_state.end()) {
                new_state.erase(remove(new_state.begin(), new_state.end(), neighbor), new_state.end());
            }
        }
    }

    isFeasible = (variable_value == 1 && find(previous_state.begin(), previous_state.end(), stoi(variable_id.substr(2))) != previous_state.end()) || (variable_value == 0);
    return make_pair(new_state, isFeasible);
}

int IndependentSetProblem::get_priority_for_discard_node(const vector<int>& state) const {
    return -state.size();
}

int IndependentSetProblem::get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const {
    return -node_id;
}

const vector<int> IndependentSetProblem::merge_operator(const vector<int>& state_one, const vector<int>& state_two) const {
    vector<int> result;
    set_union(state_one.begin(), state_one.end(), state_two.begin(), state_two.end(), back_inserter(result));
    return result;
}

const string IndependentSetProblem::get_state_as_string(const vector<int>& state) const {
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
