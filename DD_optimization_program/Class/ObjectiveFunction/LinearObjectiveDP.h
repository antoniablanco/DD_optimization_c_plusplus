
#ifndef DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H
#define DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>

#include "AbstractObjective.h"
#include "ObjectiveStructure.h"

using namespace std;


/**
 * @brief Algoritmo de programación dinámica para resolver un objetivo lineal utilizando programación dinámica.
 */
class LinearObjectiveDP : public AbstractObjective {
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
    void assign_graph(Graph graph_DD) override;

    /**
     * @brief Resuelve el grafo asociado al objetivo.
     * @return Estructura de datos que representa el resultado de la resolución del grafo.
     * Implementa el método virtual puro de la clase AbstractObjective.
     */
    ObjectiveStruct resolve_graph() override;

    /**
     * @brief Destructor de la clase LinearObjectiveDP.
     */
    ~LinearObjectiveDP()= default;

private:
    vector<int> weights; /**< Pesos de las variables del objetivo. */
    string objective; /**< Objetivo que se desea resolver. */
    Graph graph; /**< Grafo asociado al objetivo. */
    int neutro = -111111; /**< Valor neutro utilizado por el algoritmo. */
    vector<ObjectiveStruct*> DP; /**< Vector que almacena los resultados de la programación dinámica. */
    
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
    ObjectiveStruct* dp(Node node, int layer);
};


#endif //DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H