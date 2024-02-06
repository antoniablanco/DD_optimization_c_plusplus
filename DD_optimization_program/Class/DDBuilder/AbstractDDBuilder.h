
#ifndef DD_OPTIMIZATION_PROGRAM_ABSTRACTDDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_ABSTRACTDDBUILDER_H

#include "Node.h"
#include "Arc.h"
#include "Graph.h"
#include "AbstractProblemClass.h"
#include "utils.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>

/**
 * @brief Clase abstracta que proporciona la base para la construcción de diagramas de decisión.
 */
class AbstractDDBuilder{
public:
    /**
     * @brief Constructor de la clase AbstractDDBuilder.
     * @param problem Referencia al problema asociado al grafo.
     */
    AbstractDDBuilder(AbstractProblem& problem);

    Graph* graph;

    /**
     * @brief Construye el diagrama de decisión.
     * @param should_visualize Booleano que indica si se debe visualizar la construcción del grafo.
     * @return Puntero al grafo construido.
     */
    Graph* get_desition_diagram(bool should_visualize);

    virtual ~AbstractDDBuilder() = default; /**< Destructor virtual por defecto. */

protected:
    int node_number; /**< Contador de nodos para nombrar sus id's. */
    AbstractProblem& problem; /**< Referencia al problema asociado al grafo. */
    vector<string> variables; /**< Lista de variables del problema. */
    map<string, vector<int>> variables_domain; /**< Dominio de las variables del problema. */
    pair<bool, Node*> exist_node_with_same_state(vector<int> node_state); /**< Verifica si existe un nodo con el mismo estado. */

private:
    /**
     * @brief Inicializa el grafo con un nodo raíz.
     * @param initial_state Estado inicial del nodo raíz.
     */
    Graph initialize_graph(vector<int>& initial_state);  

    // Métodos para la construcción del grafo
    void create_new_layer(int variable_id);
    void create_new_nodes_in_the_new_layer(int variable_id);
    void check_if_new_node_should_be_created(int variable_value, Node* existed_node, int variable_id); 
    bool there_is_node_in_last_layer(int variable_id);
    void create_arcs_for_the_terminal_node(int variable_value, Node* existed_node, int variable_id);
    void create_rest_of_arcs(int variable_value, Node* existed_node, int variable_id, vector<int> node_state); 
    void create_arc_for_the_new_node(Node* existed_node, Node* node_created, int variable_value, int variable_id); 
    
    // Métodos de visualización
    void print_graph(bool should_visualize); 
    void print();
    
    /**
     * @brief Función específica de la capa.
     * Método virtual puro que debe ser implementado por las subclases para definir el comportamiento 
     * de la capa específica.
     */
    virtual void specific_layer_function() = 0;

    /**
     * @brief Función específica final.
     * Método virtual puro que debe ser implementado por las subclases para definir el comportamiento final 
     * específico.
     */
    virtual void specific_final_function() = 0;
};


#endif //DD_OPTIMIZATION_PROGRAM_ABSTRACTDDBUILDER_H