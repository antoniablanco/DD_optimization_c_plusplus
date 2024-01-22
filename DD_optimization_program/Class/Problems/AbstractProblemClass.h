//
// Created by antonia blanco on 21-01-24.
//

#ifndef DD_OPTIMIZATION_PROGRAM_ABSTRACTPROBLEMCLASS_H
#define DD_OPTIMIZATION_PROGRAM_ABSTRACTPROBLEMCLASS_H

#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

class AbstractProblem {
public:
    AbstractProblem(vector<int>& initial_state, const vector<pair<string, vector<int>>>& variables);

    virtual bool equals(const vector<int>& state_one, const vector<int>& state_two) const = 0;
    virtual pair<vector<int>, bool> transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const = 0;
    virtual int get_priority_for_discard_node(const vector<int>& state) const = 0;
    virtual int get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const = 0;
    virtual const vector<int> merge_operator(const vector<int>& state_one, const vector<int>& state_two) const = 0;

    vector<int>& initial_state;
    vector<string> ordered_variables;
    map<string, vector<int>> variables_domain;
    
    virtual ~AbstractProblem() = default;


private:
    void get_variables(const vector<pair<string, vector<int>>>& variables);
};

#endif //DD_OPTIMIZATION_PROGRAM_ABSTRACTPROBLEMCLASS_H
