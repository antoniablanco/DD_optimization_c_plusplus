#ifndef DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H
#define DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

#include "Graph.h"
#include "AbstractObjective.h"
#include "ObjectiveStructure.h"
#include "DD.h"

using namespace std;

/**
 * @brief Clase que representa un controlador de función objetivo para un diagrama de decisión.
 */
class ObjectiveFunction {
public:
    /**
     * @brief Constructor de la clase ObjectiveFunction.
     * @param dd Objeto de la clase DD en el cual se encuentra el grafo de decisión asociado a la función objetivo.
     */
    ObjectiveFunction(DD dd);

    ObjectiveStruct answer; /**< Estructura que almacena la solución de la función objetivo. */

    /**
     * @brief Establece la función que se utilizará para resolver el diagrama de decisión.
     * @param objective_function Referencia a un objeto de la clase AbstractObjective que representa 
     * el algoritmo a utilizar.
     */
    void set_objective_function(AbstractObjective& objective_function);

    /**
     * @brief Resuelve el diagrama de decisión entregado utilizando el algortimo pasado anteriormente.
     * @return Estructura que contiene la solución de la función objetivo.
     */
    ObjectiveStruct solve_dd();

    /**
     * @brief Obtiene el tiempo empleado para resolver la función objetivo.
     * @return Cadena de texto que representa el tiempo empleado.
     */
    string get_time();

    /**
     * @brief Obtiene la solución de la función objetivo calculada anteriormente.
     * @return Estructura que contiene la solución de la función objetivo.
     */
    ObjectiveStruct get_the_solution();

private:

    Graph graph; /**< Grafo de decisión asociado a la función objetivo. */
    chrono::duration<double> time; /**< Tiempo empleado para resolver la función objetivo. */
    AbstractObjective* objective_function; /**< Puntero a la función objetivo. */

    /**
     * @brief Verifica si el algoritmo a sido entregado.
     */
    void check_if_objective_is_set();
};

#endif //DD_OPTIMIZATION_PROGRAM_OBJECTIVEFUNCTION_H