//
// Created by antonia blanco on 21-01-24.
//

#ifndef DD_OPTIMIZATION_PROGRAM_UTILS_H
#define DD_OPTIMIZATION_PROGRAM_UTILS_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief Convierte un vector de enteros a una cadena de texto.
 * @param vector Vector de enteros que se va a convertir.
 * @return Cadena de texto que representa el vector de enteros.
 */
string to_string_int_vector(vector<int> vector);

/**
 * @brief Convierte un vector de cadenas de texto a una cadena de texto.
 * @param vector Vector de cadenas de texto que se va a convertir.
 * @return Cadena de texto que representa el vector de cadenas de texto.
 */
string to_string_string_vector(vector<string> vector);

/**
 * @brief Elimina un valor específico de un vector de enteros.
 * @param vector Vector de enteros del cual se va a eliminar el valor.
 * @param value Valor que se va a eliminar del vector.
 */
void remove_int_vector(vector<int> &vector, int value);


#endif //DD_OPTIMIZATION_PROGRAM_UTILS_H
