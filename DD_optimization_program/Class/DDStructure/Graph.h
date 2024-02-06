
#ifndef DD_OPTIMIZATION_PROGRAM_GRAPH_H
#define DD_OPTIMIZATION_PROGRAM_GRAPH_H

#include "Node.h"
#include "Arc.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Clase que representa un grafo.
 */
class Graph {
public:
    /**
     * @brief Constructor de la clase Graph.
     * @param initial_node Nodo inicial del grafo.
     */
    Graph(Node* initial_node);

    /**
     * @brief Constructor por defecto de la clase Graph.
     */
    Graph() = default;

    vector<Node*> nodes; /**< Vector que almacena todos los nodos del grafo. */
    vector<vector<Node*>> structure; /**< Estructura del grafo representada como una matriz de nodos separadas por nivel. */
    int actual_layer; /**< Índice de la capa actual del grafo en la que se esta trabajando. */

    /**
     * @brief Sobrecarga del operador de comparación de igualdad para los grafos.
     * @param other Grafo con el que se desea comparar.
     * @return true si los grafos son iguales, false en caso contrario.
     */
    bool operator==(const Graph &other) const;

    // Métodos que trabajan sobre la estructura de nodos del grafo.
    void add_node(Node* node);
    void add_new_layer();
    void eliminate_node_and_his_arcs(Node& node);
    void remove_node(Node& node);

    /**
     * @brief Destructor de la clase Graph.
     */
    ~Graph() = default;

private:
    /**
     * @brief Compara dos nodos.
     * @param nodeOne Nodo a comparar.
     * @param nodeTwo Nodo a comparar.
     * @return true si los nodos son iguales, false en caso contrario.
     */
    bool compare_two_nodes(const Node& nodeOne, const Node& nodeTwo) const;
    void remove_node_from_layer(Node& node); /** < Elimina el nodo entegado del grafo*/
};


#endif //DD_OPTIMIZATION_PROGRAM_GRAPH_H
