
#include "DD.h"
#include "Node.h"
#include "Arc.h"
#include "Graph.h"
#include "DDBuilder.h"
#include "RestrictedDDBuilder.h"
#include "RelaxedDDBuilder.h"
#include "ReduceDDBuilder.h"

#include <thread>


DD::DD(AbstractProblem& problem, const bool verbose) : 
    problem(problem),
    graph_DD(create_desition_diagram(verbose))
    {}

DD::~DD() {}


Graph DD::create_desition_diagram(const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión..." << endl;
    auto start = chrono::steady_clock::now();

    DDBuilder dDBuilder(problem);
    Graph graph = dDBuilder.get_desition_diagram(verbose);
    
    auto end = chrono::steady_clock::now();
    cout << "Diagrama de decisión creado" << endl;
    
    dd_builder_time = chrono::duration<double>(end - start);
    return graph;
}

void DD::create_restricted_desition_diagram(int max_width, const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión restringido ..." << endl;
    auto start = chrono::steady_clock::now();

    RestrictedDDBuilder restrictedDDBuilder(problem, max_width);
    Graph graph = restrictedDDBuilder.get_desition_diagram(verbose);
    graph_DD = graph;

    auto end = chrono::steady_clock::now();
    cout << "Creación del diagrama de decision restringido terminado" << endl;
    
    restricted_dd_builder_time = chrono::duration<double>(end - start);
}

void DD::create_relaxed_desition_diagram(int max_width, const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión relajado ..." << endl;
    auto start = chrono::steady_clock::now();

    RelaxedDDBuilder relaxedDDBuilder(problem, max_width);
    Graph graph = relaxedDDBuilder.get_desition_diagram(verbose);
    graph_DD = graph;

    auto end = chrono::steady_clock::now();
    cout << "Creación del diagrama de decision relajado terminado" << endl;
    
    relaxed_dd_builder_time = chrono::duration<double>(end - start);
}

void DD::create_reduce_desition_diagram(const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión reducido ..." << endl;
    auto start = chrono::steady_clock::now();

    ReduceDDBuilder reduceDDBuilder(&graph_DD);
    Graph graph = reduceDDBuilder.get_desition_diagram(verbose);
    graph_DD = graph;

    auto end = chrono::steady_clock::now();
    cout << "Creación del diagrama de decision reducido terminado" << endl;
    
    reduce_dd_builder_time = chrono::duration<double>(end - start);
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

