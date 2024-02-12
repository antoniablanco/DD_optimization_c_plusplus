//
// Created by antonia blanco on 21-01-24.
//

#include "utils.h"


string to_string_int_vector(vector<int> vector) {
    string result = "[";
    for (int i = 0; i < vector.size(); ++i) {
        result += std::to_string(vector[i]);
        if (i != vector.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

