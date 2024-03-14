#ifndef TEMPLATETYPE_REDUCEDDBUILDER_H
#define TEMPLATETYPE_REDUCEDDBUILDER_H

#include "Graph.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

/**
 * @brief Clase que representa un constructor de un grafo de decisión reducido.
 */
template <typename T>
class ReduceDDBuilder{
public:
    /**
     * @brief Constructor de la clase ReduceDDBuilder.
     * @param graph Puntero al grafo original que se reducirá.
     */
    ReduceDDBuilder(Graph<T>* graph, AbstractProblem<T>& problem);

    Graph<T>* graph; /**< Puntero al grafo original que se reducirá. */

    /**
     * @brief Construye el grafo de decisión reducido.
     * @param should_visualize Booleano que indica si se debe visualizar el proceso de construcción.
     * @return Grafo de decisión reducido.
     */
    Graph<T> GetDecisionDiagram(bool should_visualize);

    /**
     * @brief Destructor de la clase ReduceDDBuilder.
     */
    ~ReduceDDBuilder() = default;

private:
    int layer_working; /**< Capa actual de trabajo en la construcción del grafo reducido. */
    AbstractProblem<T>& problem; /**< Referencia al problema asociado al grafo. */

    // Métodos que trabajan en la construcción del grafo reducido.
    void reviewing_layer(vector<Node<T>*> layer);
    static vector<string> get_node_of_every_type_of_path(Node<T>* node);
    void merge_nodes(Node<T>* node_to_remove, Node<T>* node_to_keep);
    static void redirect_in_arcs(Node<T>* node_to_remove, Node<T>* node_to_keep);
    static void delete_out_arcs(Node<T>* node_to_remove);
    void delete_node(Node<T>* node_to_remove) const;
    void specific_final_function();
    void adjust_node_number() const; /**< Ajusta el id de los nodos tras los cambios producidos */

    // Métodos que visualizan el grafo reducido.
    void print_graph(bool should_visualize);
    void print() const;
};
#include "ReduceDDBuilder.tpp"
#endif //TEMPLATETYPE_REDUCEDDBUILDER_H
