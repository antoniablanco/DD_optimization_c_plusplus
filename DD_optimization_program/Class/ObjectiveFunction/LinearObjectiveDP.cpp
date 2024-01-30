#include "LinearObjectiveDP.h"

LinearObjectiveDP::LinearObjectiveDP(vector<int> weights, string objective) : weights(weights), objective(objective) {
    choose_transform_weights();
}

void LinearObjectiveDP::choose_transform_weights() {
    if (objective == "max") {
        for (auto& weight : weights) {
            weight = -weight;
        }
    }
}

void LinearObjectiveDP::assign_graph(Graph graph_DD) {
    graph = graph_DD;
}

ObjectiveStruct LinearObjectiveDP::resolve_graph() {
    
    ObjectiveStruct* objective_answer = new ObjectiveStruct();
    objective_answer->value = 10;
    objective_answer->path = "u_0_0 -> u_0_1";

    return *objective_answer;
}


/*
ObjectiveStruct LinearObjectiveDP::resolve_graph() {
    DP = vector<ObjectiveStruct>(graph.nodes.size(), ObjectiveStruct());
    int last_layer_number = graph.structure.size() - 2;
    ObjectiveStruct objective_answer = dp(*graph.nodes.back(), last_layer_number);

    if (objective == "max"){
        objective_answer.value = -objective_answer.value;
    }

    objective_answer.path = objective_answer.path.substr(2);

    return objective_answer;
}
*/

ObjectiveStruct LinearObjectiveDP::dp(Node node, int layer) {
    if (node.in_arcs.size() == 0) {
        return ObjectiveStruct();
    }
    
    if (DP[node.id].value != neutro) {
        return DP[node.id];
    }

    DP[node.id].value = numeric_limits<int>::max();

    for (auto& arc : node.in_arcs) {
        if (DP[node.id].value > dp(*arc->out_node, layer - 1).value + arc->variable_value * weights[layer]) {
            DP[node.id].value = dp(*arc->out_node, layer - 1).value + arc->variable_value * weights[layer];
            DP[node.id].path = dp(*arc->out_node, layer - 1).path + "-> " + arc->to_string() + "(" + to_string(arc->variable_value) + ")";
            DP[node.id].arcs.assign(DP[arc->out_node->id].arcs.begin(), DP[arc->out_node->id].arcs.end());
            DP[node.id].arcs.push_back(arc);
        }
    }

    return DP[node.id];
}
