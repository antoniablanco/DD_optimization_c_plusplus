#ifndef DD_OPTIMIZATION_PROGRAM_INDEPENDENTSETPROBLEM_H
#define DD_OPTIMIZATION_PROGRAM_INDEPENDENTSETPROBLEM_H

#include "MyExceptions.h"
#include "AbstractProblemClass.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>
#include <unordered_set>

using namespace std;

class IndependentSetProblem : public AbstractProblem {
public:
    IndependentSetProblem(vector<int>& initial_state, vector<pair<string, vector<int>>>& variables, 
    map<string, vector<int>> dict_node_neighbors);

    bool equals(const vector<int>& state_one, const vector<int>& state_two) const override;
    pair<vector<int>, bool> transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const override;
    int get_priority_for_discard_node(const vector<int>& state) const override;
    int get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const override;
    const vector<int> merge_operator(const vector<int>& state_one, const vector<int>& state_two) const override;

private:
    map<string, vector<int>> dict_node_neighbors;
    void check_atributes(vector<pair<string, vector<int>>>& variables);
    void check_same_variables(vector<pair<string, vector<int>>>& variables);
    void check_consistent_dictionary_of_neighbors();
    vector<string> keysToVector(const map<std::string, vector<int>>& variables);
    vector<string> keysOfVector(vector<pair<string, vector<int>>>& variables);
    bool isNeighborConsistent(const string& key, int value);

};

#endif //DD_OPTIMIZATION_PROGRAM_INDEPENDENTSETPROBLEM_H