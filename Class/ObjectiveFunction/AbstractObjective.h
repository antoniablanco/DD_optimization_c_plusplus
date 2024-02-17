#ifndef TEMPLATETYPE_ABSTRACTOBJECTIVE_H
#define TEMPLATETYPE_ABSTRACTOBJECTIVE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

#include "ObjectiveStructure.h"

using namespace std;

/**
 * @brief Clase abstracta que representa un objetivo en el programa de optimización.
 */
template <typename T>
class AbstractObjective {
public:
    /**
     * @brief Constructor de la clase AbstractObjective.
     */
    AbstractObjective();

    /**
     * @brief Asigna un grafo al objetivo.
     * @param graph_DD Grafo que se va a asignar al objetivo.
     * Es un método virtual puro que debe ser implementado por las clases hijas.
     */
    virtual void assign_graph(Graph<T> graph_DD) = 0;

    /**
     * @brief Resuelve el grafo asociado al objetivo.
     * @return Estructura de datos que representa el resultado de la resolución del grafo.
     * Es un método virtual puro que debe ser implementado por las clases hijas.
     */
    virtual ObjectiveStruct<T> resolve_graph() = 0;

    /**
     * @brief Destructor de la clase AbstractObjective.
     */
    virtual ~AbstractObjective()= default;
};
#include "AbstractObjective.tpp"
#endif //TEMPLATETYPE_ABSTRACTOBJECTIVE_H
