#include <gtest/gtest.h>
#include "../../Examples/SetCovering/SetCoveringProblem.h" 
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

class ProblemSetCoveringTest : public ::testing::Test {
protected:
    void SetUp() override {
        vector<vector<int>> matrix_of_wheight = {{1, 1, 1, 0, 0, 0},
                                             {1, 0, 0, 1, 1, 0},
                                             {0, 1, 0, 1, 0, 1}};
        vector<int> right_side_of_restrictions = {1, 1, 1};

        
        vector<int> initial_state = {1, 2, 3};
        vector<pair<string, vector<int>>> variables = {
            make_pair("x_1", vector<int>{0, 1}), 
            make_pair("x_2", vector<int>{0, 1}),
            make_pair("x_3", vector<int>{0, 1}), 
            make_pair("x_4", vector<int>{0, 1}),
            make_pair("x_5", vector<int>{0, 1}),
            make_pair("x_6", vector<int>{0, 1})
        };

        set_covering_instance = new SetCoveringProblem(initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
        dd_instance = new DD(*set_covering_instance, false);
    }

    void TearDown() override {
        delete set_covering_instance;
        delete dd_instance;
    }
    SetCoveringProblem* set_covering_instance;
    DD* dd_instance;
};

/*
TEST_F(ProblemSetCoveringTest, TestOrderedVariables) {
    vector<string> ordered_variables_test = {"x_1", "x_2", "x_3", "x_4", "x_5", "x_6"};
    ASSERT_EQ(set_covering_instance->ordered_variables, ordered_variables_test);
}

TEST_F(ProblemSetCoveringTest, TestVariablesDomain) {
    map<string, vector<int>> variables_domain_test = {
        {"x_1", {0, 1}},
        {"x_2", {0, 1}},
        {"x_3", {0, 1}},
        {"x_4", {0, 1}},
        {"x_5", {0, 1}},
        {"x_6", {0, 1}}
    };
    ASSERT_EQ(set_covering_instance->variables_domain, variables_domain_test);
}

TEST_F(ProblemSetCoveringTest, TestIsDDCreated) {
    ASSERT_FALSE(dd_instance->get_desition_diagram().nodes.empty());
}

TEST_F(ProblemSetCoveringTest, TestVerboseCreateDD) {
    ofstream out("createDDSetCovering.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout.rdbuf(coutbuf);

    DD dd_set_covering_instance(*set_covering_instance, true);
    
    ifstream file("Test/txt_files/createDDSetCovering.txt");
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createDDSetCovering.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_EQ(actual_output, expected_output);
}
*/