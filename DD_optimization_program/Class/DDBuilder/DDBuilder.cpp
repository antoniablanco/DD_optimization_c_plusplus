
#include "DDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;


DDBuilder::DDBuilder(AbstractProblem& problem) : AbstractDDBuilder(problem) {}

void DDBuilder::specificLayerFunction() {
}

void DDBuilder::specific_final_function() {
}
