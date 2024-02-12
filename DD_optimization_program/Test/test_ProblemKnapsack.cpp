#include <gtest/gtest.h>
#include "../../Examples/Knapsack/KnapsackProblem.h" 
#include "../../Class/DD.h"
#include "../../Class/AnswerStructure/ObjectiveStructure.h"
#include "../../Class/ObjectiveFunction/LinearObjectiveDP.h"
#include "../../Class/ObjectiveFunction/ObjectiveFunction.h"
#include "dd_controller_generators/DDKnapsack.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <filesystem>

namespace fs = std::filesystem;
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

        source_directory = fs::current_path().parent_path().string();
        if (source_directory == "/Users/antoniablanco/Desktop/DD_optimization_c-") {
            source_directory = source_directory + "/DD_optimization_program";
        }
    }

    void TearDown() override {
        delete knapsack_instance;
        delete dd_instance;
    }

    ObjectiveStruct getLinearDpSolution() {
        vector<int> objective_weights = {-5, 1, 18, 17};
        ObjectiveFunction objective_function_instance = ObjectiveFunction(*dd_instance);
        LinearObjectiveDP linear_objective_instance = LinearObjectiveDP(objective_weights, "max");
        objective_function_instance.set_objective_function(linear_objective_instance);

        return objective_function_instance.solve_dd();
    }

    vector<int> initial_state;
    KnapsackProblem* knapsack_instance;
    DD* dd_instance;
    string source_directory;
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
    string full_file_path = source_directory + "/Test/txt_files/createDDKnapsack.txt";

    ifstream file(full_file_path);
    string expected_output((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    
    ifstream actual_file("createDDKnapsack.txt");
    string actual_output((istreambuf_iterator<char>(actual_file)), istreambuf_iterator<char>());
    actual_file.close();

    ASSERT_TRUE(actual_output==expected_output);
}

TEST_F(ProblemKnapsackTest, TestVerboseCreateReduceDD) {
    ofstream out("createReduceDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, false);
    dd_knapsack_instance.createReduceDecisionDiagram(true);

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

TEST_F(ProblemKnapsackTest, TestVerboseCreateRestrictedDD) {
    ofstream out("createRestrictedDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, false);
    dd_knapsack_instance.createRestrictedDecisionDiagram(3, true);

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

TEST_F(ProblemKnapsackTest, TestVerboseCreateRelaxedDD) {
    ofstream out("createRelaxedDDKnapsack.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    DD dd_knapsack_instance(*knapsack_instance, false);
    dd_knapsack_instance.createRelaxedDecisionDiagram(3, true);

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

TEST_F(ProblemKnapsackTest, TestCreateDDGraphEqual) {
    Graph expected_graph = GetExactDDKnapsack();
    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTest, TestCreateReduceDDGraphEqual) {
    Graph expected_graph = GetReduceDDKnapsack();
    dd_instance->createReduceDecisionDiagram();

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTest, TestCreateRestrictedDDGraphEqual) {
    Graph expected_graph = GetRestrictedDDKnapsack();
    dd_instance->createRestrictedDecisionDiagram(3);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTest, CompareTwoDifferentGraphs) {
    Graph not_expected_graph = GetFalseDDKnapsack();

    ASSERT_FALSE(dd_instance->get_desition_diagram()==not_expected_graph);
}

TEST_F(ProblemKnapsackTest, TestCreateRelaxedDDGraphEqual) {
    Graph expected_graph = GetRelaxedDDKnapsack();
    dd_instance->createRelaxedDecisionDiagram(3);

    ASSERT_TRUE(dd_instance->get_desition_diagram()==expected_graph);
}

TEST_F(ProblemKnapsackTest, TestGetCopy) {
    Graph original_graph = dd_instance->get_desition_diagram();
    Graph copied_graph = dd_instance->get_desition_diagram_copy();
    
    ASSERT_NE(&original_graph, &copied_graph);
    ASSERT_TRUE(original_graph==copied_graph);
}

TEST_F(ProblemKnapsackTest, TestGetDDBuilderTime) {
    ASSERT_GT(stof(dd_instance->getDdBuilderTime()), 0);
}

TEST_F(ProblemKnapsackTest, TestGetReduceDDBuilderTime) {
    dd_instance->createReduceDecisionDiagram();
    ASSERT_GT(stof(dd_instance->getReduceDdBuilderTime()), 0);
}

TEST_F(ProblemKnapsackTest, TestGetRestrictedDDBuilderTime) {
    dd_instance->createRestrictedDecisionDiagram(3);
    ASSERT_GT(stof(dd_instance->getRestrictedDdBuilderTime()), 0);
}

TEST_F(ProblemKnapsackTest, TestGetRelaxedDDBuilderTime) {
    dd_instance->createRelaxedDecisionDiagram(3, true);
    ASSERT_GT(stof(dd_instance->get_relaxed_dd_builder_time()), 0);
}

TEST_F(ProblemKnapsackTest, GetSolutionForDD) {
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 18;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_7(1)-> arc_7_10(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTest, GetSolutionForReduceDD) {
    dd_instance->createReduceDecisionDiagram();
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 18;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_6(1)-> arc_6_7(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTest, GetSolutionForRestrictedeDD) {
    dd_instance->createRestrictedDecisionDiagram(3);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 18;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_6(1)-> arc_6_9(0)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTest, GetSolutionForRelaxedeDD) {
    dd_instance->createRelaxedDecisionDiagram(3);
    ObjectiveStruct solution = getLinearDpSolution();
    int expected_value = 35;
    string expected_path = " arc_0_1(0)-> arc_1_3(0)-> arc_3_6(1)-> arc_6_9(1)";
    ASSERT_EQ(solution.value, expected_value);
    ASSERT_EQ(solution.path, expected_path);
}

TEST_F(ProblemKnapsackTest, TestCompareGMLDDGraph) {
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

TEST_F(ProblemKnapsackTest, TestCompareGMLReduceDDGraph) {
    dd_instance->createReduceDecisionDiagram();
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

TEST_F(ProblemKnapsackTest, TestCompareGMLRestrictedDDGraph) {
    dd_instance->createRestrictedDecisionDiagram(3);
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

TEST_F(ProblemKnapsackTest, TestCompareGMLRelaxedDDGraph) {
    dd_instance->createRelaxedDecisionDiagram(3);
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
