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

bool areEqualIgnoringNonPrintable(const std::string& str1, const std::string& str2) {
    auto isNonPrintable = [](unsigned char c) { return !std::isprint(c); };

    std::string cleanStr1, cleanStr2;
    std::copy_if(str1.begin(), str1.end(), std::back_inserter(cleanStr1), isNonPrintable);
    std::copy_if(str2.begin(), str2.end(), std::back_inserter(cleanStr2), isNonPrintable);

    return cleanStr1 == cleanStr2;
}

class ProblemKnapsackTest : public ::testing::Test {
protected:
    void SetUp() override {
        initial_state = {0, 0};
        vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}), 
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}), 
            make_pair("x_4", vector<int>{0, 1})
        };

        vector<vector<int>> matrix_of_wheight = {{3, 3, 4, 6}};
        vector<int> right_side_of_restrictions = {6};

        knapsack_instance = new KnapsackProblem(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
        dd_instance = new DD(*knapsack_instance, false);
    }

    void TearDown() override {
        delete knapsack_instance;
        delete dd_instance;
    }
    vector<int> initial_state;
    KnapsackProblem* knapsack_instance;
    DD* dd_instance;
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

TEST_F(ProblemKnapsackTest, TestIsDDCreated) {
    ASSERT_FALSE(dd_instance->get_desition_diagram().nodes.empty());
}

TEST_F(ProblemKnapsackTest, TestVerboseCreateDD) {
    ofstream out("createDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, true);
    cout.rdbuf(coutbuf);
    
    ifstream file("Test/txt_files/createDDKnapsack.txt");
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createDDKnapsack.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(areEqualIgnoringNonPrintable(actual_output, expected_output));
}

/*
TEST_F(ProblemKnapsackTest, TestVerboseCreateReduceDD) {
    ofstream out("createReduceDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, false);
    dd_knapsack_instance.create_reduce_desition_diagram(true);

    cout.rdbuf(coutbuf);
    
    ifstream file("Test/txt_files/createReduceDDKnapsack.txt");
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createReduceDDKnapsack.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_EQ(actual_output, expected_output);
}
*/

