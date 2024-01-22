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

string to_string_string_vector(vector<string> vector) {
    string result = "[";
    for (int i = 0; i < vector.size(); ++i) {
        result += vector[i];
        if (i != vector.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

void remove_int_vector(vector<int> &vector, int value) {

    auto it = std::find(vector.begin(), vector.end(), value);
    if (it != vector.end()) {
        vector.erase(it);
    }
}
