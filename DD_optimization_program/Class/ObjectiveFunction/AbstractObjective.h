
#ifndef DD_OPTIMIZATION_PROGRAM_ABSTRACTOBJECTIVE_H
#define DD_OPTIMIZATION_PROGRAM_ABSTRACTOBJECTIVE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

#include "Graph.h"
#include "Arc.h"

using namespace std;

class AbstractObjective {

    public:
    AbstractObjective();
    virtual void assign_graph(Graph graph_DD) = 0;
    virtual tuple<int, string, vector<Arc*>> resolve_graph() = 0;

    virtual ~AbstractObjective();
};

#endif //DD_OPTIMIZATION_PROGRAM_ABSTRACTOBJECTIVE_H