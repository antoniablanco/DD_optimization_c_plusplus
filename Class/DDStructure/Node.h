#ifndef TEMPLATETYPE_NODE_H
#define TEMPLATETYPE_NODE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Declaración anticipada de la clase Arc para evitar problemas de dependencia circular.
template <typename T>
class Arc;

/**
 * @brief Clase que representa un nodo en un grafo.
 */
template <typename T>
class Node {
public:
    /**
     * @brief Constructor de la clase Node.
     * @param node_id Identificador único del nodo.
     * @param state Estado del nodo representado como un vector de enteros.
     */
    Node(int node_id, T state);

    /**
     * @brief Constructor por defecto de la clase Node.
     */
    Node() = default;

    int id; /**< Identificador único del nodo. */
    T state; /**< Estado del nodo, el cual puede poseer diferentes tipos de datos */
    vector<Arc<T>*> in_arcs; /**< Vector de arcos que entran al nodo. */
    vector<Arc<T>*> out_arcs; /**< Vector de arcos que salen del nodo. */

    /**
     * @brief Convierte el nodo a una cadena de texto.
     * @return Cadena de texto que representa el nodo.
     */
    string to_string() const;

    /**
     * @brief Sobrecarga del operador de comparación de igualdad para los nodos.
     * @param other Nodo con el que se desea comparar.
     * @return true si los nodos son iguales, false en caso contrario.
     */
    bool operator==(const Node &other) const;

    /**
     * @brief Sobrecarga del operador de escritura para los grafos.
     * @param node Nodo que se quiere escribir en una cadena.
     */
    friend std::ostream& operator<<(std::ostream& os, const Node<T>& node);

    /**
     * @brief Obtención del estado del nodo.
     */

    // Métodos que trabajan sobre la estructura de arcos del nodo.
    void add_in_arc(Arc<T>* arc);
    void add_out_arc(Arc<T>* arc);

    /**
     * @brief Destructor de la clase Node.
     */
    ~Node();
};

#include "Node.tpp"
#endif //TEMPLATETYPE_NODE_H
