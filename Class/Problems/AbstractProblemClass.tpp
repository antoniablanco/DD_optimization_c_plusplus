#include "AbstractProblemClass.h"

template <typename T>
AbstractProblem<T>::AbstractProblem(T& initial_state, const vector<pair<string, vector<int>>> &variables):
        initial_state(initial_state)
{
    get_variables(variables);
}

template <typename T>
void AbstractProblem<T>::get_variables(const vector<pair<std::string, vector<int>>> &variables) {
    for (auto &variable: variables) {
        this->ordered_variables.push_back(variable.first);
        this->variables_domain[variable.first] = variable.second;
    }
}

template <typename T>
bool AbstractProblem<T>::equals(const T &state_one, const T &state_two) const {
    throw std::logic_error("The method equals has not been implemented yet");
}

template <typename T>
pair<T, bool> AbstractProblem<T>::transition_function(const T &previous_state, const string &variable_id, int variable_value) const {
    throw std::logic_error("The method transition_function has not been implemented yet");
}

template <typename T>
int AbstractProblem<T>::get_priority_for_discard_node(const T &state) const {
    throw std::logic_error("The method get_priority_for_discard_node has not been implemented yet");
}

template <typename T>
int AbstractProblem<T>::get_priority_for_merge_nodes(const int node_id, const T &state) const {
    throw std::logic_error("The method get_priority_for_merge_nodes has not been implemented yet");
}

template <typename T>
T AbstractProblem<T>::merge_operator(const T &state_one, const T &state_two) const {
    throw std::logic_error("The method merge_operator has not been implemented yet");
}

template <typename T>
string AbstractProblem<T>::get_state_as_string(const T &state) const {
    throw std::logic_error("The method get_state_as_string has not been implemented yet");
}