#ifndef DD_OPTIMIZATION_PROGRAM_REDUCEDDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_REDUCEDDBUILDER_H

#include "Node.h"
#include "Arc.h"
#include "Graph.h"
#include "utils.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Clase que representa un constructor de un grafo de decisión reducido.
 */
class ReduceDDBuilder{
public:
    /**
     * @brief Constructor de la clase ReduceDDBuilder.
     * @param graph Puntero al grafo original que se reducirá.
     */
    ReduceDDBuilder(Graph* graph);

    Graph* graph; /**< Puntero al grafo original que se reducirá. */

    /**
     * @brief Construye el grafo de decisión reducido.
     * @param should_visualize Booleano que indica si se debe visualizar el proceso de construcción.
     * @return Grafo de decisión reducido.
     */
    Graph GetDecisionDiagram(bool should_visualize);
    
    /**
     * @brief Destructor de la clase ReduceDDBuilder.
     */
    ~ReduceDDBuilder() = default;

private:
    int layer_working; /**< Capa actual de trabajo en la construcción del grafo reducido. */

    // Métodos que trabajan en la construcción del grafo reducido.
    void reviewing_layer(vector<Node*> layer);
    static bool checking_if_two_nodes_should_merge(Node* node_one, Node* node_two);
    static vector<string> get_node_of_every_type_of_path(Node* node);
    void merge_nodes(Node* node_one, Node* node_two);
    pair<Node*, Node*> get_order_of_changin_nodes(Node* node_one, Node* node_two) const;
    static static void redirect_in_arcs(Node* node_to_remove, Node* node_to_keep);
    static void delete_out_arcs(Node* node_to_remove);
    void delete_node(Node* node_to_remove) const;
    void specific_final_function();
    void adjust_node_number() const; /**< Ajusta el id de los nodos tras los cambios producidos */

    // Métodos que visualizan el grafo reducido.
    void print_graph(bool should_visualize);
    void print() const;
};

#endif //DD_OPTIMIZATION_PROGRAM_REDUCEDDBUILDER_H