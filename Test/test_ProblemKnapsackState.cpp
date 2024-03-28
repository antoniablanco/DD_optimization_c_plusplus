#include <gtest/gtest.h>
#include "../../Examples/KnapsackState/KnapsackProblemState.h"
#include "../../Class/DD.h"
#include "../../Class/ObjectiveFunction/LinearObjectiveDP.h"
#include "../../Class/ObjectiveFunction/ObjectiveFunction.h"
#include "dd_controller_generators/DDKnapsackState.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;


class ProblemKnapsackTestState : public ::testing::Test {
protected:
    void SetUp() override {
        initial_state = new State({0, 0});
        vector<pair<string, vector<int>>> variables = {
                make_pair("x_1", vector<int>{0, 1}),
                make_pair("x_2", vector<int>{0, 1}),
                make_pair("x_3", vector<int>{0, 1}),
                make_pair("x_4", vector<int>{0, 1})
        };

        vector<vector<int>> matrix_of_wheight = {{3, 3, 4, 6}};
        vector<int> right_side_of_restrictions = {6};

        knapsack_instance = new KnapsackProblemState(*initial_state, variables, matrix_of_wheight, right_side_of_restrictions);
        dd_instance = new DD(*knapsack_instance, false);

        source_directory = fs::current_path().parent_path().string();
    }

    void TearDown() override {
        delete knapsack_instance;
        delete dd_instance;
        delete initial_state;
    }

    ObjectiveStruct<State> getLinearDpSolution() {
        vector<int> objective_weights = {-5, 1, 18, 17};
        ObjectiveFunction objective_function_instance = ObjectiveFunction<State>(*dd_instance);
        LinearObjectiveDP linear_objective_instance = LinearObjectiveDP<State>(objective_weights, "max");
        objective_function_instance.set_objective_function(linear_objective_instance);

        return objective_function_instance.solve_dd();
    }

    State* initial_state;
    KnapsackProblemState* knapsack_instance;
    DD<State>* dd_instance;
    string source_directory;
};

TEST_F(ProblemKnapsackTestState, TestOrderedVariables) {
    vector<string> ordered_variables_test = {"x_1", "x_2", "x_3", "x_4"};
    ASSERT_EQ(knapsack_instance->ordered_variables, ordered_variables_test);
}

TEST_F(ProblemKnapsackTestState, TestVariablesDomain) {
    map<string, vector<int>> variables_domain_test = {
            {"x_1", {0, 1}},
            {"x_2", {0, 1}},
            {"x_3", {0, 1}},
            {"x_4", {0, 1}}
    };
    ASSERT_EQ(knapsack_instance->variables_domain, variables_domain_test);
}

TEST_F(ProblemKnapsackTestState, TestIsDDCreated) {
    ASSERT_FALSE(dd_instance->get_desition_diagram().nodes.empty());
}

TEST_F(ProblemKnapsackTestState, TestVerboseCreateDD) {
    ofstream out("createDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, true);
    cout.rdbuf(coutbuf);
    string full_file_path = source_directory + "/Test/txt_files/createDDKnapsack.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createDDKnapsack.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTestState, TestVerboseCreateReduceDD) {
    ofstream out("createReduceDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, false);
    dd_knapsack_instance.create_reduce_decision_diagram(true);

    cout.rdbuf(coutbuf);

    string full_file_path = source_directory + "/Test/txt_files/createReduceDDKnapsack.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createReduceDDKnapsack.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTestState, TestVerboseCreateRestrictedDD) {
    ofstream out("createRestrictedDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, false);
    dd_knapsack_instance.create_restricted_decision_diagram(3, true);

    cout.rdbuf(coutbuf);

    string full_file_path = source_directory + "/Test/txt_files/createRestrictedDDKnapsack.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createRestrictedDDKnapsack.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTestState, TestVerboseCreateRelaxedDD) {
    ofstream out("createRelaxedDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, false);
    dd_knapsack_instance.create_relaxed_decision_diagram(3, true);

    cout.rdbuf(coutbuf);

    string full_file_path = source_directory + "/Test/txt_files/createRelaxedDDKnapsack.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createRelaxedDDKnapsack.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTestState, TestCreateDDGraphEqual) {
    Graph expected_graph = GetExactDDKnapsackState();
    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTestState, TestCreateReduceDDGraphEqual) {
    Graph expected_graph = GetReduceDDKnapsackState();
    dd_instance->create_reduce_decision_diagram();

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTestState, TestCreateRestrictedDDGraphEqual) {
    Graph expected_graph = GetRestrictedDDKnapsackState();
    dd_instance->create_restricted_decision_diagram(3);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTestState, CompareTwoDifferentGraphs) {
    Graph not_expected_graph = GetFalseDDKnapsackState();

    ASSERT_FALSE(dd_instance->get_desition_diagram()==not_expected_graph);
}

TEST_F(ProblemKnapsackTestState, TestCreateRelaxedDDGraphEqual) {
    Graph expected_graph = GetRelaxedDDKnapsackState();
    dd_instance->create_relaxed_decision_diagram(3);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTestState, TestGetCopy) {
    Graph original_graph = dd_instance->get_desition_diagram();
    Graph copied_graph = dd_instance->get_desition_diagram_copy();

    ASSERT_NE(&original_graph, &copied_graph);
    ASSERT_TRUE(original_graph==copied_graph);
}

TEST_F(ProblemKnapsackTestState, TestGetDDBuilderTime) {
    ASSERT_GT(stof(dd_instance->get_dd_builder_time()), 0);
}

TEST_F(ProblemKnapsackTestState, TestGetReduceDDBuilderTime) {
    dd_instance->create_reduce_decision_diagram();
    ASSERT_GT(stof(dd_instance->get_reduce_dd_builder_time()), 0);
}

TEST_F(ProblemKnapsackTestState, TestGetRestrictedDDBuilderTime) {
    dd_instance->create_restricted_decision_diagram(3);
    ASSERT_GT(stof(dd_instance->get_restricted_dd_builder_time()), 0);
}

TEST_F(ProblemKnapsackTestState, TestGetRelaxedDDBuilderTime) {
    dd_instance->create_relaxed_decision_diagram(3, true);
    ASSERT_GT(stof(dd_instance->get_relaxed_dd_builder_time()), 0);
}

TEST_F(ProblemKnapsackTestState, GetSolutionForDD) {
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 18;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_7(1)-> arc_7_10(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTestState, GetSolutionForReduceDD) {
    dd_instance->create_reduce_decision_diagram();
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 18;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_6(1)-> arc_6_7(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTestState, GetSolutionForRestrictedeDD) {
    dd_instance->create_restricted_decision_diagram(3);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 18;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_6(1)-> arc_6_9(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTestState, GetSolutionForRelaxedeDD) {
    dd_instance->create_relaxed_decision_diagram(3);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 35;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_6(1)-> arc_6_9(1)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTestState, TestCompareGMLDDGraph) {
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/exact_dd_knapsack.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTestState, TestCompareGMLReduceDDGraph) {
    dd_instance->create_reduce_decision_diagram();
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/reduce_dd_knapsack.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTestState, TestCompareGMLRestrictedDDGraph) {
    dd_instance->create_restricted_decision_diagram(3);
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/restricted_dd_knapsack.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTestState, TestCompareGMLRelaxedDDGraph) {
    dd_instance->create_relaxed_decision_diagram(3);
    dd_instance->export_graph_file("test");

    string expected_file_path = source_directory + "/Test/gml_files/relax_dd_knapsack.gml";
    string actual_file_path = source_directory + "/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}