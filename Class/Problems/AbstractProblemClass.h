#ifndef TEMPLATETYPE_ABSTRACTPROBLEMCLASS_H
#define TEMPLATETYPE_ABSTRACTPROBLEMCLASS_H

#include <vector>
#include <map>
#include <string>
#include <utility>
#include <stdexcept>

using namespace std;

/**
 * @brief Clase abstracta que representa un problema de optimización.
 */
template <typename T> class AbstractProblem {
public:
    /**
     * @brief Constructor de la clase AbstractProblem.
     * @param initial_state Estado inicial del problema.
     * @param variables Vector de pares que representa las variables del problema y sus dominios.
     */
    AbstractProblem(T& initial_state, const vector<pair<string, vector<int>>>& variables);

    /**
     * @brief Compara dos estados para determinar si son iguales.
     * @param state_one Primer estado a comparar.
     * @param state_two Segundo estado a comparar.
     * @return true si los estados son iguales, false en caso contrario.
     */
    virtual bool equals(const T& state_one, const T& state_two) const = 0;

    /**
     * @brief Función de transición que define cómo cambiar de un estado a otro dado una variable y su valor.
     * @param previous_state Estado anterior.
     * @param variable_id Identificador de la variable que se va a cambiar.
     * @param variable_value Valor de la variable.
     * @return Par que contiene el nuevo estado resultante y un indicador de viabilidad.
     */
    virtual pair<T, bool> transition_function(const T& previous_state, const string& variable_id, int variable_value) const = 0;

    /**
     * @brief Obtiene la prioridad para descartar un nodo del grafo de decisión.
     * @param state Estado del nodo a evaluar.
     * @return Prioridad para descartar el nodo.
     */
    virtual int get_priority_for_discard_node(const T& state) const = 0;

    /**
     * @brief Obtiene la prioridad para fusionar nodos en el grafo de decisión.
     * @param node_id Identificador del nodo a evaluar.
     * @param state Estado del nodo a evaluar.
     * @return Prioridad para fusionar los nodos.
     */
    virtual int get_priority_for_merge_nodes(const int node_id, const T& state) const = 0;

    /**
     * @brief Operador de fusión que combina dos estados en uno solo.
     * @param state_one Primer estado a fusionar.
     * @param state_two Segundo estado a fusionar.
     * @return Nuevo estado resultante de la fusión.
     */
    virtual const T merge_operator(const T& state_one, const T& state_two) const = 0;

    virtual const string get_state_as_string(const T& state) const = 0;

    T& initial_state; /**< Estado inicial del problema. */
    vector<string> ordered_variables; /**< Vector que contiene el orden de las variables. */
    map<string, vector<int>> variables_domain; /**< Mapa que contiene las variables y sus dominios. */

    /**
     * @brief Destructor de la clase AbstractProblem.
     */
    virtual ~AbstractProblem() = default;


private:
    /**
     * @brief Obtiene las variables y sus dominios a partir del vector de pares proporcionado en su construcción.
     * @param variables Vector de pares que representa las variables del problema y sus dominios.
     */
    void get_variables(const vector<pair<string, vector<int>>>& variables);
};
#include "AbstractProblemClass.tpp"
#endif //TEMPLATETYPE_ABSTRACTPROBLEMCLASS_H
