#include "ReduceDDBuilder.h"

using namespace std;

template <typename T>
ReduceDDBuilder<T>::ReduceDDBuilder(Graph<T>* graph, AbstractProblem<T>& problem) :
    graph(graph),
    layer_working(graph->actual_layer),
    problem(problem){}

template <typename T>
Graph<T> ReduceDDBuilder<T>::GetDecisionDiagram(bool should_visualize) {
    auto reversedStructure = graph->structure;
    reverse(reversedStructure.begin(), reversedStructure.end());

    for (const auto& layer : reversedStructure) {
        print_graph(should_visualize);
        reviewing_layer(layer);
        graph->remove_not_active_nodes(layer_working);
        layer_working -=1;
    }

    specific_final_function();
    print_graph(should_visualize);

    return *graph;
}

template <typename T>
void ReduceDDBuilder<T>::reviewing_layer(vector<Node<T>*> layer) {
    map<vector<string>, Node<T>*> map_of_paths;
    auto it = layer.begin();
    while (it != layer.end()) {
        Node<T>* node = *it;
        vector<string> PathsOfNode = get_node_of_every_type_of_path(node);
        if (map_of_paths.count(PathsOfNode)) {
            merge_nodes(node, map_of_paths[PathsOfNode]);
        } else {
            map_of_paths[PathsOfNode] = node;
        }
        ++it;
    }
}

template <typename T>
vector<string> ReduceDDBuilder<T>::get_node_of_every_type_of_path(Node<T>* node) {
    vector<string> nodesOfPath = {};
    nodesOfPath.reserve(node->out_arcs.size());
    for (Arc<T>* arc : node->out_arcs) {

        string aux = arc->in_node->to_string() + "_" + to_string(arc->variable_value);
        nodesOfPath.push_back(std::move(aux));
    }
    return nodesOfPath;
}

template <typename T>
void ReduceDDBuilder<T>::merge_nodes(Node<T>* node_to_remove, Node<T>* node_to_keep) {
    redirect_in_arcs(node_to_remove, node_to_keep);
    delete_out_arcs(node_to_remove);
    delete_node(node_to_remove);
}

template <typename T>
void ReduceDDBuilder<T>::redirect_in_arcs(Node<T>* node_to_remove, Node<T>* node_to_keep) {
    for (Arc<T>* arc : node_to_remove->in_arcs) {
        arc->in_node = node_to_keep;
        node_to_keep->add_in_arc(arc);
        //if (find(node_to_keep->in_arcs.begin(), node_to_keep->in_arcs.end(), arc) == node_to_keep->in_arcs.end()) {
        //    node_to_keep->add_in_arc(arc);
        //}
    }
    node_to_remove->in_arcs.clear();
}

template <typename T>
void ReduceDDBuilder<T>::delete_out_arcs(Node<T>* node_to_remove) {
    for (auto it = node_to_remove->out_arcs.begin(); it != node_to_remove->out_arcs.end(); ) {
        Arc<T>* arc = *it;
        it = node_to_remove->out_arcs.erase(it);
        arc->in_node->in_arcs.erase(remove(arc->in_node->in_arcs.begin(), arc->in_node->in_arcs.end(), arc), arc->in_node->in_arcs.end());
        delete arc;
    }
}

template <typename T>
void ReduceDDBuilder<T>::delete_node(Node<T>* node_to_remove) const {
    node_to_remove->is_active = false;
}

template <typename T>
void ReduceDDBuilder<T>::specific_final_function() {
    adjust_node_number();
}

template <typename T>
void ReduceDDBuilder<T>::adjust_node_number() const {
    int initial_node_number = 0;
    for (const vector<Node<T>*>& layer : graph->structure) {
        for (Node<T>* node : layer) {
            node->set_id(initial_node_number);
            initial_node_number++;
        }
    }
}

template <typename T>
void ReduceDDBuilder<T>::print_graph(bool should_visualize) {
    if (should_visualize) {
        print();
    }
}

template <typename T>
void ReduceDDBuilder<T>::print() const {

    cout << "" << endl;
    for (const auto& layer : graph->structure) {
        cout << "------------------------------------------------------" << endl;
        for (auto& node : layer) {
            string in_arcs_str;
            for (const auto& arc : node->in_arcs) {
                in_arcs_str += arc->to_string() + " ";
            }
            in_arcs_str = in_arcs_str.empty() ? "" : in_arcs_str.substr(0, in_arcs_str.size() - 1);
            cout << node->to_string() << problem.get_state_as_string(node->state) << "(" << in_arcs_str << ") ";
        }
        cout << "" << endl;
    }
}
