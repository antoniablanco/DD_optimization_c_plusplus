#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <stdexcept>

class SameLenError : public std::exception {
public:
    SameLenError(const char* message = "Variables must have the same length");
    const char* what() const noexcept override;

private:
    const char* message;
};

class SameVariables : public std::exception {
public:
    SameVariables(const char* message = "Variables must be the same between dictionaries");
    const char* what() const noexcept override;

private:
    const char* message;
};

class MustBeIntegers : public std::exception {
public:
    MustBeIntegers(const char* message = "Values must be integers");
    const char* what() const noexcept override;

private:
    const char* message;
};

class ConsistentDictionaryOfNeighbors : public std::exception {
public:
    ConsistentDictionaryOfNeighbors(const char* message = "Dictionary of neighbors must be consistent");
    const char* what() const noexcept override;

private:
    const char* message;
};

class MissingObjectiveFunction : public std::exception {
public:
    MissingObjectiveFunction(const char* message = "The Objective Function has not been set");
    const char* what() const noexcept override;

private:
    const char* message;
};

class NotImplementedError : public std::exception {
public:
    NotImplementedError(const char* message = "This method has not been implemented yet");
    const char* what() const noexcept override;

private:
    const char* message;
};

class ObjectiveNotSetException : public std::exception {
public:
    ObjectiveNotSetException(const char* message = "Objective has not been set, please use solve_dd()");
    const char* what() const noexcept override;

private:
    const char* message;
};

#endif // CUSTOM_EXCEPTIONS_H
