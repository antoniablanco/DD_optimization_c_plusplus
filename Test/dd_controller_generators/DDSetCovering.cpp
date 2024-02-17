#include "Node.h"
#include "Arc.h"
#include "Graph.h"

using namespace std;

Graph<vector<int>> GetExactDDSetCovering() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {1, 2, 3});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {3});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {1, 2, 3});
    Arc<vector<int>>* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);

    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {2});
    Arc<vector<int>>* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {3});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 0, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {});
    Arc<vector<int>>* arc_2_6 = new Arc(node_2, node_6, 1, "x_2");
    node_2->add_out_arc(arc_2_6);
    node_6->add_in_arc(arc_2_6);
    graph->add_node(node_6);

    graph->add_new_layer();
    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {2, 3});
    Arc<vector<int>>* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);
    graph->add_node(node_7);

    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {2});
    Arc<vector<int>>* arc_4_8_op1 = new Arc(node_4, node_8, 0, "x_3");
    Arc<vector<int>>* arc_4_8_op2 = new Arc(node_4, node_8, 1, "x_3");
    node_4->add_out_arc(arc_4_8_op1);
    node_4->add_out_arc(arc_4_8_op2);
    node_8->add_in_arc(arc_4_8_op1);
    node_8->add_in_arc(arc_4_8_op2);
    graph->add_node(node_8);

    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {3});
    Arc<vector<int>>* arc_5_9_op1 = new Arc(node_5, node_9, 0, "x_3");
    Arc<vector<int>>* arc_5_9_op2 = new Arc(node_5, node_9, 1, "x_3");
    node_5->add_out_arc(arc_5_9_op1);
    node_5->add_out_arc(arc_5_9_op2);
    node_9->add_in_arc(arc_5_9_op1);
    node_9->add_in_arc(arc_5_9_op2);
    graph->add_node(node_9);

    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_6_10_op1 = new Arc(node_6, node_10, 0, "x_3");
    Arc<vector<int>>* arc_6_10_op2 = new Arc(node_6, node_10, 1, "x_3");
    node_6->add_out_arc(arc_6_10_op1);
    node_6->add_out_arc(arc_6_10_op2);
    node_10->add_in_arc(arc_6_10_op1);
    node_10->add_in_arc(arc_6_10_op2);
    graph->add_node(node_10);

    graph->add_new_layer();

    Node<vector<int>>* node_11 = new Node<vector<int>>(11, {2, 3});
    Arc<vector<int>>* arc_7_11 = new Arc(node_7, node_11, 0, "x_4");
    node_7->add_out_arc(arc_7_11);
    node_11->add_in_arc(arc_7_11);
    graph->add_node(node_11);

    Node<vector<int>>* node_12 = new Node<vector<int>>(12, {});
    Arc<vector<int>>* arc_7_12 = new Arc(node_7, node_12, 1, "x_4");
    Arc<vector<int>>* arc_8_12 = new Arc(node_8, node_12, 1, "x_4");
    Arc<vector<int>>* arc_9_12 = new Arc(node_9, node_12, 1, "x_4");
    Arc<vector<int>>* arc_10_12_op1 = new Arc(node_10, node_12, 0, "x_4");
    Arc<vector<int>>* arc_10_12_op2 = new Arc(node_10, node_12, 1, "x_4");
    node_7->add_out_arc(arc_7_12);
    node_8->add_out_arc(arc_8_12);
    node_9->add_out_arc(arc_9_12);
    node_10->add_out_arc(arc_10_12_op1);
    node_10->add_out_arc(arc_10_12_op2);
    node_12->add_in_arc(arc_7_12);
    node_12->add_in_arc(arc_8_12);
    node_12->add_in_arc(arc_9_12);
    node_12->add_in_arc(arc_10_12_op1);
    node_12->add_in_arc(arc_10_12_op2);
    graph->add_node(node_12);

    Node<vector<int>>* node_13 = new Node<vector<int>>(13, {2});
    Arc<vector<int>>* arc_8_13 = new Arc(node_8, node_13, 0, "x_4");
    node_8->add_out_arc(arc_8_13);
    node_13->add_in_arc(arc_8_13);
    graph->add_node(node_13);

    Node<vector<int>>* node_14 = new Node<vector<int>>(14, {3});
    Arc<vector<int>>* arc_9_14 = new Arc(node_9, node_14, 0, "x_4");
    node_9->add_out_arc(arc_9_14);
    node_14->add_in_arc(arc_9_14);
    graph->add_node(node_14);

    graph->add_new_layer();
    Node<vector<int>>* node_15 = new Node<vector<int>>(15, {3});
    Arc<vector<int>>* arc_11_15 = new Arc(node_11, node_15, 1, "x_5");
    Arc<vector<int>>* arc_14_15_op1 = new Arc(node_14, node_15, 1, "x_5");
    Arc<vector<int>>* arc_14_15_op2 = new Arc(node_14, node_15, 0, "x_5");
    node_11->add_out_arc(arc_11_15);
    node_14->add_out_arc(arc_14_15_op1);
    node_14->add_out_arc(arc_14_15_op2);
    node_15->add_in_arc(arc_11_15);
    node_15->add_in_arc(arc_14_15_op1);
    node_15->add_in_arc(arc_14_15_op2);
    graph->add_node(node_15);

    Node<vector<int>>* node_16 = new Node<vector<int>>(16, {});
    Arc<vector<int>>* arc_12_16_op1 = new Arc(node_12, node_16, 0, "x_5");
    Arc<vector<int>>* arc_12_16_op2 = new Arc(node_12, node_16, 1, "x_5");
    Arc<vector<int>>* arc_13_16 = new Arc(node_13, node_16, 1, "x_5");
    node_12->add_out_arc(arc_12_16_op1);
    node_12->add_out_arc(arc_12_16_op2);
    node_13->add_out_arc(arc_13_16);
    node_16->add_in_arc(arc_12_16_op1);
    node_16->add_in_arc(arc_12_16_op2);
    node_16->add_in_arc(arc_13_16);
    graph->add_node(node_16);

    graph->add_new_layer();
    Node<vector<int>>* node_17 = new Node<vector<int>>(17, {});
    Arc<vector<int>>* arc_15_17 = new Arc(node_15, node_17, 1, "x_6");
    Arc<vector<int>>* arc_16_17_op1 = new Arc(node_16, node_17, 0, "x_6");
    Arc<vector<int>>* arc_16_17_op2 = new Arc(node_16, node_17, 1, "x_6");
    node_15->add_out_arc(arc_15_17);
    node_16->add_out_arc(arc_16_17_op1);
    node_16->add_out_arc(arc_16_17_op2);
    node_17->add_in_arc(arc_15_17);
    node_17->add_in_arc(arc_16_17_op1);
    node_17->add_in_arc(arc_16_17_op2);
    graph->add_node(node_17);

    return *graph;
}

Graph<vector<int>> GetReduceDDSetCovering() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {1, 2, 3});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {3});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {1, 2, 3});
    Arc<vector<int>>* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);

    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {2});
    Arc<vector<int>>* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {3});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 0, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {});
    Arc<vector<int>>* arc_2_6 = new Arc(node_2, node_6, 1, "x_2");
    node_2->add_out_arc(arc_2_6);
    node_6->add_in_arc(arc_2_6);
    graph->add_node(node_6);

    graph->add_new_layer();
    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {2, 3});
    Arc<vector<int>>* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);
    graph->add_node(node_7);

    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {2});
    Arc<vector<int>>* arc_4_8_op1 = new Arc(node_4, node_8, 0, "x_3");
    Arc<vector<int>>* arc_4_8_op2 = new Arc(node_4, node_8, 1, "x_3");
    node_4->add_out_arc(arc_4_8_op1);
    node_4->add_out_arc(arc_4_8_op2);
    node_8->add_in_arc(arc_4_8_op1);
    node_8->add_in_arc(arc_4_8_op2);
    graph->add_node(node_8);

    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {3});
    Arc<vector<int>>* arc_5_9_op1 = new Arc(node_5, node_9, 0, "x_3");
    Arc<vector<int>>* arc_5_9_op2 = new Arc(node_5, node_9, 1, "x_3");
    node_5->add_out_arc(arc_5_9_op1);
    node_5->add_out_arc(arc_5_9_op2);
    node_9->add_in_arc(arc_5_9_op1);
    node_9->add_in_arc(arc_5_9_op2);
    graph->add_node(node_9);

    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_6_10_op1 = new Arc(node_6, node_10, 0, "x_3");
    Arc<vector<int>>* arc_6_10_op2 = new Arc(node_6, node_10, 1, "x_3");
    node_6->add_out_arc(arc_6_10_op1);
    node_6->add_out_arc(arc_6_10_op2);
    node_10->add_in_arc(arc_6_10_op1);
    node_10->add_in_arc(arc_6_10_op2);
    graph->add_node(node_10);

    graph->add_new_layer();

    Node<vector<int>>* node_11 = new Node<vector<int>>(11, {2, 3});
    Arc<vector<int>>* arc_7_11 = new Arc(node_7, node_11, 0, "x_4");
    node_7->add_out_arc(arc_7_11);
    node_11->add_in_arc(arc_7_11);
    graph->add_node(node_11);

    Node<vector<int>>* node_12 = new Node<vector<int>>(12, {});
    Arc<vector<int>>* arc_7_12 = new Arc(node_7, node_12, 1, "x_4");
    Arc<vector<int>>* arc_8_12 = new Arc(node_8, node_12, 1, "x_4");
    Arc<vector<int>>* arc_9_12 = new Arc(node_9, node_12, 1, "x_4");
    Arc<vector<int>>* arc_10_12_op1 = new Arc(node_10, node_12, 0, "x_4");
    Arc<vector<int>>* arc_10_12_op2 = new Arc(node_10, node_12, 1, "x_4");
    node_7->add_out_arc(arc_7_12);
    node_8->add_out_arc(arc_8_12);
    node_9->add_out_arc(arc_9_12);
    node_10->add_out_arc(arc_10_12_op1);
    node_10->add_out_arc(arc_10_12_op2);
    node_12->add_in_arc(arc_7_12);
    node_12->add_in_arc(arc_8_12);
    node_12->add_in_arc(arc_9_12);
    node_12->add_in_arc(arc_10_12_op1);
    node_12->add_in_arc(arc_10_12_op2);
    graph->add_node(node_12);

    Node<vector<int>>* node_13 = new Node<vector<int>>(13, {2});
    Arc<vector<int>>* arc_8_13 = new Arc(node_8, node_13, 0, "x_4");
    node_8->add_out_arc(arc_8_13);
    node_13->add_in_arc(arc_8_13);
    graph->add_node(node_13);

    Node<vector<int>>* node_14 = new Node<vector<int>>(14, {3});
    Arc<vector<int>>* arc_9_14 = new Arc(node_9, node_14, 0, "x_4");
    node_9->add_out_arc(arc_9_14);
    node_14->add_in_arc(arc_9_14);
    graph->add_node(node_14);

    graph->add_new_layer();
    Node<vector<int>>* node_15 = new Node<vector<int>>(15, {3});
    Arc<vector<int>>* arc_11_15 = new Arc(node_11, node_15, 1, "x_5");
    Arc<vector<int>>* arc_14_15_op1 = new Arc(node_14, node_15, 1, "x_5");
    Arc<vector<int>>* arc_14_15_op2 = new Arc(node_14, node_15, 0, "x_5");
    node_11->add_out_arc(arc_11_15);
    node_14->add_out_arc(arc_14_15_op1);
    node_14->add_out_arc(arc_14_15_op2);
    node_15->add_in_arc(arc_11_15);
    node_15->add_in_arc(arc_14_15_op1);
    node_15->add_in_arc(arc_14_15_op2);
    graph->add_node(node_15);

    Node<vector<int>>* node_16 = new Node<vector<int>>(16, {});
    Arc<vector<int>>* arc_12_16_op1 = new Arc(node_12, node_16, 0, "x_5");
    Arc<vector<int>>* arc_12_16_op2 = new Arc(node_12, node_16, 1, "x_5");
    Arc<vector<int>>* arc_13_16 = new Arc(node_13, node_16, 1, "x_5");
    node_12->add_out_arc(arc_12_16_op1);
    node_12->add_out_arc(arc_12_16_op2);
    node_13->add_out_arc(arc_13_16);
    node_16->add_in_arc(arc_12_16_op1);
    node_16->add_in_arc(arc_12_16_op2);
    node_16->add_in_arc(arc_13_16);
    graph->add_node(node_16);

    graph->add_new_layer();
    Node<vector<int>>* node_17 = new Node<vector<int>>(17, {});
    Arc<vector<int>>* arc_15_17 = new Arc(node_15, node_17, 1, "x_6");
    Arc<vector<int>>* arc_16_17_op1 = new Arc(node_16, node_17, 0, "x_6");
    Arc<vector<int>>* arc_16_17_op2 = new Arc(node_16, node_17, 1, "x_6");
    node_15->add_out_arc(arc_15_17);
    node_16->add_out_arc(arc_16_17_op1);
    node_16->add_out_arc(arc_16_17_op2);
    node_17->add_in_arc(arc_15_17);
    node_17->add_in_arc(arc_16_17_op1);
    node_17->add_in_arc(arc_16_17_op2);
    graph->add_node(node_17);

    return *graph;
}

Graph<vector<int>> GetRestrictedDDSetCovering() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {1, 2, 3});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {3});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {2});
    Arc<vector<int>>* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);

    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {3});
    Arc<vector<int>>* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 1, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {2});
    Arc<vector<int>>* arc_3_6_op1 = new Arc(node_3, node_6, 0, "x_3");
    Arc<vector<int>>* arc_3_6_op2 = new Arc(node_3, node_6, 1, "x_3");
    node_3->add_out_arc(arc_3_6_op1);
    node_3->add_out_arc(arc_3_6_op2);
    node_6->add_in_arc(arc_3_6_op1);
    node_6->add_in_arc(arc_3_6_op2);
    graph->add_node(node_6);

    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {3});
    Arc<vector<int>>* arc_4_7_op1 = new Arc(node_4, node_7, 0, "x_3");
    Arc<vector<int>>* arc_4_7_op2 = new Arc(node_4, node_7, 1, "x_3");
    node_4->add_out_arc(arc_4_7_op1);
    node_4->add_out_arc(arc_4_7_op2);
    node_7->add_in_arc(arc_4_7_op1);
    node_7->add_in_arc(arc_4_7_op2);
    graph->add_node(node_7);

    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {});
    Arc<vector<int>>* arc_5_8_op1 = new Arc(node_5, node_8, 0, "x_3");
    Arc<vector<int>>* arc_5_8_op2 = new Arc(node_5, node_8, 1, "x_3");
    node_5->add_out_arc(arc_5_8_op1);
    node_5->add_out_arc(arc_5_8_op2);
    node_8->add_in_arc(arc_5_8_op1);
    node_8->add_in_arc(arc_5_8_op2);
    graph->add_node(node_8);

    graph->add_new_layer();
    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {2});
    Arc<vector<int>>* arc_6_9 = new Arc(node_6, node_9, 0, "x_3");
    node_6->add_out_arc(arc_6_9);
    node_9->add_in_arc(arc_6_9);
    graph->add_node(node_9);

    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_6_10 = new Arc(node_6, node_10, 1, "x_3");
    Arc<vector<int>>* arc_7_10 = new Arc(node_7, node_10, 1, "x_3");
    Arc<vector<int>>* arc_8_10_op1 = new Arc(node_8, node_10, 0, "x_3");
    Arc<vector<int>>* arc_8_10_op2 = new Arc(node_8, node_10, 1, "x_3");
    node_6->add_out_arc(arc_6_10);
    node_7->add_out_arc(arc_7_10);
    node_8->add_out_arc(arc_8_10_op1);
    node_8->add_out_arc(arc_8_10_op2);
    node_10->add_in_arc(arc_6_10);
    node_10->add_in_arc(arc_7_10);
    node_10->add_in_arc(arc_8_10_op1);
    node_10->add_in_arc(arc_8_10_op2);
    graph->add_node(node_10);

    Node<vector<int>>* node_11 = new Node<vector<int>>(11, {3});
    Arc<vector<int>>* arc_7_11 = new Arc(node_7, node_11, 0, "x_3");
    node_7->add_out_arc(arc_7_11);
    node_11->add_in_arc(arc_7_11);
    graph->add_node(node_11);

    graph->add_new_layer();
    Node<vector<int>>* node_12 = new Node<vector<int>>(12, {});
    Arc<vector<int>>* arc_9_12 = new Arc(node_9, node_12, 1, "x_3");
    Arc<vector<int>>* arc_10_12_op1 = new Arc(node_10, node_12, 0, "x_3");
    Arc<vector<int>>* arc_10_12_op2 = new Arc(node_10, node_12, 1, "x_3");
    node_9->add_out_arc(arc_9_12);
    node_10->add_out_arc(arc_10_12_op1);
    node_10->add_out_arc(arc_10_12_op2);
    node_12->add_in_arc(arc_9_12);
    node_12->add_in_arc(arc_10_12_op1);
    node_12->add_in_arc(arc_10_12_op2);
    graph->add_node(node_12);

    Node<vector<int>>* node_13 = new Node<vector<int>>(13, {3});
    Arc<vector<int>>* arc_11_13_op1 = new Arc(node_11, node_13, 0, "x_3");
    Arc<vector<int>>* arc_11_13_op2 = new Arc(node_11, node_13, 1, "x_3");
    node_11->add_out_arc(arc_11_13_op1);
    node_11->add_out_arc(arc_11_13_op2);
    node_13->add_in_arc(arc_11_13_op1);
    node_13->add_in_arc(arc_11_13_op2);
    graph->add_node(node_13);

    graph->add_new_layer();
    Node<vector<int>>* node_14 = new Node<vector<int>>(14, {});
    Arc<vector<int>>* arc_12_14_op1 = new Arc(node_12, node_14, 0, "x_6");
    Arc<vector<int>>* arc_12_14_op2 = new Arc(node_12, node_14, 1, "x_6");
    Arc<vector<int>>* arc_13_14 = new Arc(node_13, node_14, 1, "x_6");
    node_12->add_out_arc(arc_12_14_op1);
    node_12->add_out_arc(arc_12_14_op2);
    node_13->add_out_arc(arc_13_14);
    node_14->add_in_arc(arc_12_14_op1);
    node_14->add_in_arc(arc_12_14_op2);
    node_14->add_in_arc(arc_13_14);
    graph->add_node(node_14);

    return *graph;
}

Graph<vector<int>> GetRelaxedDDSetCovering() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3});
    Graph<vector<int>>* graph = new Graph(node_0);

    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {1, 2, 3});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {3});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {2});
    Arc<vector<int>>* arc_1_3_op1 = new Arc(node_1, node_3, 0, "x_2");
    Arc<vector<int>>* arc_1_3_op2 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3_op1);
    node_1->add_out_arc(arc_1_3_op2);
    node_3->add_in_arc(arc_1_3_op1);
    node_3->add_in_arc(arc_1_3_op2);
    graph->add_node(node_3);

    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {3});
    Arc<vector<int>>* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 1, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {2});
    Arc<vector<int>>* arc_3_6_op1 = new Arc(node_3, node_6, 0, "x_3");
    Arc<vector<int>>* arc_3_6_op2 = new Arc(node_3, node_6, 1, "x_3");
    node_3->add_out_arc(arc_3_6_op1);
    node_3->add_out_arc(arc_3_6_op2);
    node_6->add_in_arc(arc_3_6_op1);
    node_6->add_in_arc(arc_3_6_op2);
    graph->add_node(node_6);

    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {3});
    Arc<vector<int>>* arc_4_7_op1 = new Arc(node_4, node_7, 0, "x_3");
    Arc<vector<int>>* arc_4_7_op2 = new Arc(node_4, node_7, 1, "x_3");
    node_4->add_out_arc(arc_4_7_op1);
    node_4->add_out_arc(arc_4_7_op2);
    node_7->add_in_arc(arc_4_7_op1);
    node_7->add_in_arc(arc_4_7_op2);
    graph->add_node(node_7);

    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {});
    Arc<vector<int>>* arc_5_8_op1 = new Arc(node_5, node_8, 0, "x_3");
    Arc<vector<int>>* arc_5_8_op2 = new Arc(node_5, node_8, 1, "x_3");
    node_5->add_out_arc(arc_5_8_op1);
    node_5->add_out_arc(arc_5_8_op2);
    node_8->add_in_arc(arc_5_8_op1);
    node_8->add_in_arc(arc_5_8_op2);
    graph->add_node(node_8);

    graph->add_new_layer();
    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {2});
    Arc<vector<int>>* arc_6_9 = new Arc(node_6, node_9, 0, "x_3");
    node_6->add_out_arc(arc_6_9);
    node_9->add_in_arc(arc_6_9);
    graph->add_node(node_9);

    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_6_10 = new Arc(node_6, node_10, 1, "x_3");
    Arc<vector<int>>* arc_7_10 = new Arc(node_7, node_10, 1, "x_3");
    Arc<vector<int>>* arc_8_10_op1 = new Arc(node_8, node_10, 0, "x_3");
    Arc<vector<int>>* arc_8_10_op2 = new Arc(node_8, node_10, 1, "x_3");
    node_6->add_out_arc(arc_6_10);
    node_7->add_out_arc(arc_7_10);
    node_8->add_out_arc(arc_8_10_op1);
    node_8->add_out_arc(arc_8_10_op2);
    node_10->add_in_arc(arc_6_10);
    node_10->add_in_arc(arc_7_10);
    node_10->add_in_arc(arc_8_10_op1);
    node_10->add_in_arc(arc_8_10_op2);
    graph->add_node(node_10);

    Node<vector<int>>* node_11 = new Node<vector<int>>(11, {3});
    Arc<vector<int>>* arc_7_11 = new Arc(node_7, node_11, 0, "x_3");
    node_7->add_out_arc(arc_7_11);
    node_11->add_in_arc(arc_7_11);
    graph->add_node(node_11);

    graph->add_new_layer();
    Node<vector<int>>* node_12 = new Node<vector<int>>(12, {});
    Arc<vector<int>>* arc_9_12 = new Arc(node_9, node_12, 1, "x_3");
    Arc<vector<int>>* arc_10_12_op1 = new Arc(node_10, node_12, 0, "x_3");
    Arc<vector<int>>* arc_10_12_op2 = new Arc(node_10, node_12, 1, "x_3");
    node_9->add_out_arc(arc_9_12);
    node_10->add_out_arc(arc_10_12_op1);
    node_10->add_out_arc(arc_10_12_op2);
    node_12->add_in_arc(arc_9_12);
    node_12->add_in_arc(arc_10_12_op1);
    node_12->add_in_arc(arc_10_12_op2);
    graph->add_node(node_12);

    Node<vector<int>>* node_13 = new Node<vector<int>>(13, {3});
    Arc<vector<int>>* arc_11_13_op1 = new Arc(node_11, node_13, 0, "x_3");
    Arc<vector<int>>* arc_11_13_op2 = new Arc(node_11, node_13, 1, "x_3");
    node_11->add_out_arc(arc_11_13_op1);
    node_11->add_out_arc(arc_11_13_op2);
    node_13->add_in_arc(arc_11_13_op1);
    node_13->add_in_arc(arc_11_13_op2);
    graph->add_node(node_13);

    graph->add_new_layer();
    Node<vector<int>>* node_14 = new Node<vector<int>>(14, {});
    Arc<vector<int>>* arc_12_14_op1 = new Arc(node_12, node_14, 0, "x_6");
    Arc<vector<int>>* arc_12_14_op2 = new Arc(node_12, node_14, 1, "x_6");
    Arc<vector<int>>* arc_13_14 = new Arc(node_13, node_14, 1, "x_6");
    node_12->add_out_arc(arc_12_14_op1);
    node_12->add_out_arc(arc_12_14_op2);
    node_13->add_out_arc(arc_13_14);
    node_14->add_in_arc(arc_12_14_op1);
    node_14->add_in_arc(arc_12_14_op2);
    node_14->add_in_arc(arc_13_14);
    graph->add_node(node_14);

    return *graph;
}

Graph<vector<int>> GetFalseDDSetCovering() {
    Node<vector<int>>* node_0 = new Node<vector<int>>(0, {1, 2, 3, 4});
    Graph<vector<int>>* graph = new Graph(node_0);


    graph->add_new_layer();
    Node<vector<int>>* node_1 = new Node<vector<int>>(1, {1, 2, 3});
    Arc<vector<int>>* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node<vector<int>>* node_2 = new Node<vector<int>>(2, {3});
    Arc<vector<int>>* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node<vector<int>>* node_3 = new Node<vector<int>>(3, {1, 2, 3});
    Arc<vector<int>>* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);

    Node<vector<int>>* node_4 = new Node<vector<int>>(4, {2});
    Arc<vector<int>>* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    graph->add_node(node_4);

    Node<vector<int>>* node_5 = new Node<vector<int>>(5, {3});
    Arc<vector<int>>* arc_2_5 = new Arc(node_2, node_5, 0, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    Node<vector<int>>* node_6 = new Node<vector<int>>(6, {});
    Arc<vector<int>>* arc_2_6 = new Arc(node_2, node_6, 1, "x_2");
    node_2->add_out_arc(arc_2_6);
    node_6->add_in_arc(arc_2_6);
    graph->add_node(node_6);

    graph->add_new_layer();
    Node<vector<int>>* node_7 = new Node<vector<int>>(7, {2, 3});
    Arc<vector<int>>* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);
    graph->add_node(node_7);

    Node<vector<int>>* node_8 = new Node<vector<int>>(8, {2});
    Arc<vector<int>>* arc_4_8_op1 = new Arc(node_4, node_8, 0, "x_3");
    Arc<vector<int>>* arc_4_8_op2 = new Arc(node_4, node_8, 1, "x_3");
    node_4->add_out_arc(arc_4_8_op1);
    node_4->add_out_arc(arc_4_8_op2);
    node_8->add_in_arc(arc_4_8_op1);
    node_8->add_in_arc(arc_4_8_op2);
    graph->add_node(node_8);

    Node<vector<int>>* node_9 = new Node<vector<int>>(9, {3});
    Arc<vector<int>>* arc_5_9_op1 = new Arc(node_5, node_9, 0, "x_3");
    Arc<vector<int>>* arc_5_9_op2 = new Arc(node_5, node_9, 1, "x_3");
    node_5->add_out_arc(arc_5_9_op1);
    node_5->add_out_arc(arc_5_9_op2);
    node_9->add_in_arc(arc_5_9_op1);
    node_9->add_in_arc(arc_5_9_op2);
    graph->add_node(node_9);

    Node<vector<int>>* node_10 = new Node<vector<int>>(10, {});
    Arc<vector<int>>* arc_6_10_op1 = new Arc(node_6, node_10, 0, "x_3");
    Arc<vector<int>>* arc_6_10_op2 = new Arc(node_6, node_10, 1, "x_3");
    node_6->add_out_arc(arc_6_10_op1);
    node_6->add_out_arc(arc_6_10_op2);
    node_10->add_in_arc(arc_6_10_op1);
    node_10->add_in_arc(arc_6_10_op2);
    graph->add_node(node_10);

    graph->add_new_layer();

    Node<vector<int>>* node_11 = new Node<vector<int>>(11, {2, 3});
    Arc<vector<int>>* arc_7_11 = new Arc(node_7, node_11, 0, "x_3");
    node_7->add_out_arc(arc_7_11);
    node_11->add_in_arc(arc_7_11);
    graph->add_node(node_11);

    Node<vector<int>>* node_12 = new Node<vector<int>>(12, {});
    Arc<vector<int>>* arc_7_12 = new Arc(node_7, node_12, 1, "x_4");
    Arc<vector<int>>* arc_8_12 = new Arc(node_8, node_12, 1, "x_4");
    Arc<vector<int>>* arc_9_12 = new Arc(node_9, node_12, 1, "x_4");
    Arc<vector<int>>* arc_10_12_op1 = new Arc(node_10, node_12, 0, "x_4");
    Arc<vector<int>>* arc_10_12_op2 = new Arc(node_10, node_12, 1, "x_4");
    node_7->add_out_arc(arc_7_12);
    node_8->add_out_arc(arc_8_12);
    node_9->add_out_arc(arc_9_12);
    node_10->add_out_arc(arc_10_12_op1);
    node_10->add_out_arc(arc_10_12_op2);
    node_12->add_in_arc(arc_7_12);
    node_12->add_in_arc(arc_8_12);
    node_12->add_in_arc(arc_9_12);
    node_12->add_in_arc(arc_10_12_op1);
    node_12->add_in_arc(arc_10_12_op2);
    graph->add_node(node_12);

    Node<vector<int>>* node_13 = new Node<vector<int>>(13, {2});
    Arc<vector<int>>* arc_8_13 = new Arc(node_8, node_13, 0, "x_4");
    node_8->add_out_arc(arc_8_13);
    node_13->add_in_arc(arc_8_13);
    graph->add_node(node_13);

    Node<vector<int>>* node_14 = new Node<vector<int>>(14, {3});
    Arc<vector<int>>* arc_9_14 = new Arc(node_9, node_14, 0, "x_4");
    node_9->add_out_arc(arc_9_14);
    node_14->add_in_arc(arc_9_14);
    graph->add_node(node_14);

    graph->add_new_layer();
    Node<vector<int>>* node_15 = new Node<vector<int>>(15, {3});
    Arc<vector<int>>* arc_11_15 = new Arc(node_11, node_15, 1, "x_5");
    Arc<vector<int>>* arc_14_15_op1 = new Arc(node_14, node_15, 1, "x_5");
    Arc<vector<int>>* arc_14_15_op2 = new Arc(node_14, node_15, 0, "x_5");
    node_11->add_out_arc(arc_11_15);
    node_14->add_out_arc(arc_14_15_op1);
    node_14->add_out_arc(arc_14_15_op2);
    node_15->add_in_arc(arc_11_15);
    node_15->add_in_arc(arc_14_15_op1);
    node_15->add_in_arc(arc_14_15_op2);
    graph->add_node(node_15);

    Node<vector<int>>* node_16 = new Node<vector<int>>(16, {});
    Arc<vector<int>>* arc_12_16_op1 = new Arc(node_12, node_16, 0, "x_5");
    Arc<vector<int>>* arc_12_16_op2 = new Arc(node_12, node_16, 1, "x_5");
    Arc<vector<int>>* arc_13_16 = new Arc(node_13, node_16, 1, "x_5");
    node_12->add_out_arc(arc_12_16_op1);
    node_12->add_out_arc(arc_12_16_op2);
    node_13->add_out_arc(arc_13_16);
    node_16->add_in_arc(arc_12_16_op1);
    node_16->add_in_arc(arc_12_16_op2);
    node_16->add_in_arc(arc_13_16);
    graph->add_node(node_16);

    graph->add_new_layer();
    Node<vector<int>>* node_17 = new Node<vector<int>>(17, {});
    Arc<vector<int>>* arc_15_17 = new Arc(node_15, node_17, 1, "x_6");
    Arc<vector<int>>* arc_16_17_op1 = new Arc(node_16, node_17, 0, "x_6");
    Arc<vector<int>>* arc_16_17_op2 = new Arc(node_16, node_17, 1, "x_6");
    node_15->add_out_arc(arc_15_17);
    node_16->add_out_arc(arc_16_17_op1);
    node_16->add_out_arc(arc_16_17_op2);
    node_17->add_in_arc(arc_15_17);
    node_17->add_in_arc(arc_16_17_op1);
    node_17->add_in_arc(arc_16_17_op2);
    graph->add_node(node_17);

    return *graph;
}
