//
// Created by antonia blanco on 21-01-24.
//

#include "AbstractProblemClass.h"

AbstractProblem::AbstractProblem(const vector<int>& initial_state, const vector<pair<string, vector<int>>> &variables):
    initial_state(initial_state),
    ordered_variables(get_variables(variables)) {}

vector<string>  AbstractProblem::get_variables(const vector<pair<std::string, vector<int>>> &variables) {
    vector<string> ordered_variables;
    for (auto &variable: variables) {
        ordered_variables.push_back(variable.first);
        this->variables_domain[variable.first] = variable.second;
    }
    return ordered_variables;
}
