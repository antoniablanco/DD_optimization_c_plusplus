
#ifndef DD_OPTIMIZATION_PROGRAM_NODE_H
#define DD_OPTIMIZATION_PROGRAM_NODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

// Declaración anticipada de la clase Arc para evitar problemas de dependencia circular.
class Arc;

/**
 * @brief Clase que representa un nodo en un grafo.
 */
class Node {
public:
    /**
     * @brief Constructor de la clase Node.
     * @param node_id Identificador único del nodo.
     * @param state Estado del nodo representado como un vector de enteros.
     */
    Node(int node_id, vector<int> state);

    /**
     * @brief Constructor por defecto de la clase Node.
     */
    Node() = default;

    int id; /**< Identificador único del nodo. */
    vector<int> state; /**< Estado del nodo, el cual puede poseer diferentes tipos de datos */
    list<Arc*> in_arcs; /**< Lista de arcos que entran al nodo. */
    list<Arc*> out_arcs; /**< Lista de arcos que salen del nodo. */

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


    friend std::ostream& operator<<(std::ostream& os, const Node& node);

    // Métodos que trabajan sobre la estructura de arcos del nodo.
    void add_in_arc(Arc* arc);
    void add_out_arc(Arc* arc);
    void remove_in_arc(Arc& arc);
    void remove_out_arc(Arc& arc);

    /**
     * @brief Destructor de la clase Node.
     */
    ~Node();
};

#endif //DD_OPTIMIZATION_PROGRAM_NODE_H
