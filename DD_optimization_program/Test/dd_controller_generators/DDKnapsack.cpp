
#include "Node.h"
#include "Arc.h"
#include "Graph.h"

using namespace std;


Graph GetExactDDKnapsack() {
    Node* node_0 = new Node(0, {0});
    Graph* graph = new Graph(node_0);

    graph->add_new_layer();
    Node* node_1 = new Node(1, {0});
    Arc* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);

    graph->add_node(node_1);
    Node* node_2 = new Node(2, {3});
    Arc* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node* node_3 = new Node(3, {0});
    Arc* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);

    graph->add_node(node_3);
    Node* node_4 = new Node(4, {3});
    Arc* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    Arc* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);

    graph->add_node(node_4);
    Node* node_5 = new Node(5, {6});
    Arc* arc_2_5 = new Arc(node_2, node_5, 1, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node* node_6 = new Node(6, {0});
    Arc* arc_3_6 = new Arc(node_3, node_6, 0, "x_3");
    node_3->add_out_arc(arc_3_6);
    node_6->add_in_arc(arc_3_6);

    graph->add_node(node_6);
    Node* node_7 = new Node(7, {4});
    Arc* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);

    graph->add_node(node_7);
    Node* node_8 = new Node(8, {3});
    Arc* arc_4_8 = new Arc(node_4, node_8, 0, "x_3");
    node_4->add_out_arc(arc_4_8);
    node_8->add_in_arc(arc_4_8);

    graph->add_node(node_8);
    Node* node_9 = new Node(9, {6});
    Arc* arc_5_9 = new Arc(node_5, node_9, 0, "x_3");
    node_5->add_out_arc(arc_5_9);
    node_9->add_in_arc(arc_5_9);
    graph->add_node(node_9);


    graph->add_new_layer();
    Node* node_10 = new Node(10, {0});
    Arc* arc_6_10_op1 = new Arc(node_6, node_10, 0, "x_4");
    node_6->add_out_arc(arc_6_10_op1);
    node_10->add_in_arc(arc_6_10_op1);
    Arc* arc_6_10_op2 = new Arc(node_6, node_10, 1, "x_4");
    node_6->add_out_arc(arc_6_10_op2);
    node_10->add_in_arc(arc_6_10_op2);
    Arc* arc_7_10 = new Arc(node_7, node_10, 0, "x_4");
    node_7->add_out_arc(arc_7_10);
    node_10->add_in_arc(arc_7_10);
    Arc* arc_8_10 = new Arc(node_8, node_10, 0, "x_4");
    node_8->add_out_arc(arc_8_10);
    node_10->add_in_arc(arc_8_10);
    Arc* arc_9_10 = new Arc(node_9, node_10, 0, "x_4");
    node_9->add_out_arc(arc_9_10);
    node_10->add_in_arc(arc_9_10);
    graph->add_node(node_10);

    return *graph;
}

Graph GetReduceDDKnapsack() {
    Node* node_0 = new Node(0, {0});
    Graph* graph = new Graph(node_0);

    graph->add_new_layer();
    Node* node_1 = new Node(1, {0});
    Arc* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);
    graph->add_node(node_1);

    Node* node_2 = new Node(2, {3});
    Arc* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node* node_3 = new Node(3, {0});
    Arc* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);

    Node* node_4 = new Node(4, {3});
    Arc* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    Arc* arc_2_4_op1 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4_op1);
    node_4->add_in_arc(arc_2_4_op1);
    Arc* arc_2_4_op2 = new Arc(node_2, node_4, 1, "x_2");
    node_2->add_out_arc(arc_2_4_op2);
    node_4->add_in_arc(arc_2_4_op2);
    graph->add_node(node_4);

    graph->add_new_layer();
    Node* node_5 = new Node(5, {0});
    Arc* arc_3_5 = new Arc(node_3, node_5, 0, "x_3");
    node_3->add_out_arc(arc_3_5);
    node_5->add_in_arc(arc_3_5);
    graph->add_node(node_5);

    Node* node_6 = new Node(6, {4});
    Arc* arc_3_6 = new Arc(node_3, node_6, 1, "x_3");
    node_3->add_out_arc(arc_3_6);
    node_6->add_in_arc(arc_3_6);

    Arc* arc_4_6 = new Arc(node_4, node_6, 0, "x_3");
    node_4->add_out_arc(arc_4_6);
    node_6->add_in_arc(arc_4_6);
    graph->add_node(node_6);

    graph->add_new_layer();
    Node* node_7 = new Node(7, {0});
    Arc* arc_5_7_op1 = new Arc(node_5, node_7, 0, "x_4");
    node_5->add_out_arc(arc_5_7_op1);
    node_7->add_in_arc(arc_5_7_op1);
    Arc* arc_5_7_op2 = new Arc(node_5, node_7, 1, "x_4");
    node_5->add_out_arc(arc_5_7_op2);
    node_7->add_in_arc(arc_5_7_op2);
    Arc* arc_6_7 = new Arc(node_6, node_7, 0, "x_4");
    node_6->add_out_arc(arc_6_7);
    node_7->add_in_arc(arc_6_7);
    graph->add_node(node_7);

    return *graph;
}

Graph GetRestrictedDDKnapsack() {
    Node* node_0 = new Node(0, {0});;
    Graph* graph = new Graph(node_0);;

    graph->add_new_layer();
    Node* node_1 = new Node(1, {0});
    Arc* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);

    graph->add_node(node_1);
    Node* node_2 = new Node(2, {3});
    Arc* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);


    graph->add_new_layer();
    Node* node_3 = new Node(3, {0});
    Arc* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);

    Node* node_4 = new Node(4, {3});
    Arc* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    Arc* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);
    graph->add_node(node_4);

    graph->add_new_layer();
    Node* node_5 = new Node(5, {0});
    Arc* arc_3_5 = new Arc(node_3, node_5, 0, "x_3");
    node_3->add_out_arc(arc_3_5);
    node_5->add_in_arc(arc_3_5);
    graph->add_node(node_5);

    Node* node_6 = new Node(6, {4});
    Arc* arc_3_6 = new Arc(node_3, node_6, 1, "x_3");
    node_3->add_out_arc(arc_3_6);
    node_6->add_in_arc(arc_3_6);
    graph->add_node(node_6);

    Node* node_7 = new Node(7, {3});
    Arc* arc_4_7 = new Arc(node_4, node_7, 0, "x_3");
    node_4->add_out_arc(arc_4_7);
    node_7->add_in_arc(arc_4_7);
    graph->add_node(node_7);


    graph->add_new_layer();
    Node* node_8 = new Node(8, {0});
    Arc* arc_5_8_op1 = new Arc(node_5, node_8, 0, "x_4");
    node_5->add_out_arc(arc_5_8_op1);
    node_8->add_in_arc(arc_5_8_op1);
    Arc* arc_5_8_op2 = new Arc(node_5, node_8, 1, "x_4");
    node_5->add_out_arc(arc_5_8_op2);
    node_8->add_in_arc(arc_5_8_op2);

    Arc* arc_6_8 = new Arc(node_6, node_8, 0, "x_4");
    node_6->add_out_arc(arc_6_8);
    node_8->add_in_arc(arc_6_8);

    Arc* arc_7_8 = new Arc(node_7, node_8, 0, "x_4");
    node_7->add_out_arc(arc_7_8);
    node_8->add_in_arc(arc_7_8);

    graph->add_node(node_8);

    return *graph;
}

Graph GetRelaxedDDKnapsack() {
    Node* node_0 = new Node(0, {0});;
    Graph* graph = new Graph(node_0);;

    graph->add_new_layer();
    Node* node_1 = new Node(1, {0});
    Arc* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");
    node_0->add_out_arc(arc_0_1);
    node_1->add_in_arc(arc_0_1);

    graph->add_node(node_1);
    Node* node_2 = new Node(2, {3});
    Arc* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);


    graph->add_new_layer();
    Node* node_3 = new Node(3, {0});
    Arc* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);
    graph->add_node(node_3);

    Node* node_4 = new Node(4, {3});
    Arc* arc_1_4 =new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    Arc* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);
    graph->add_node(node_4);

    Node* node_5 = new Node(5, {6});
    Arc* arc_2_5 = new Arc(node_2, node_5, 1, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node* node_6 = new Node(6, {4});
    Arc* arc_3_6 = new Arc(node_3, node_6, 1, "x_3");
    node_3->add_out_arc(arc_3_6);
    node_6->add_in_arc(arc_3_6);
    graph->add_node(node_6);

    Node* node_7 = new Node(7, {3});
    Arc* arc_4_7 = new Arc(node_4, node_7, 0, "x_3");
    node_4->add_out_arc(arc_4_7);
    node_7->add_in_arc(arc_4_7);
    graph->add_node(node_7);

    Node* node_8 = new Node(8, {6});
    Arc* arc_5_8 = new Arc(node_5, node_8, 0, "x_3");
    node_5->add_out_arc(arc_5_8);
    node_8->add_in_arc(arc_5_8);
    graph->add_node(node_8);


    graph->add_new_layer();
    Node* node_9 = new Node(9, {4});
    Arc* arc_6_9 = new Arc(node_6, node_9, 0, "x_4");
    node_6->add_out_arc(arc_6_9);
    node_9->add_in_arc(arc_6_9);

    Arc* arc_7_9 = new Arc(node_7, node_9, 0, "x_4");
    node_7->add_out_arc(arc_7_9);
    node_9->add_in_arc(arc_7_9);

    Arc* arc_8_9 = new Arc(node_8, node_9, 0, "x_4");
    node_8->add_out_arc(arc_8_9);
    node_9->add_in_arc(arc_8_9);

    graph->add_node(node_9);


    return *graph;
}

Graph GetFalseDDKnapsack() {
    Node* node_0 = new Node(0, {0});;
    Graph* graph = new Graph(node_0);;

    graph->add_new_layer();;
    Node* node_1 = new Node(1, {0});;
    Arc* arc_0_1 = new Arc(node_0, node_1, 0, "x_1");;
    node_0->add_out_arc(arc_0_1);;
    node_1->add_in_arc(arc_0_1);;

    graph->add_node(node_1);;
    Node* node_2 = new Node(2, {3});;
    Arc* arc_0_2 = new Arc(node_0, node_2, 1, "x_1");;
    node_0->add_out_arc(arc_0_2);
    node_2->add_in_arc(arc_0_2);
    graph->add_node(node_2);

    graph->add_new_layer();
    Node* node_3 = new Node(3, {0});
    Arc* arc_1_3 = new Arc(node_1, node_3, 0, "x_2");
    node_1->add_out_arc(arc_1_3);
    node_3->add_in_arc(arc_1_3);

    graph->add_node(node_3);
    Node* node_4 = new Node(4, {3});
    Arc* arc_1_4 = new Arc(node_1, node_4, 1, "x_2");
    node_1->add_out_arc(arc_1_4);
    node_4->add_in_arc(arc_1_4);
    Arc* arc_2_4 = new Arc(node_2, node_4, 0, "x_2");
    node_2->add_out_arc(arc_2_4);
    node_4->add_in_arc(arc_2_4);

    graph->add_node(node_4);
    Node* node_5 = new Node(5, {6});
    Arc* arc_2_5 = new Arc(node_2, node_5, 1, "x_2");
    node_2->add_out_arc(arc_2_5);
    node_5->add_in_arc(arc_2_5);
    graph->add_node(node_5);

    graph->add_new_layer();
    Node* node_6 = new Node(6, {0});
    Arc* arc_3_6 = new Arc(node_3, node_6, 0, "x_3");
    node_3->add_out_arc(arc_3_6);
    node_6->add_in_arc(arc_3_6);

    graph->add_node(node_6);
    Node* node_7 = new Node(7, {4});
    Arc* arc_3_7 = new Arc(node_3, node_7, 1, "x_3");
    node_3->add_out_arc(arc_3_7);
    node_7->add_in_arc(arc_3_7);

    graph->add_node(node_7);
    Node* node_8 = new Node(8, {3});
    Arc* arc_4_8 = new Arc(node_4, node_8, 0, "x_3");
    node_4->add_out_arc(arc_4_8);
    node_8->add_in_arc(arc_4_8);

    graph->add_node(node_8);
    Node* node_9 = new Node(9, {6});
    Arc* arc_5_9 = new Arc(node_5, node_9, 0, "x_3");
    node_5->add_out_arc(arc_5_9);
    node_9->add_in_arc(arc_5_9);
    graph->add_node(node_9);


    graph->add_new_layer();
    Node* node_10 = new Node(10, {0});
    Arc* arc_6_10_op1 = new Arc(node_6, node_10, 0, "x_4");
    node_6->add_out_arc(arc_6_10_op1);
    node_10->add_in_arc(arc_6_10_op1);
    Arc* arc_6_10_op2 = new Arc(node_6, node_10, 1, "x_4");
    node_6->add_out_arc(arc_6_10_op2);
    node_10->add_in_arc(arc_6_10_op2);
    Arc* arc_7_10 = new Arc(node_7, node_10, 0, "x_4");
    node_7->add_out_arc(arc_7_10);
    node_10->add_in_arc(arc_7_10);
    Arc* arc_8_10 = new Arc(node_8, node_10, 0, "x_4");
    node_8->add_out_arc(arc_8_10);
    node_10->add_in_arc(arc_8_10);
    Arc* arc_9_10 = new Arc(node_9, node_10, 0, "x_4");
    node_9->add_out_arc(arc_9_10);
    node_10->add_in_arc(arc_9_10);
    graph->add_node(node_10);

    graph->add_new_layer();
    Node* node_11 = new Node(11, {6});
    Arc* arc_10_11 = new Arc(node_10, node_11, 0, "x_5");
    node_10->add_out_arc(arc_10_11);
    node_11->add_in_arc(arc_10_11);
    graph->add_node(node_11);

    return *graph;
}