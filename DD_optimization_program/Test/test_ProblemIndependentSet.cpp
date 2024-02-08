#include <gtest/gtest.h>
#include "../../Examples/IndependentSet/IndependentSetProblem.h" 
#include "../../Class/DD.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>
#include <chrono>
#include <memory>
#include <thread>

using namespace std;

class ProblemIndependentSetTest : public ::testing::Test {
protected:
    void SetUp() override {
        map<string, vector<int>> dict_node_neighbors;
        dict_node_neighbors["x_1"] = {2, 3};
        dict_node_neighbors["x_2"] = {1, 3, 4};
        dict_node_neighbors["x_3"] = {1, 2, 4};
        dict_node_neighbors["x_4"] = {2, 3, 5};
        dict_node_neighbors["x_5"] = {4};
        
        vector<int> initial_state = {1, 2, 3, 4, 5};
        vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}), 
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}), 
            make_pair("x_4", vector<int>{0, 1}),
            make_pair("x_5", vector<int>{0, 1})
        };
        
        independent_set_instance = new IndependentSetProblem(initial_state, variables, dict_node_neighbors);
        dd_instance = new DD(*independent_set_instance, false);
    }

    void TearDown() override {
        delete independent_set_instance;
        delete dd_instance;
    }
    IndependentSetProblem* independent_set_instance;
    DD* dd_instance;
};

/*
TEST_F(ProblemIndependentSetTest, TestOrderedVariables) {
    vector<string> ordered_variables_test = {"x_1", "x_2", "x_3", "x_4", "x_5"};
    ASSERT_EQ(independent_set_instance->ordered_variables, ordered_variables_test);
}

TEST_F(ProblemIndependentSetTest, TestVariablesDomain) {
    map<string, vector<int>> variables_domain_test = {
        {"x_1", {0, 1}},
        {"x_2", {0, 1}},
        {"x_3", {0, 1}},
        {"x_4", {0, 1}},
        {"x_5", {0, 1}}
    };
    ASSERT_EQ(independent_set_instance->variables_domain, variables_domain_test);
}

TEST_F(ProblemIndependentSetTest, TestIsDDCreated) {
    ASSERT_FALSE(dd_instance->get_desition_diagram().nodes.empty());
}

TEST_F(ProblemIndependentSetTest, TestVerboseCreateDD) {
    ofstream out("createDDIndependentSet.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout.rdbuf(coutbuf);

    DD dd_independent_set_instance(*independent_set_instance, true);
    
    ifstream file("Test/txt_files/createDDIndependentSet.txt");
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createDDIndependentSet.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_EQ(actual_output, expected_output);
}

TEST_F(ProblemIndependentSetTest, TestVerboseCreateReduceDD) {
    ofstream out("createReduceDDIndependentSet.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout.rdbuf(coutbuf);

    DD dd_independent_set_instance(*independent_set_instance, false);
    dd_independent_set_instance.create_reduce_desition_diagram(true);
    
    ifstream file("Test/txt_files/createReduceDDIndependentSet.txt");
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createReduceDDIndependentSet.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_EQ(actual_output, expected_output);
}
*/