//
// Created by antonia blanco on 12-02-24.
//

#ifndef TEMPLATETYPE_ARC_H
#define TEMPLATETYPE_ARC_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Declaración anticipada de la clase Node para evitar problemas de dependencia circular
template <typename T>
class Node;

/**
 * @brief Clase que representa un arco en un grafo.
 */
template <typename T>
class Arc{
public:
    /**
     * @brief Constructor de la clase Arc.
     * @param out_node Puntero al nodo desde el que sale el arco.
     * @param in_node Puntero al nodo que entra el arco.
     * @param variable_value Valor que toma la variable asociada.
     * @param variable_id Identificador de la variable asociada al arco.
     */
    Arc(Node<T>* out_node, Node<T>* in_node, int variable_value, std::string variable_id);
    Node<T>* out_node; /**< Puntero al nodo desde el que sale el arco. */
    Node<T>* in_node; /**< Puntero al nodo que entra el arco. */
    int variable_value; /**< Valor que toma la variable asociada */
    string variable_id; /**< Identificador de la variable asociada al arco. */

    /**
     * @brief Convierte el arco a una cadena de texto.
     * @return Cadena de texto que representa el arco.
     */
    string to_string() const;


    friend std::ostream& operator<<(std::ostream& os, const Arc& arc);

    /**
     * @brief Sobrecarga del operador de comparación de igualdad para los arcos.
     * @param other Arco con el que se desea comparar.
     * @return true si los arcos son iguales, false en caso contrario.
     */
    bool operator==(const Arc &other) const;

    /**
     * @brief Destructor por defecto de la clase Arc.
     */
    ~Arc() = default;
};

#include "Arc.tpp"
#endif //TEMPLATETYPE_ARC_H
