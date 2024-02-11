
#ifndef DD_OPTIMIZATION_PROGRAM_ARC_H
#define DD_OPTIMIZATION_PROGRAM_ARC_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Declaración anticipada de la clase Node para evitar problemas de dependencia circular
class Node;

/**
 * @brief Clase que representa un arco en un grafo.
 */
class Arc{
public:
    /**
     * @brief Constructor de la clase Arc.
     * @param out_node Puntero al nodo desde el que sale el arco.
     * @param in_node Puntero al nodo que entra el arco.
     * @param variable_value Valor que toma la variable asociada.
     * @param variable_id Identificador de la variable asociada al arco.
     */
    Arc(Node* out_node, Node* in_node, int variable_value, std::string variable_id);
    Node* out_node; /**< Puntero al nodo desde el que sale el arco. */
    Node* in_node; /**< Puntero al nodo que entra el arco. */
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

#endif //DD_OPTIMIZATION_PROGRAM_ARC_H
