//
// Created by antonia blanco on 13-02-24.
//

#ifndef TEMPLATETYPE_GRAPH_H
#define TEMPLATETYPE_GRAPH_H

#include "Node.h"
#include "Arc.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Graph {
public:
    /**
     * @brief Constructor de la clase Graph.
     * @param initial_node Nodo inicial del grafo.
     */
    Graph(Node<T>* initial_node);

    /**
     * @brief Constructor por defecto de la clase Graph.
     */
    Graph() = default;

    vector<Node<T>*> nodes; /**< Vector que almacena todos los nodos del grafo. */
    vector<vector<Node<T>*>> structure; /**< Estructura del grafo representada como una matriz de nodos separadas por nivel. */
    int actual_layer; /**< Índice de la capa actual del grafo en la que se esta trabajando. */

    /**
     * @brief Sobrecarga del operador de comparación de igualdad para los grafos.
     * @param other Grafo con el que se desea comparar.
     * @return true si los grafos son iguales, false en caso contrario.
     */
    bool operator==(const Graph &other) const;

    /**
     * @brief Sobrecarga del operador de escritura para los grafos.
     * @param graph Grafo que se quiere escribir en una cadena.
     */
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

    // Métodos que trabajan sobre la estructura de nodos del grafo.
    void add_node(Node<T>* node);
    void add_new_layer();
    void eliminate_node_and_his_arcs(Node<T>& node);
    void remove_node(Node<T>& node);

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
    static bool compare_two_nodes(const Node<T>& nodeOne, const Node<T>& nodeTwo) ;
    void remove_node_from_layer(Node<T>& node); /** < Elimina el nodo entegado del grafo*/
};
#include "Graph.tpp"
#endif //TEMPLATETYPE_GRAPH_H
