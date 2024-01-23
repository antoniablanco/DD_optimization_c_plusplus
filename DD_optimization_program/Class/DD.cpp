
#include "DD.h"
#include "Node.h"
#include "Arc.h"
#include "Graph.h"

#include <thread>

DD::DD(AbstractProblem& problem, const bool verbose) : 
    problem(problem),
    dd_builder_time(0),  
    reduce_dd_builder_time(0),
    restricted_dd_builder_time(0),
    relaxed_dd_builder_time(0),
    graph_DD(create_desition_diagram(verbose))
    {}

Graph DD::create_desition_diagram(const bool verbose) {
    std::cout << "Iniciando la creación del diagrama de decisión..." << std::endl;
    auto start = chrono::high_resolution_clock::now();
    Node node_0(0, {0});
    Graph graph(node_0);

    auto wake_up_time = std::chrono::system_clock::now() + std::chrono::seconds(3);

    // Dormir hasta que se alcance el tiempo deseado
    std::this_thread::sleep_until(wake_up_time);

    auto end = chrono::high_resolution_clock::now();
    
    std::cout << "Diagrama de decisión creado" << std::endl;
    dd_builder_time = end - start;
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
