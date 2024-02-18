#include <gtest/gtest.h>
#include "../../Examples/SetCovering/SetCoveringProblem.h"
#include "../../Class/DD.h"
#include "../../Class/ObjectiveFunction/LinearObjectiveDP.h"
#include "../../Class/ObjectiveFunction/ObjectiveFunction.h"
#include "dd_controller_generators/DDSetCovering.cpp"

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


        initial_state = vector<int>{1, 2, 3};
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

        source_directory = fs::current_path().parent_path().string();
    }

    void TearDown() override {
        delete set_covering_instance;
        delete dd_instance;
    }
    ObjectiveStruct<vector<int>> getLinearDpSolution() {
        vector<int> objective_weights = {2, 1, 4, 3, 4, 3};
        ObjectiveFunction objective_function_instance = ObjectiveFunction<vector<int>>(*dd_instance);
        LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<vector<int>>(objective_weights, "min");
        objective_function_instance.set_objective_function(linear_objective_instance);

        return objective_function_instance.solve_dd();
    }
    vector<int> initial_state;
    SetCoveringProblem* set_covering_instance;
    DD<vector<int>>* dd_instance;
    string source_directory;
};


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

    DD dd_set_covering_instance(*set_covering_instance, true);
    cout.rdbuf(coutbuf);

    string full_file_path = source_directory + "/Test/txt_files/createDDSetCovering.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createDDSetCovering.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemSetCoveringTest, TestVerboseCreateReduceDD) {
    ofstream out("createReduceDDSetCovering.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_set_covering_instance(*set_covering_instance, false);
    dd_set_covering_instance.create_reduce_decision_diagram(true);

    cout.rdbuf(coutbuf);

    string full_file_path = source_directory + "/Test/txt_files/createReduceDDSetCovering.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createReduceDDSetCovering.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemSetCoveringTest, TestVerboseCreateRestrictedDD) {
    ofstream out("createRestrictedDDSetCovering.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_set_covering_instance(*set_covering_instance, false);
    dd_set_covering_instance.create_restricted_decision_diagram(3, true);

    cout.rdbuf(coutbuf);

    string full_file_path = source_directory + "/Test/txt_files/createRestrictedDDSetCovering.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createRestrictedDDSetCovering.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemSetCoveringTest, TestVerboseCreateRelaxedDD) {
    ofstream out("createRelaxedDDSetCovering.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_set_covering_instance(*set_covering_instance, false);
    dd_set_covering_instance.create_relaxed_decision_diagram(3, true);

    cout.rdbuf(coutbuf);

    string full_file_path = source_directory + "/Test/txt_files/createRelaxedDDSetCovering.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createRelaxedDDSetCovering.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemSetCoveringTest, TestCreateDDGraphEqual) {
    Graph expected_graph = GetExactDDSetCovering();
    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemSetCoveringTest, TestCreateReduceDDGraphEqual) {
    Graph expected_graph = GetReduceDDSetCovering();
    dd_instance->create_reduce_decision_diagram();

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemSetCoveringTest, TestCreateRestrictedDDGraphEqual) {
    Graph expected_graph = GetRestrictedDDSetCovering();
    dd_instance->create_restricted_decision_diagram(3);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemSetCoveringTest, CompareTwoDifferentGraphs) {
    Graph not_expected_graph = GetFalseDDSetCovering();

    ASSERT_FALSE(dd_instance->get_desition_diagram()==not_expected_graph);
}

TEST_F(ProblemSetCoveringTest, TestCreateRelaxedDDGraphEqual) {
    Graph expected_graph = GetRelaxedDDSetCovering();
    dd_instance->create_relaxed_decision_diagram(3);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemSetCoveringTest, TestGetCopy) {
    Graph original_graph = dd_instance->get_desition_diagram();
    Graph copied_graph = dd_instance->get_desition_diagram_copy();

    ASSERT_NE(&original_graph, &copied_graph);
    ASSERT_TRUE(original_graph==copied_graph);
}

TEST_F(ProblemSetCoveringTest, TestGetDDBuilderTime) {
    ASSERT_GT(stof(dd_instance->get_dd_builder_time()), 0);
}

TEST_F(ProblemSetCoveringTest, TestGetReduceDDBuilderTime) {
    dd_instance->create_reduce_decision_diagram();
    ASSERT_GT(stof(dd_instance->get_reduce_dd_builder_time()), 0);
}

TEST_F(ProblemSetCoveringTest, TestGetRestrictedDDBuilderTime) {
    dd_instance->create_restricted_decision_diagram(2);
    ASSERT_GT(stof(dd_instance->get_restricted_dd_builder_time()), 0);
}

TEST_F(ProblemSetCoveringTest, TestGetRelaxedDDBuilderTime) {
    dd_instance->create_relaxed_decision_diagram(2);
    ASSERT_GT(stof(dd_instance->get_relaxed_dd_builder_time()), 0);
}

TEST_F(ProblemSetCoveringTest, GetSolutionForDD) {
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 3;
    string expected_path = " arc_0_2(1)-> arc_2_6(1)-> arc_6_10(0)-> arc_10_12(0)-> arc_12_16(0)-> arc_16_17(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemSetCoveringTest, GetSolutionForReduceDD) {
    dd_instance->create_reduce_decision_diagram();
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 3;
    string expected_path = " arc_0_2(1)-> arc_2_6(1)-> arc_6_10(0)-> arc_10_12(0)-> arc_12_16(0)-> arc_16_17(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemSetCoveringTest, GetSolutionForRestrictedeDD) {
    dd_instance->create_restricted_decision_diagram(3, false);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 3;
    string expected_path = " arc_0_2(1)-> arc_2_5(1)-> arc_5_8(0)-> arc_8_10(0)-> arc_10_12(0)-> arc_12_14(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemSetCoveringTest, GetSolutionForRelaxedeDD) {
    dd_instance->create_relaxed_decision_diagram(3);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 3;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_6(0)-> arc_6_10(1)-> arc_10_12(0)-> arc_12_14(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemSetCoveringTest, TestCompareGMLDDGraph) {
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/exact_dd_set_covering.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemSetCoveringTest, TestCompareGMLReduceDDGraph) {
    dd_instance->create_reduce_decision_diagram();
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/reduce_dd_set_covering.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemSetCoveringTest, TestCompareGMLRestrictedDDGraph) {
    dd_instance->create_restricted_decision_diagram(3);
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/restricted_dd_set_covering.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemSetCoveringTest, TestCompareGMLRelaxedDDGraph) {
    dd_instance->create_relaxed_decision_diagram(3);
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/relax_dd_set_covering.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

