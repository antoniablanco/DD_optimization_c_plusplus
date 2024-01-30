
#ifndef DD_OPTIMIZATION_PROGRAM_OBJECTIVESTRUCTURE_H
#define DD_OPTIMIZATION_PROGRAM_OBJECTIVESTRUCTURE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

#include "Graph.h"
#include "Arc.h"

using namespace std;

struct ObjectiveStruct {
    int value;
    string path;
    vector<Arc*> arcs;

    ObjectiveStruct();
};

#endif //DD_OPTIMIZATION_PROGRAM_OBJECTIVESTRUCTURE_H