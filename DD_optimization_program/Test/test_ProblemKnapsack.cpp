#include <gtest/gtest.h>
#include "../../Examples/Knapsack/KnapsackProblem.h" 
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

class ProblemKnapsackTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector<int> initial_state = {0, 0};
        vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}), 
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}), 
            make_pair("x_4", vector<int>{0, 1})
        };

        vector<vector<int>> matrix_of_wheight = {{3, 3, 4, 6}};
        vector<int> right_side_of_restrictions = {6};

        knapsack_instance = new KnapsackProblem(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
        dd_knapsack_instance = new DD(*knapsack_instance, false);
    }

    void TearDown() override {
        delete knapsack_instance;
        delete dd_knapsack_instance;
    }
    KnapsackProblem* knapsack_instance;
    DD* dd_knapsack_instance;
};

TEST_F(ProblemKnapsackTest, TestOrderedVariables) {
    vector<string> ordered_variables_test = {"x_1", "x_2", "x_3", "x_4"};
    ASSERT_EQ(knapsack_instance->ordered_variables, ordered_variables_test);
}

TEST_F(ProblemKnapsackTest, TestVariablesDomain) {
    map<string, vector<int>> variables_domain_test = {
        {"x_1", {0, 1}},
        {"x_2", {0, 1}},
        {"x_3", {0, 1}},
        {"x_4", {0, 1}}
    };
    ASSERT_EQ(knapsack_instance->variables_domain, variables_domain_test);
}
