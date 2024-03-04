#ifndef TEMPLATETYPE_INDEPENDENTSETPROBLEM_H
#define TEMPLATETYPE_INDEPENDENTSETPROBLEM_H

#include "MyExceptions.h"
#include "AbstractProblemClass.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>
#include <unordered_set>

using namespace std;

/**
 * @brief Clase que representa un problema de conjunto independiente.
 *
 * Esta clase hereda de AbstractProblem y define un problema de conjunto independiente,
 * en el que se busca encontrar el conjunto más grande de nodos no adyacentes en un grafo.
 */
class IndependentSetProblem : public AbstractProblem<vector<int>> {
public:
    /**
     * @brief Constructor de la clase IndependentSetProblem.
     *
     * @param initial_state Estado inicial del problema.
     * @param variables Variables del problema, representadas como pares de nombre y dominio.
     * @param dict_node_neighbors Diccionario de vecinos de los nodos del grafo.
     */
    IndependentSetProblem(vector<int>& initial_state, vector<pair<string, vector<int>>>& variables,
                          map<string, vector<int>> dict_node_neighbors);

    // Métodos que implementan funciones virtuales de la clase AbstractProblem.
    bool equals(const vector<int>& state_one, const vector<int>& state_two) const override;
    pair<vector<int>, bool> transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const override;
    int get_priority_for_discard_node(const vector<int>& state) const override;
    int get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const override;
    vector<int> merge_operator(const vector<int>& state_one, const vector<int>& state_two) const override;
    string get_state_as_string(const vector<int>& state) const override;

private:
    map<string, vector<int>> dict_node_neighbors; /**< Diccionario de vecinos de los nodos del grafo. */

    // Métodos privados que verifican la consistencia de los atributos del problema.
    void check_atributes(vector<pair<string, vector<int>>>& variables);
    void check_same_variables(vector<pair<string, vector<int>>>& variables);
    void check_consistent_dictionary_of_neighbors();


    unordered_set<string> keysToVector(const map<string, vector<int>>& variables); /**< Obtiene las claves de un mapa de pares. */
    unordered_set<string> keysOfVector(vector<pair<string, vector<int>>>& variables); /**< Obtiene las claves de un vector de pares. */

    /**
     * @brief Verifica si un vecino es consistente.
     *
     * @param key Clave del nodo.
     * @param value Valor del vecino.
     * @return true si el vecino es consistente, false en caso contrario.
     */
    bool isNeighborConsistent(const string& key, int value);

};

#endif //TEMPLATETYPE_INDEPENDENTSETPROBLEM_H
