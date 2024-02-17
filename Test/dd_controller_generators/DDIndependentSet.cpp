#include "Graph.h"

using namespace std;

Graph<vector<int>> GetExactDDIndependentSet() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3, 4, 5});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {2, 3, 4, 5});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {4, 5});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {3, 4, 5});
    Arc<vector<int>>* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);


    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {5});
    Arc<vector<int>>* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {4, 5});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 0, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {4, 5});
    Arc<vector<int>>* arc_3_6 = new Arc(node_3, node_6, 0, "x_3");
    node_6->add_in_arc(arc_3_6);
    node_3->add_out_arc(arc_3_6);
    Arc<vector<int>>* arc_5_6 = new Arc(node_5, node_6, 0, "x_3");
    node_5->add_out_arc(arc_5_6);
    node_6->add_in_arc(arc_5_6);
    graph->add_node(node_6);

    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {5});
    Arc<vector<int>>* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);
    Arc<vector<int>>* arc_4_7 = new Arc(node_4, node_7, 0, "x_3");
    node_4->add_out_arc(arc_4_7);
    node_7->add_in_arc(arc_4_7);
    graph->add_node(node_7);

    graph->add_new_layer();
    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {5});
    Arc<vector<int>>* arc_6_8 = new Arc(node_6, node_8, 0, "x_4");
    node_6->add_out_arc(arc_6_8);
    node_8->add_in_arc(arc_6_8);
    Arc<vector<int>>* arc_7_8 = new Arc(node_7, node_8, 0, "x_4");
    node_7->add_out_arc(arc_7_8);
    node_8->add_in_arc(arc_7_8);
    graph->add_node(node_8);

    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {});
    Arc<vector<int>>* arc_6_9 = new Arc(node_6, node_9, 1, "x_4");
    node_6->add_out_arc(arc_6_9);
    node_9->add_in_arc(arc_6_9);
    graph->add_node(node_9);

    graph->add_new_layer();
    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_8_10_1 = new Arc(node_8, node_10, 0, "x_5");
    node_8->add_out_arc(arc_8_10_1);
    node_10->add_in_arc(arc_8_10_1);
    Arc<vector<int>>* arc_8_10_2 = new Arc(node_8, node_10, 1, "x_5");
    node_8->add_out_arc(arc_8_10_2);
    node_10->add_in_arc(arc_8_10_2);
    Arc<vector<int>>* arc_9_10 = new Arc(node_9, node_10, 0, "x_5");
    node_9->add_out_arc(arc_9_10);
    node_10->add_in_arc(arc_9_10);
    graph->add_node(node_10);

    return *graph;
}

Graph<vector<int>> GetReduceDDIndependentSet() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3, 4, 5});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {2, 3, 4, 5});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {4, 5});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {3, 4, 5});
    Arc<vector<int>>* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);


    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {5});
    Arc<vector<int>>* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {4, 5});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 0, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {4, 5});
    Arc<vector<int>>* arc_3_6 = new Arc(node_3, node_6, 0, "x_3");
    node_6->add_in_arc(arc_3_6);
    node_3->add_out_arc(arc_3_6);
    Arc<vector<int>>* arc_5_6 = new Arc(node_5, node_6, 0, "x_3");
    node_5->add_out_arc(arc_5_6);
    node_6->add_in_arc(arc_5_6);
    graph->add_node(node_6);

    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {5});
    Arc<vector<int>>* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);
    Arc<vector<int>>* arc_4_7 = new Arc(node_4, node_7, 0, "x_3");
    node_4->add_out_arc(arc_4_7);
    node_7->add_in_arc(arc_4_7);
    graph->add_node(node_7);

    graph->add_new_layer();
    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {5});
    Arc<vector<int>>* arc_6_8 = new Arc(node_6, node_8, 0, "x_4");
    node_6->add_out_arc(arc_6_8);
    node_8->add_in_arc(arc_6_8);
    Arc<vector<int>>* arc_7_8 = new Arc(node_7, node_8, 0, "x_4");
    node_7->add_out_arc(arc_7_8);
    node_8->add_in_arc(arc_7_8);
    graph->add_node(node_8);

    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {});
    Arc<vector<int>>* arc_6_9 = new Arc(node_6, node_9, 1, "x_4");
    node_6->add_out_arc(arc_6_9);
    node_9->add_in_arc(arc_6_9);
    graph->add_node(node_9);

    graph->add_new_layer();
    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_8_10_1 = new Arc(node_8, node_10, 0, "x_5");
    node_8->add_out_arc(arc_8_10_1);
    node_10->add_in_arc(arc_8_10_1);
    Arc<vector<int>>* arc_8_10_2 = new Arc(node_8, node_10, 1, "x_5");
    node_8->add_out_arc(arc_8_10_2);
    node_10->add_in_arc(arc_8_10_2);
    Arc<vector<int>>* arc_9_10 = new Arc(node_9, node_10, 0, "x_5");
    node_9->add_out_arc(arc_9_10);
    node_10->add_in_arc(arc_9_10);
    graph->add_node(node_10);


    return *graph;
}

Graph<vector<int>> GetRestrictedDDIndependentSet() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3, 4, 5});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {2, 3, 4, 5});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {4, 5});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {3, 4, 5});
    Arc<vector<int>>* arc_1_3_op1 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3_op1);
    node_3->add_in_arc(arc_1_3_op1);
    Arc<vector<int>>* arc_1_3_op2 = new Arc(node_1, node_3, 1, "x_2");
    node_1->add_out_arc(arc_1_3_op2);
    node_3->add_in_arc(arc_1_3_op2);
    graph->add_node(node_3);

    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {4, 5});
    Arc<vector<int>>* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);
    graph->add_node(node_4);


    graph->add_new_layer();
    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {5});
    Arc<vector<int>>* arc_3_5 = new Arc(node_3, node_5, 1, "x_3");
    node_5->add_in_arc(arc_3_5);
    node_3->add_out_arc(arc_3_5);
    graph->add_node(node_5);

    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {4, 5});
    Arc<vector<int>>* arc_3_6 = new Arc(node_3, node_6, 0, "x_3");
    node_3->add_out_arc(arc_3_6);
    node_6->add_in_arc(arc_3_6);
    Arc<vector<int>>* arc_4_6 = new Arc(node_4, node_6, 0, "x_3");
    node_4->add_out_arc(arc_4_6);
    node_6->add_in_arc(arc_4_6);
    graph->add_node(node_6);

    graph->add_new_layer();
    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {5});
    Arc<vector<int>>* arc_5_7 = new Arc(node_5, node_7, 0, "x_4");
    node_5->add_out_arc(arc_5_7);
    node_7->add_in_arc(arc_5_7);
    Arc<vector<int>>* arc_6_7 = new Arc(node_6, node_7, 0, "x_4");
    node_6->add_out_arc(arc_6_7);
    node_7->add_in_arc(arc_6_7);
    graph->add_node(node_7);

    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {});
    Arc<vector<int>>* arc_6_8 = new Arc(node_6, node_8, 1, "x_4");
    node_6->add_out_arc(arc_6_8);
    node_8->add_in_arc(arc_6_8);
    graph->add_node(node_8);

    graph->add_new_layer();
    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {});
    Arc<vector<int>>* arc_7_9_op1 = new Arc(node_7, node_9, 0, "x_5");
    node_7->add_out_arc(arc_7_9_op1);
    node_9->add_in_arc(arc_7_9_op1);
    Arc<vector<int>>* arc_7_9_op2 = new Arc(node_7, node_9, 1, "x_5");
    node_7->add_out_arc(arc_7_9_op2);
    node_9->add_in_arc(arc_7_9_op2);
    Arc<vector<int>>* arc_8_9 = new Arc(node_8, node_9, 0, "x_5");
    node_8->add_out_arc(arc_8_9);
    node_9->add_in_arc(arc_8_9);
    graph->add_node(node_9);

    return *graph;
}

Graph<vector<int>> GetRelaxedDDIndependentSet() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3, 4, 5});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {2, 3, 4, 5});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {4, 5});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {3, 4, 5});
    Arc<vector<int>>* arc_1_3_op1 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3_op1);
    node_3->add_in_arc(arc_1_3_op1);
    Arc<vector<int>>* arc_1_3_op2 = new Arc(node_1, node_3, 1, "x_2");
    node_1->add_out_arc(arc_1_3_op2);
    node_3->add_in_arc(arc_1_3_op2);
    graph->add_node(node_3);

    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {4, 5});
    Arc<vector<int>>* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);
    graph->add_node(node_4);


    graph->add_new_layer();
    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {5});
    Arc<vector<int>>* arc_3_5 = new Arc(node_3, node_5, 1, "x_3");
    node_5->add_in_arc(arc_3_5);
    node_3->add_out_arc(arc_3_5);
    graph->add_node(node_5);

    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {4, 5});
    Arc<vector<int>>* arc_3_6 = new Arc(node_3, node_6, 0, "x_3");
    node_3->add_out_arc(arc_3_6);
    node_6->add_in_arc(arc_3_6);
    Arc<vector<int>>* arc_4_6 = new Arc(node_4, node_6, 0, "x_3");
    node_4->add_out_arc(arc_4_6);
    node_6->add_in_arc(arc_4_6);
    graph->add_node(node_6);

    graph->add_new_layer();
    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {5});
    Arc<vector<int>>* arc_5_7 = new Arc(node_5, node_7, 0, "x_4");
    node_5->add_out_arc(arc_5_7);
    node_7->add_in_arc(arc_5_7);
    Arc<vector<int>>* arc_6_7 = new Arc(node_6, node_7, 0, "x_4");
    node_6->add_out_arc(arc_6_7);
    node_7->add_in_arc(arc_6_7);
    graph->add_node(node_7);

    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {});
    Arc<vector<int>>* arc_6_8 = new Arc(node_6, node_8, 1, "x_4");
    node_6->add_out_arc(arc_6_8);
    node_8->add_in_arc(arc_6_8);
    graph->add_node(node_8);

    graph->add_new_layer();
    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {});
    Arc<vector<int>>* arc_7_9_op1 = new Arc(node_7, node_9, 0, "x_5");
    node_7->add_out_arc(arc_7_9_op1);
    node_9->add_in_arc(arc_7_9_op1);
    Arc<vector<int>>* arc_7_9_op2 = new Arc(node_7, node_9, 1, "x_5");
    node_7->add_out_arc(arc_7_9_op2);
    node_9->add_in_arc(arc_7_9_op2);
    Arc<vector<int>>* arc_8_9 = new Arc(node_8, node_9, 0, "x_5");
    node_8->add_out_arc(arc_8_9);
    node_9->add_in_arc(arc_8_9);
    graph->add_node(node_9);


    return *graph;
}

Graph<vector<int>> GetFalseDDIndependentSet() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3, 4});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {2, 3, 4, 5});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {4, 5});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {3, 4, 5});
    Arc<vector<int>>* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);


    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {5});
    Arc<vector<int>>* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {4, 5});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 0, "x_3");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {4, 5});
    Arc<vector<int>>* arc_3_6 = new Arc(node_3, node_6, 0, "x_3");
    node_6->add_in_arc(arc_3_6);
    node_3->add_out_arc(arc_3_6);
    Arc<vector<int>>* arc_5_6 = new Arc(node_5, node_6, 0, "x_3");
    node_5->add_out_arc(arc_5_6);
    node_6->add_in_arc(arc_5_6);
    graph->add_node(node_6);

    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {5});
    Arc<vector<int>>* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);
    Arc<vector<int>>* arc_4_7 = new Arc(node_4, node_7, 0, "x_3");
    node_4->add_out_arc(arc_4_7);
    node_7->add_in_arc(arc_4_7);
    graph->add_node(node_7);

    graph->add_new_layer();
    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {5});
    Arc<vector<int>>* arc_6_8 = new Arc(node_6, node_8, 0, "x_4");
    node_6->add_out_arc(arc_6_8);
    node_8->add_in_arc(arc_6_8);
    Arc<vector<int>>* arc_7_8 = new Arc(node_7, node_8, 0, "x_4");
    node_7->add_out_arc(arc_7_8);
    node_8->add_in_arc(arc_7_8);
    graph->add_node(node_8);

    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {});
    Arc<vector<int>>* arc_6_9 = new Arc(node_6, node_9, 1, "x_4");
    node_6->add_out_arc(arc_6_9);
    node_9->add_in_arc(arc_6_9);
    graph->add_node(node_9);

    graph->add_new_layer();
    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_8_10_1 = new Arc(node_8, node_10, 0, "x_5");
    node_8->add_out_arc(arc_8_10_1);
    node_10->add_in_arc(arc_8_10_1);
    Arc<vector<int>>* arc_8_10_2 = new Arc(node_8, node_10, 1, "x_5");
    node_8->add_out_arc(arc_8_10_2);
    node_10->add_in_arc(arc_8_10_2);
    Arc<vector<int>>* arc_9_10 = new Arc(node_9, node_10, 0, "x_5");
    node_9->add_out_arc(arc_9_10);
    node_10->add_in_arc(arc_9_10);
    graph->add_node(node_10);


    return *graph;
}