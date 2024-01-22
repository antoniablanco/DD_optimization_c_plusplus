
#include "Node.h"
#include "Arc.h"
#include "Graph.h"

using namespace std;

int main() {

    Node node_0(0, {0});
    Graph graph(node_0);

    graph.add_new_layer();
    Node node_1 = Node(1, {0});
    Arc arc_0_1 = Arc(node_0, node_1, 0, "x_1");
    node_0.add_out_arc(arc_0_1);
    node_1.add_in_arc(arc_0_1);

    graph.add_node(node_1);
    Node node_2 = Node(2, {3});
    Arc arc_0_2 = Arc(node_0, node_2, 1, "x_1");
    node_0.add_out_arc(arc_0_2);
    node_2.add_in_arc(arc_0_2);
    graph.add_node(node_2);

    graph.add_new_layer();
    Node node_3 = Node(3, {0});
    Arc arc_1_3 = Arc(node_1, node_3, 0, "x_2");
    node_1.add_out_arc(arc_1_3);
    node_3.add_in_arc(arc_1_3);

    graph.add_node(node_3);
    Node node_4 = Node(4, {3});
    Arc arc_1_4 = Arc(node_1, node_4, 1, "x_2");
    node_1.add_out_arc(arc_1_4);
    node_4.add_in_arc(arc_1_4);
    Arc arc_2_4 = Arc(node_2, node_4, 0, "x_2");
    node_2.add_out_arc(arc_2_4);
    node_4.add_in_arc(arc_2_4);

    graph.add_node(node_4);
    Node node_5 = Node(5, {6});
    Arc arc_2_5 = Arc(node_2, node_5, 1, "x_2");
    node_2.add_out_arc(arc_2_5);
    node_5.add_in_arc(arc_2_5);
    graph.add_node(node_5);

    return 0;
}