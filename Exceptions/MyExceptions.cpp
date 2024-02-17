//
// Created by antonia blanco on 13-02-24.
//

#include "MyExceptions.h"

SameLenError::SameLenError(const char* message) : message(message) {}

const char* SameLenError::what() const noexcept {
    return message;
}

SameVariables::SameVariables(const char* message) : message(message) {}

const char* SameVariables::what() const noexcept {
    return message;
}

MustBeIntegers::MustBeIntegers(const char* message) : message(message) {}

const char* MustBeIntegers::what() const noexcept {
    return message;
}

ConsistentDictionaryOfNeighbors::ConsistentDictionaryOfNeighbors(const char* message) : message(message) {}

const char* ConsistentDictionaryOfNeighbors::what() const noexcept {
    return message;
}

MissingObjectiveFunction::MissingObjectiveFunction(const char* message) : message(message) {}

const char* MissingObjectiveFunction::what() const noexcept {
    return message;
}

NotImplementedError::NotImplementedError(const char* message) : message(message) {}

const char* NotImplementedError::what() const noexcept {
    return message;
}

ObjectiveNotSetException::ObjectiveNotSetException(const char* message) : message(message) {}

const char* ObjectiveNotSetException::what() const noexcept {
    return message;
}
