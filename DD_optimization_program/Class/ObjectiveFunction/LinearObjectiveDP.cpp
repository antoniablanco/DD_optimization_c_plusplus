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
    DP = vector<ObjectiveStruct*>(graph.nodes.size(), nullptr);
    int last_layer_number = graph.structure.size() - 2;
    ObjectiveStruct* objective_answer = dp(*graph.nodes.back(), last_layer_number);

    if (objective == "max"){
        objective_answer->value = -objective_answer->value;
    }

    objective_answer->path = objective_answer->path.substr(2);

    return *objective_answer;
}


ObjectiveStruct* LinearObjectiveDP::dp(const Node& node, int layer) {

    if (node.in_arcs.empty()) {
        return new ObjectiveStruct(0, "", {});
    }

    DP[node.id] = new ObjectiveStruct(numeric_limits<int>::max(), "", {});
    for (auto& arc : node.in_arcs) {
        if (DP[arc->out_node->id] == nullptr) {
            DP[arc->out_node->id] = dp(*arc->out_node, layer - 1);
        }

        ObjectiveStruct* subResult = DP[arc->out_node->id];
        if (DP[node.id]->value > subResult->value + arc->variable_value * weights[layer]) {
            DP[node.id]->value = subResult->value + arc->variable_value * weights[layer];
            DP[node.id]->path = subResult->path + "-> " + arc->to_string() + "(" + to_string(arc->variable_value) + ")";
            DP[node.id]->arcs.assign(subResult->arcs.begin(), subResult->arcs.end());
            DP[node.id]->arcs.push_back(arc);
        }
    }

    return DP[node.id];
}
