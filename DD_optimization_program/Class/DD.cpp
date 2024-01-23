
#include "DD.h"
#include "Node.h"
#include "Arc.h"
#include "Graph.h"
#include "DDBuilder.h"

#include <thread>

DD::DD(AbstractProblem& problem, const bool verbose) : 
    problem(problem),
    graph_DD(create_desition_diagram(verbose))
    {}

Graph DD::create_desition_diagram(const bool verbose) {
    cout << "Iniciando la creación del diagrama de decisión..." << endl;
    auto start = chrono::steady_clock::now();

    Graph graph = DDBuilder(problem).get_desition_diagram(verbose);
    
    auto end = chrono::steady_clock::now();
    cout << "Diagrama de decisión creado" << endl;
    
    dd_builder_time = chrono::duration<double>(end - start);
    return graph;
}

string DD::get_dd_builder_time() {
    return to_string(dd_builder_time.count());
}

string DD::get_reduce_dd_builder_time() {
    return to_string(reduce_dd_builder_time.count());
}

string DD::get_restricted_dd_builder_time() {
    return to_string(restricted_dd_builder_time.count());
}

string DD::get_relaxed_dd_builder_time() {
    return to_string(relaxed_dd_builder_time.count());
}

Graph& DD::get_desition_diagram() {
    return graph_DD;
}

unique_ptr<Graph> DD::get_desition_diagram_copy() {
    auto graphCopy = make_unique<Graph>(graph_DD);
    return graphCopy;
}