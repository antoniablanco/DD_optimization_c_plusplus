
#ifndef DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H
#define DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "AbstractObjective.h"

using namespace std;

class LinearObjectiveDP : public AbstractObjective {

    public:
    LinearObjectiveDP(list<int> weights, string objective);
    void assign_graph(Graph graph_DD) override;
    tuple<int, string, vector<Arc*>> resolve_graph() override;

    ~LinearObjectiveDP();

    private:
    list<int> weights;
    string objective;
    
    void choose_transform_weights();
    tuple<int, string, vector<Arc*>> dp(Node node, int layer);
};


#endif //DD_OPTIMIZATION_PROGRAM_LINEAROBJECTIVEDP_H