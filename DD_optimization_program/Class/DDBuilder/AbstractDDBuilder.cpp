
#include "AbstractDDBuilder.h"


AbstractDDBuilder::AbstractDDBuilder(AbstractProblem& problem) : 
    problem(problem),
    node_number(1),
    variables(problem.ordered_variables),
    variables_domain(problem.variables_domain),
    graph()
    {   
        Node* node_root = new Node(0, problem.initial_state);
        graph = new Graph(node_root);
    }
    

Graph* AbstractDDBuilder::getDecisionDiagram(bool should_visualize) {
        
    for (size_t variable_id = 0; variable_id < variables.size(); ++variable_id) {
        create_new_layer(variable_id);
        specificLayerFunction();
        print_graph(should_visualize);
    }
 
    specific_final_function();
    print_graph(should_visualize);

    return graph;
}

void AbstractDDBuilder::create_new_layer(int variable_id) {
    graph->add_new_layer();
        
    create_new_nodes_in_the_new_layer(variable_id);
}

void AbstractDDBuilder::create_new_nodes_in_the_new_layer(int variable_id) {
    size_t last_layer_index = graph->structure.size() - 2;
        
    for (Node* pExistedNode : graph->structure[last_layer_index]) {
        if (pExistedNode) {
            for (int variable_value : variables_domain[variables[variable_id]]) {
                check_if_new_node_should_be_created(variable_value, pExistedNode, variable_id);
            }
        }
    }
}

void AbstractDDBuilder::check_if_new_node_should_be_created(int variable_value, Node* existed_node, int variable_id) {
    auto result = problem.transition_function(existed_node->state, variables[variable_id], variable_value);
    vector<int> node_state = result.first;
    bool isFeasible = result.second;

    if (isFeasible)
    {
        if (there_is_node_in_last_layer(variable_id)) {
            create_arcs_for_the_terminal_node(variable_value, existed_node, variable_id);
        } else {
            create_rest_of_arcs(variable_value, existed_node, variable_id, node_state);
        }
    
    }
}

bool AbstractDDBuilder::there_is_node_in_last_layer(int variable_id) {
    return variables.back() == variables[variable_id] && !graph->structure.back().empty();
}

void AbstractDDBuilder::create_arcs_for_the_terminal_node(int variable_value, Node *existed_node, int variable_id) {
    Node& same_state_node = *graph->structure.back().back();
    create_arc_for_the_new_node(existed_node, &same_state_node, variable_value, variable_id);
}

void AbstractDDBuilder::create_rest_of_arcs(int variable_value, Node *existed_node, int variable_id, vector<int> node_state) {
    auto result = exist_node_with_same_state(node_state);
    bool exist_node = result.first;
    Node* node_created = result.second;

    if (exist_node) {
        create_arc_for_the_new_node(existed_node, node_created, variable_value, variable_id);
    } else {
        Node *new_node = new Node(node_number, node_state);

        create_arc_for_the_new_node(existed_node, new_node, variable_value, variable_id);
        graph->add_node(new_node);
        node_number++;
    }
}

pair<bool, Node*> AbstractDDBuilder::exist_node_with_same_state(vector<int> node_state) {

    for (const auto& pNode : graph->structure.back()) {
        if (problem.equals(pNode->state, node_state)) {
            return {true, pNode};
        }
    }
    return {false, nullptr};
}

void AbstractDDBuilder::create_arc_for_the_new_node(Node* existed_node, Node* node_created, int variable_value, int variable_id) {
    Arc* arc = new Arc(existed_node, node_created, variable_value, variables[variable_id]);

    existed_node->add_out_arc(arc);
    node_created->add_in_arc(arc);
}

void AbstractDDBuilder::print_graph(bool should_visualize) {
    if (should_visualize) {
        print();
    }
}

void AbstractDDBuilder::print() {
    
    cout << "" << endl;
    for (const auto& layer : graph->structure) {
        cout << "------------------------------------------------------" << endl;
        for (auto& node : layer) {
            string in_arcs_str;
            for (const auto& arc : node->in_arcs) {
                in_arcs_str += arc->to_string() + " ";
            }
            in_arcs_str = in_arcs_str.empty() ? "" : in_arcs_str.substr(0, in_arcs_str.size() - 1);
            cout << node->to_string() << "(" << in_arcs_str << ") ";
        }
        cout << "" << endl;
    }
}
