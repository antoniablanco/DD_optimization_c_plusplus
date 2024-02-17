#include "LinearObjectiveDP.h"

template <typename T>
LinearObjectiveDP<T>::LinearObjectiveDP(vector<int> weights, string objective) : weights(weights), objective(objective) {
    choose_transform_weights();
}

template <typename T>
void LinearObjectiveDP<T>::choose_transform_weights() {
    if (objective == "max") {
        for (auto& weight : weights) {
            weight = -weight;
        }
    }
}

template <typename T>
void LinearObjectiveDP<T>::assign_graph(Graph<T> graph_DD) {
    graph = graph_DD;
}

template <typename T>
ObjectiveStruct<T> LinearObjectiveDP<T>::resolve_graph() {
    DP = vector<ObjectiveStruct<T>*>(graph.nodes.size(), nullptr);
    int last_layer_number = graph.structure.size() - 2;
    ObjectiveStruct<T>* objective_answer = dp(*graph.nodes.back(), last_layer_number);

    if (objective == "max"){
        objective_answer->value = -objective_answer->value;
    }

    objective_answer->path = objective_answer->path.substr(2);

    return *objective_answer;
}

template <typename T>
ObjectiveStruct<T>* LinearObjectiveDP<T>::dp(const Node<T>& node, int layer) {

    if (node.in_arcs.empty()) {
        return new ObjectiveStruct<T>(0, "", {});
    }

    DP[node.id] = new ObjectiveStruct<T>(numeric_limits<int>::max(), "", {});
    for (auto& arc : node.in_arcs) {
        if (DP[arc->out_node->id] == nullptr) {
            DP[arc->out_node->id] = dp(*arc->out_node, layer - 1);
        }

        ObjectiveStruct<T>* subResult = DP[arc->out_node->id];
        if (DP[node.id]->value > subResult->value + arc->variable_value * weights[layer]) {
            DP[node.id]->value = subResult->value + arc->variable_value * weights[layer];
            DP[node.id]->path = subResult->path + "-> " + arc->to_string() + "(" + to_string(arc->variable_value) + ")";
            DP[node.id]->arcs.assign(subResult->arcs.begin(), subResult->arcs.end());
            DP[node.id]->arcs.push_back(arc);
        }
    }

    return DP[node.id];
}
