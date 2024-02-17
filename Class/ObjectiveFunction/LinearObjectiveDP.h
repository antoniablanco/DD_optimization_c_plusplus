#ifndef TEMPLATETYPE_LINEAROBJECTIVEDP_H
#define TEMPLATETYPE_LINEAROBJECTIVEDP_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>

#include "AbstractObjective.h"

using namespace std;


/**
 * @brief Algoritmo de programación dinámica para resolver un objetivo lineal utilizando programación dinámica.
 */
template <typename T>
class LinearObjectiveDP : public AbstractObjective<T> {
public:
    /**
     * @brief Constructor de la clase LinearObjectiveDP.
     * @param weights Pesos de las variables del objetivo.
     * @param objective Objetivo que se desea resolver.
     */
    LinearObjectiveDP(vector<int> weights, string objective);

    /**
     * @brief Asigna un grafo al objetivo.
     * @param graph_DD Grafo que se va a asignar al objetivo.
     * Implementa el método virtual puro de la clase AbstractObjective.
     */
    void assign_graph(Graph<T> graph_DD) override;

    /**
     * @brief Resuelve el grafo asociado al objetivo.
     * @return Estructura de datos que representa el resultado de la resolución del grafo.
     * Implementa el método virtual puro de la clase AbstractObjective.
     */
    ObjectiveStruct<T> resolve_graph() override;

    /**
     * @brief Destructor de la clase LinearObjectiveDP.
     */
    ~LinearObjectiveDP()= default;

private:
    vector<int> weights; /**< Pesos de las variables del objetivo. */
    string objective; /**< Objetivo que se desea resolver. */
    Graph<T> graph; /**< Grafo asociado al objetivo. */
    int neutro = -111111; /**< Valor neutro utilizado por el algoritmo. */
    vector<ObjectiveStruct<T>*> DP; /**< Vector que almacena los resultados de la programación dinámica. */

    /**
     * @brief Aplica transformaciones necesarias a los pesos para la resolución del problema, si este es de maximización.
     */
    void choose_transform_weights();

    /**
     * @brief Algoritmo de programación dinámica para resolver el problema.
     * @param node Nodo actual en el grafo de decisión.
     * @param layer Capa actual en el grafo de decisión.
     * @return Puntero a la estructura de objetivo correspondiente al nodo y capa dados.
     */
    ObjectiveStruct<T>* dp(const Node<T>& node, int layer);
};
#include "LinearObjectiveDP.tpp"
#endif //TEMPLATETYPE_LINEAROBJECTIVEDP_H
