#ifndef DD_OPTIMIZATION_PROGRAM_SETCOVERINGPROBLEM_H
#define DD_OPTIMIZATION_PROGRAM_SETCOVERINGPROBLEM_H

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
 * @brief Clase que representa un problema de cubrimiento de conjuntos (Set Covering Problem).
 * 
 * Esta clase hereda de AbstractProblem y define un problema de cubrimiento de conjuntos,
 * donde se busca encontrar el conjunto mínimo que cubren todos los elementos.
 */
class SetCoveringProblem : public AbstractProblem {
public:
    /**
     * @brief Constructor de la clase SetCoveringProblem.
     * 
     * @param initial_state Estado inicial del problema.
     * @param variables Variables del problema, representadas como pares de nombre y dominio.
     * @param matrix_of_wheight Matriz de pesos de los elementos.
     * @param right_side_of_restrictions Lado derecho de las restricciones.
     */
    SetCoveringProblem(vector<int>& initial_state, const vector<pair<string, vector<int>>>& variables, 
    vector<vector<int>> matrix_of_wheight, vector<int> right_side_of_restrictions);

    // Métodos que implementan funciones virtuales de la clase AbstractProblem.
    bool equals(const vector<int>& state_one, const vector<int>& state_two) const override;
    pair<vector<int>, bool> transition_function(const vector<int>& previous_state, const string& variable_id, int variable_value) const override;
    int get_priority_for_discard_node(const vector<int>& state) const override;
    int get_priority_for_merge_nodes(const int node_id, const vector<int>& state) const override;
    const vector<int> merge_operator(const vector<int>& state_one, const vector<int>& state_two) const override;

private:
    vector<vector<int>> matrix_of_wheight; /**< Matriz de pesos de los elementos. */
    vector<int> right_side_of_restrictions; /**< Lado derecho de las restricciones. */

    // Métodos privados que verifican la consistencia de los atributos del problema.
    void check_atributes(const vector<pair<string, vector<int>>>& variables, vector<int>& initial_state);
    void check_same_len_matrix_and_right_side(vector<int>& initial_state);
    void check_same_len_rows_matrix_and_variables(const vector<pair<string, vector<int>>>& variables);

};

#endif //DD_OPTIMIZATION_PROGRAM_SETCOVERINGPROBLEM_H