#ifndef DD_OPTIMIZATION_PROGRAM_DD_H
#define DD_OPTIMIZATION_PROGRAM_DD_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>
#include <chrono>
#include <memory>

#include "Problems/AbstractProblemClass.h"
#include "DDStructure/Graph.h"

using namespace std;

class DD {
public:
    DD(AbstractProblem& problem, const bool verbose = false);

    AbstractProblem& problem;

    void create_reduce_desition_diagram(const bool verbose = false);
    void create_restricted_desition_diagram(int max_width, const bool verbose = false);
    void create_relaxed_desition_diagram(int max_width, const bool verbose = false);
    void print_desition_diagram();
    void export_graph_file(string file_name);
    Graph& get_desition_diagram();
    unique_ptr<Graph> get_desition_diagram_copy();

    string get_dd_builder_time();
    string get_reduce_dd_builder_time();
    string get_restricted_dd_builder_time();
    string get_relaxed_dd_builder_time();

private:

    Graph create_desition_diagram(const bool verbose = false);
    Graph graph_DD;

    chrono::duration<double>  dd_builder_time = chrono::duration<double>(0);
    chrono::duration<double>  reduce_dd_builder_time = chrono::duration<double>(0);
    chrono::duration<double>  restricted_dd_builder_time = chrono::duration<double>(0);
    chrono::duration<double>  relaxed_dd_builder_time = chrono::duration<double>(0);

};


#endif //DD_OPTIMIZATION_PROGRAM_DD_H