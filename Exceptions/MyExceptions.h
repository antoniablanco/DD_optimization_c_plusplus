//
// Created by antonia blanco on 13-02-24.
//

#ifndef TEMPLATETYPE_MYEXCEPTIONS_H
#define TEMPLATETYPE_MYEXCEPTIONS_H

#include <stdexcept>

/**
 * @brief Excepción lanzada cuando las variables tienen longitudes diferentes.
 */
class SameLenError : public std::exception {
public:
    SameLenError(const char* message = "Variables must have the same length"); // Constructor
    const char* what() const noexcept override; // Método que devuelve el mensaje de error

private:
    const char* message; // Mensaje de error
};

/**
 * @brief Excepción lanzada cuando las variables no son las mismas entre diccionarios.
 */
class SameVariables : public std::exception {
public:
    SameVariables(const char* message = "Variables must be the same between dictionaries"); // Constructor
    const char* what() const noexcept override; // Método que devuelve el mensaje de error

private:
    const char* message; // Mensaje de error
};

/**
 * @brief Excepción lanzada cuando los valores no son enteros.
 */
class MustBeIntegers : public std::exception {
public:
    MustBeIntegers(const char* message = "Values must be integers"); // Constructor
    const char* what() const noexcept override; // Método que devuelve el mensaje de error

private:
    const char* message; // Mensaje de error
};

/**
 * @brief Excepción lanzada cuando el diccionario de vecinos no es consistente.
 */
class ConsistentDictionaryOfNeighbors : public std::exception {
public:
    ConsistentDictionaryOfNeighbors(const char* message = "Dictionary of neighbors must be consistent"); // Constructor
    const char* what() const noexcept override; // Método que devuelve el mensaje de error

private:
    const char* message; // Mensaje de error
};

/**
 * @brief Excepción lanzada cuando no se ha establecido la función objetivo.
 */
class MissingObjectiveFunction : public std::exception {
public:
    MissingObjectiveFunction(const char* message = "The Objective Function has not been set"); // Constructor
    const char* what() const noexcept override; // Método que devuelve el mensaje de error

private:
    const char* message; // Mensaje de error
};

/**
 * @brief Excepción lanzada cuando se intenta llamar a un método no implementado.
 */
class NotImplementedError : public std::exception {
public:
    NotImplementedError(const char* message = "This method has not been implemented yet"); // Constructor
    const char* what() const noexcept override; // Método que devuelve el mensaje de error

private:
    const char* message; // Mensaje de error
};

/**
 * @brief Excepción lanzada cuando no se ha establecido el algoritmo para resolver el problema.
 */
class ObjectiveNotSetException : public std::exception {
public:
    ObjectiveNotSetException(const char* message = "Objective has not been set, please use solve_dd()"); // Constructor
    const char* what() const noexcept override; // Método que devuelve el mensaje de error

private:
    const char* message; // Mensaje de error
};

#endif //TEMPLATETYPE_MYEXCEPTIONS_H
