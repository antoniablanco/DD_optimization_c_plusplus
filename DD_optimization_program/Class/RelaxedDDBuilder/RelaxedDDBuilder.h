#ifndef DD_OPTIMIZATION_PROGRAM_RELAXEDDDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_RELAXEDDDBUILDER_H

#include "AbstractDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Clase que representa un constructor de un grafo de decisión relajado.
 */
class RelaxedDDBuilder: public AbstractDDBuilder {
public:
    /**
     * @brief Constructor de la clase RelaxedDDBuilder.
     * @param problem Referencia a un objeto de la clase AbstractProblem que representa el problema a resolver.
     * @param max_width Ancho máximo permitido para el grafo de decisión.
     */
    RelaxedDDBuilder(AbstractProblem& problem, int max_width);

private:
    int max_width; /**< Ancho máximo permitido para el grafo de decisión. */

    /**
     * @brief Función específica para la capa del grafo en la construcción de un grafo de decisión relajado.
     * Se implementa función obligatoria de la clase padre.
     */
    void specificLayerFunction() override;

    /**
     * @brief Función específica para la capa final del grafo en la construcción de un grafo de decisión relajado.
     * Se implementa función obligatoria de la clase padre.
     */
    void specific_final_function() override;
    
    // Métodos que trabajan en la construcción del grafo relajado.
    void merge_nodes_when_width_is_greater_than_w();
    bool width_is_greater_than_w();
    void merge_nodes(Node* node_to_remove, Node* node_to_keep);
    void merge_with_an_existing_node(Node* node_one, Node* node_two, Node* exist_node);
    void merge_when_doesnt_exist_node(Node* node_to_remove, Node* node_to_keep, vector<int> new_state);
    static void redirect_in_arcs(Node* node_to_remove, Node* node_to_keep);
    static void change_new_state(Node* node, vector<int> new_state);
    void delete_node(Node* node_to_remove);
    void adjust_node_number(); /**< Ajusta el id de los nodos tras los cambios producidos */

};

#endif //DD_OPTIMIZATION_PROGRAM_RELAXEDDDBUILDER_H