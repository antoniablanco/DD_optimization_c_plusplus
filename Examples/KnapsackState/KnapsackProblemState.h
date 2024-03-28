#ifndef TEMPLATETYPE_KNAPSACKPROBLEMSTATE_H
#define TEMPLATETYPE_KNAPSACKPROBLEMSTATE_H

#include "MyExceptions.h"
#include "AbstractProblemClass.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>

using namespace std;

class State {
public: 
    State(vector<int> value);
    vector<int> value;

    bool operator==(const State& other) const;
};

/**
 * @brief Clase que representa un problema de la mochila (Knapsack Problem).
 *
 * Esta clase hereda de AbstractProblem y define un problema de la mochila,
 * donde se busca maximizar el valor total de los elementos seleccionados,
 * respetando una restricción de peso máximo.
 */
class KnapsackProblemState : public AbstractProblem<State> {
public:
    /**
     * @brief Constructor de la clase KnapsackProblem.
     *
     * @param initial_state Estado inicial del problema.
     * @param variables Variables del problema, representadas como pares de nombre y dominio.
     * @param matrix_of_wheight Matriz de pesos de los elementos.
     * @param right_side_of_restrictions Lado derecho de las restricciones.
     */
    KnapsackProblemState(State& initial_state, const vector<pair<string, vector<int>>>& variables,
                    vector<vector<int>> matrix_of_wheight, vector<int> right_side_of_restrictions);

    // Métodos que implementan funciones virtuales de la clase AbstractProblem.
    bool equals(const State& state_one, const State& state_two) const override;
    pair<State, bool> transition_function(const State& previous_state, const string& variable_id, int variable_value) const override;
    int get_priority_for_discard_node(const State& state) const override;
    int get_priority_for_merge_nodes(const int node_id, const State& state) const override;
    State merge_operator(const State& state_one, const State& state_two) const override;
    string get_state_as_string(const State& state) const override;

private:
    vector<vector<int>> matrix_of_wheight; /**< Matriz de pesos de los elementos. */
    vector<int> right_side_of_restrictions; /**< Lado derecho de las restricciones. */

    // Métodos privados que verifican la consistencia de los atributos del problema.
    void check_atributes(const vector<pair<string, vector<int>>>& variables, State& initial_state);
    void check_same_len_matrix_and_right_side(State& initial_state);
    void check_same_len_rows_matrix_and_variables(const vector<pair<string, vector<int>>>& variables);

};

#endif //TEMPLATETYPE_KNAPSACKPROBLEMSTATE_H