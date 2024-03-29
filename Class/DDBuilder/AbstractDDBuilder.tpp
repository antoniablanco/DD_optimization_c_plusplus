
#include "AbstractDDBuilder.h"

template <typename T>
AbstractDDBuilder<T>::AbstractDDBuilder(AbstractProblem<T>& problem) :
        problem(problem),
        node_number(1),
        variables(problem.ordered_variables),
        variables_domain(problem.variables_domain),
        graph()
{
    Node<T>* node_root = new Node(0, problem.initial_state);
    graph = new Graph(node_root);
    graph->structure.reserve(variables.size());
}

template <typename T>
Graph<T>* AbstractDDBuilder<T>::getDecisionDiagram(bool should_visualize) {

    for (size_t variable_id = 0; variable_id < variables.size(); ++variable_id) {
        create_new_layer(variable_id);
        specificLayerFunction();
        print_graph(should_visualize);
    }

    specific_final_function();
    print_graph(should_visualize);

    return graph;
}

template <typename T>
void AbstractDDBuilder<T>::create_new_layer(int variable_id) {
    graph->add_new_layer();

    create_new_nodes_in_the_new_layer(variable_id);
}

template <typename T>
void AbstractDDBuilder<T>::create_new_nodes_in_the_new_layer(int variable_id) {
    size_t last_layer_index = graph->structure.size() - 2;
    graph->structure.back().reserve(variables_domain[variables[variable_id]].size());
    map_of_states = std::map<string, Node<T>*>();

    for (Node<T>* pExistedNode : graph->structure[last_layer_index]) {
        if (pExistedNode) {
            for (int variable_value : variables_domain[variables[variable_id]]) {

                auto result = problem.transition_function(pExistedNode->state, variables[variable_id], variable_value);
                T node_state = result.first;
                bool isFeasible = result.second;

                if (isFeasible)
                {
                    create_new_node(variable_id, variable_value, pExistedNode, &node_state);
                }
            }
        }
    }
}

template <typename T>
void AbstractDDBuilder<T>::create_new_node(int variable_id, int variable_value, Node<T>* pExistedNode, T* node_state){
    if (there_is_node_in_last_layer(variable_id)) {
        create_arcs_for_the_terminal_node(variable_value, pExistedNode, variable_id);
    } else {
        string state_as_string = problem.get_state_as_string(*node_state);
        if (map_of_states.count(state_as_string )) {
            create_arc_for_the_new_node(pExistedNode, map_of_states[state_as_string], variable_value, variable_id);
        } else {
            Node<T> *new_node = new Node(node_number, *node_state);
            map_of_states[state_as_string] = new_node;

            create_arc_for_the_new_node(pExistedNode, new_node, variable_value, variable_id);
            graph->add_node(new_node);
            node_number++;
        }
    }
}

template <typename T>
bool AbstractDDBuilder<T>::there_is_node_in_last_layer(int variable_id) {
    return variables.back() == variables[variable_id] && !graph->structure.back().empty();
}

template <typename T>
void AbstractDDBuilder<T>::create_arcs_for_the_terminal_node(int variable_value, Node<T> *existed_node, int variable_id) {
    Node<T>& same_state_node = *graph->structure.back().back();
    create_arc_for_the_new_node(existed_node, &same_state_node, variable_value, variable_id);
}

template <typename T>
void AbstractDDBuilder<T>::create_arc_for_the_new_node(Node<T>* existed_node, Node<T>* node_created, int variable_value, int variable_id) {
    Arc<T>* arc = new Arc(existed_node, node_created, variable_value, variables[variable_id]);

    existed_node->add_out_arc(arc);
    node_created->add_in_arc(arc);
}

template <typename T>
void AbstractDDBuilder<T>::print_graph(bool should_visualize) {
    if (should_visualize) {
        print();
    }
}

template <typename T>
void AbstractDDBuilder<T>::print() {

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

template <typename T>
pair<bool, Node<T>*> AbstractDDBuilder<T>::exist_node_with_same_state(T* node_state) {

    for (const auto& pNode : graph->structure.back()) {
        if (problem.equals(pNode->state, *node_state)) {
            return {true, pNode};
        }
    }
    return {false, nullptr};

}