//
// Created by antonia blanco on 21-01-24.
//

#include "AbstractProblemClass.h" 

AbstractProblem::AbstractProblem(vector<int>& initial_state, const vector<pair<string, vector<int>>> &variables):
    initial_state(initial_state)
    {
        get_variables(variables);
    }

void  AbstractProblem::get_variables(const vector<pair<std::string, vector<int>>> &variables) {
    vector<string> ordered_variables;
    for (auto &variable: variables) {
        this->ordered_variables.push_back(variable.first);
        this->variables_domain[variable.first] = variable.second;
    }
}

bool AbstractProblem::equals(const vector<int> &state_one, const vector<int> &state_two) const {
    throw std::logic_error("The method equals has not been implemented yet");
}

pair<vector<int>, bool> AbstractProblem::transition_function(const vector<int> &previous_state, const string &variable_id, int variable_value) const {
    throw std::logic_error("The method transition_function has not been implemented yet");
}

int AbstractProblem::get_priority_for_discard_node(const vector<int> &state) const {
    throw std::logic_error("The method get_priority_for_discard_node has not been implemented yet");
}

int AbstractProblem::get_priority_for_merge_nodes(const int node_id, const vector<int> &state) const {
    throw std::logic_error("The method get_priority_for_merge_nodes has not been implemented yet");
}

const vector<int> AbstractProblem::merge_operator(const vector<int> &state_one, const vector<int> &state_two) const {
    throw std::logic_error("The method merge_operator has not been implemented yet");
}
