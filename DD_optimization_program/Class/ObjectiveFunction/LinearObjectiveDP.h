
#ifndef DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H
#define DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <limits>

#include "AbstractObjective.h"
#include "ObjectiveStructure.h"

using namespace std;

class LinearObjectiveDP : public AbstractObjective {

    public:
    LinearObjectiveDP(vector<int> weights, string objective);
    void assign_graph(Graph graph_DD) override;
    ObjectiveStruct resolve_graph() override;

    ~LinearObjectiveDP()= default;

    private:
    vector<int> weights;
    string objective;
    Graph graph;
    int neutro = -111111;
    vector<ObjectiveStruct*> DP;
    
    void choose_transform_weights();
    ObjectiveStruct* dp(Node node, int layer);
};


#endif //DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H