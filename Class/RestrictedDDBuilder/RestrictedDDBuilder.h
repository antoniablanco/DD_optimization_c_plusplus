#ifndef TEMPLATETYPE_RESTRICTEDDDBUILDER_H
#define TEMPLATETYPE_RESTRICTEDDDBUILDER_H

#include "AbstractDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Clase que representa un constructor de un grafo de decisión restringido.
 */
template <typename T>
class RestrictedDDBuilder: public AbstractDDBuilder<T> {
public:
    /**
     * @brief Constructor de la clase RestrictedDDBuilder.
     * @param problem Referencia a un objeto de la clase AbstractProblem que representa el problema a resolver.
     * @param max_width Ancho máximo permitido para el grafo de decisión.
     */
    RestrictedDDBuilder(AbstractProblem<T>& problem, int max_width);

private:
    int max_width; /**< Ancho máximo permitido para el grafo de decisión. */

    /**
     * @brief Función específica para la capa del grafo en la construcción de un grafo de decisión restringido.
     * Se implementa función obligatoria de la clase padre.
     */
    void specificLayerFunction() override;

    /**
     * @brief Función específica para la capa final del grafo en la construcción de un grafo de decisión restringido.
     * Se implementa función obligatoria de la clase padre.
     */
    void specific_final_function() override;


    // Métodos que trabajan en la construcción del grafo restringido.
    void eliminate_nodes_when_width_is_greater_than_w();
    bool width_is_greater_than_w();
    void eliminate_nodes(const vector<Node<T>*>& nodes_to_eliminate);
    void eliminate_nodes_without_out_arcs();
    void adjust_node_number();

};
#include "RestrictedDDBuilder.tpp"
#endif //TEMPLATETYPE_RESTRICTEDDDBUILDER_H
