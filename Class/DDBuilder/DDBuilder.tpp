#include "DDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <typename T>
DDBuilder<T>::DDBuilder(AbstractProblem<T>& problem) : AbstractDDBuilder<T>(problem) {}

template <typename T>
void DDBuilder<T>::specificLayerFunction() {
}

template <typename T>
void DDBuilder<T>::specific_final_function() {
}
