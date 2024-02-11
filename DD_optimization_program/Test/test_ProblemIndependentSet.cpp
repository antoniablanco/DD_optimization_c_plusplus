#include <gtest/gtest.h>
#include "../../Examples/IndependentSet/IndependentSetProblem.h" 
#include "../../Class/DD.h"
#include "../../Class/AnswerStructure/ObjectiveStructure.h"
#include "../../Class/ObjectiveFunction/LinearObjectiveDP.h"
#include "../../Class/ObjectiveFunction/ObjectiveFunction.h"
#include "dd_controller_generators/DDIndependentSet.cpp"

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
#include <filesystem>

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
        
        initial_state = vector<int>{1, 2, 3, 4, 5};
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

    ObjectiveStruct getLinearDpSolution() {
        vector<int> objective_weights = {3, 4, 2, 2, 7};
        ObjectiveFunction objective_function_instance = ObjectiveFunction(*dd_instance);
        LinearObjectiveDP linear_objective_instance = LinearObjectiveDP(objective_weights, "max");
        objective_function_instance.set_objective_function(linear_objective_instance);

        return objective_function_instance.solve_dd();
    }
    vector<int> initial_state;
    IndependentSetProblem* independent_set_instance;
    DD* dd_instance;
};


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

    DD dd_independent_set_instance(*independent_set_instance, true);
    cout.rdbuf(coutbuf);
    
    string source_directory = fs::current_path().parent_path().string();
    string full_file_path = source_directory + "/DD_optimization_program/Test/txt_files/createDDIndependentSet.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    
    ifstream actual_file("createDDIndependentSet.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemIndependentSetTest, TestVerboseCreateReduceDD) {
    ofstream out("createReduceDDIndependentSet.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_independent_set_instance(*independent_set_instance, false);
    dd_independent_set_instance.create_reduce_desition_diagram(true);

    cout.rdbuf(coutbuf);

    string source_directory = fs::current_path().parent_path().string();
    string full_file_path = source_directory + "/DD_optimization_program/Test/txt_files/createReduceDDIndependentSet.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createReduceDDIndependentSet.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemIndependentSetTest, TestVerboseCreateRestrictedDD) {
    ofstream out("createRestrictedDDIndependentSet.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_independent_set_instance(*independent_set_instance, false);
    dd_independent_set_instance.create_restricted_desition_diagram(2, true);

    cout.rdbuf(coutbuf);
    
    string source_directory = fs::current_path().parent_path().string();
    string full_file_path = source_directory + "/DD_optimization_program/Test/txt_files/createRestrictedDDIndependentSet.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createRestrictedDDIndependentSet.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemIndependentSetTest, TestVerboseCreateRelaxedDD) {
    ofstream out("createRelaxedDDIndependentSet.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_independent_set_instance(*independent_set_instance, false);
    dd_independent_set_instance.create_relaxed_desition_diagram(2, true);

    cout.rdbuf(coutbuf);
    
    string source_directory = fs::current_path().parent_path().string();
    string full_file_path = source_directory + "/DD_optimization_program/Test/txt_files/createRelaxedDDIndependentSet.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    ifstream actual_file("createRelaxedDDIndependentSet.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemIndependentSetTest, TestCreateDDGraphEqual) {
    Graph expected_graph = GetExactDDIndependentSet();
    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemIndependentSetTest, TestCreateReduceDDGraphEqual) {
    Graph expected_graph = GetReduceDDIndependentSet();
    dd_instance->create_reduce_desition_diagram();

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemIndependentSetTest, TestCreateRestrictedDDGraphEqual) {
    Graph expected_graph_one = GetRestrictedDDIndependentSet();
    Graph expected_graph_two =GetDiferentOrderRestrictedDDIndependentSet();
    dd_instance->create_restricted_desition_diagram(2);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph_one);
    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph_two);
}

TEST_F(ProblemIndependentSetTest, CompareTwoDifferentGraphs) {
    Graph not_expected_graph = GetFalseDDIndependentSet();

    ASSERT_FALSE(dd_instance->get_desition_diagram()==not_expected_graph);
}

TEST_F(ProblemIndependentSetTest, TestCreateRelaxedDDGraphEqual) {
    Graph expected_graph = GetRelaxedDDIndependentSet();
    dd_instance->create_relaxed_desition_diagram(2);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemIndependentSetTest, TestGetCopy) {
    Graph original_graph = dd_instance->get_desition_diagram();
    Graph copied_graph = dd_instance->get_desition_diagram_copy();
    
    ASSERT_NE(&original_graph, &copied_graph);
    ASSERT_TRUE(original_graph==copied_graph);
}

TEST_F(ProblemIndependentSetTest, TestGetDDBuilderTime) {
    ASSERT_GT(stof(dd_instance->get_dd_builder_time()), 0);
}

TEST_F(ProblemIndependentSetTest, TestGetReduceDDBuilderTime) {
    dd_instance->create_reduce_desition_diagram();
    ASSERT_GT(stof(dd_instance->get_reduce_dd_builder_time()), 0);
}

TEST_F(ProblemIndependentSetTest, TestGetRestrictedDDBuilderTime) {
    dd_instance->create_restricted_desition_diagram(2);
    ASSERT_GT(stof(dd_instance->get_restricted_dd_builder_time()), 0);
}

TEST_F(ProblemIndependentSetTest, TestGetRelaxedDDBuilderTime) {
    dd_instance->create_relaxed_desition_diagram(2);
    ASSERT_GT(stof(dd_instance->get_relaxed_dd_builder_time()), 0);
}

TEST_F(ProblemIndependentSetTest, GetSolutionForDD) {
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 11;
    string expected_path = " arc_0_1(0)-> arc_1_4(1)-> arc_4_7(0)-> arc_7_8(0)-> arc_8_10(1)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemIndependentSetTest, GetSolutionForReduceDD) {
    dd_instance->create_reduce_desition_diagram();
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 11;
    string expected_path = " arc_0_1(0)-> arc_1_4(1)-> arc_4_7(0)-> arc_7_8(0)-> arc_8_10(1)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemIndependentSetTest, GetSolutionForRestrictedeDD) {
    dd_instance->create_restricted_desition_diagram(2, false);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 10;
    string expected_path = " arc_0_2(1)-> arc_2_4(0)-> arc_4_5(0)-> arc_5_7(0)-> arc_7_9(1)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemIndependentSetTest, GetSolutionForRelaxedeDD) {
    dd_instance->create_relaxed_desition_diagram(2);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 13;
    string expected_path = " arc_0_1(0)-> arc_1_3(1)-> arc_3_6(1)-> arc_6_7(0)-> arc_7_9(1)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemIndependentSetTest, TestCompareGMLDDGraph) {
    dd_instance->export_graph_file("test");

    string source_directory = fs::current_path().parent_path().string();

    string expected_file_path = source_directory + "/DD_optimization_program/Test/gml_files/exact_dd_independent_set.gml";
    string actual_file_path = source_directory + "/DD_optimization_program/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemIndependentSetTest, TestCompareGMLReduceDDGraph) {
    dd_instance->create_reduce_desition_diagram();
    dd_instance->export_graph_file("test");

    string source_directory = fs::current_path().parent_path().string();

    string expected_file_path = source_directory + "/DD_optimization_program/Test/gml_files/reduce_dd_independent_set.gml";
    string actual_file_path = source_directory + "/DD_optimization_program/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemIndependentSetTest, TestCompareGMLRestrictedDDGraph) {
    dd_instance->create_restricted_desition_diagram(2);
    dd_instance->export_graph_file("test");

    string source_directory = fs::current_path().parent_path().string();

    string expected_file_path = source_directory + "/DD_optimization_program/Test/gml_files/restricted_dd_independent_set.gml";
    string actual_file_path = source_directory + "/DD_optimization_program/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemIndependentSetTest, TestCompareGMLRelaxedDDGraph) {
    dd_instance->create_relaxed_desition_diagram(2);
    dd_instance->export_graph_file("test");

    string source_directory = fs::current_path().parent_path().string();

    string expected_file_path = source_directory + "/DD_optimization_program/Test/gml_files/relax_dd_independent_set.gml";
    string actual_file_path = source_directory + "/DD_optimization_program/test.gml";

    ASSERT_TRUE(ifstream(expected_file_path).good());
    ASSERT_TRUE(ifstream(actual_file_path).good());

    ifstream expected_file(expected_file_path);
    ifstream actual_file(actual_file_path);
    string expected_output((istreambuf_iterator<char>(expected_file)), istreambuf_iterator<char>());
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());

    ASSERT_TRUE(actual_output==expected_output);
}

