
#include "DD.h"


DD::DD(AbstractProblem& problem, const bool verbose) : 
    problem(problem),
    graph_DD()
    {
        create_desition_diagram(verbose);
    }

DD::~DD() {}

void DD::create_desition_diagram(const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión..." << endl;
    auto start = chrono::steady_clock::now();
    DDBuilder dDBuilder(problem);
    Graph* graph = dDBuilder.get_desition_diagram(verbose);
    graph_DD = *graph;
    auto end = chrono::steady_clock::now();
    
    dd_builder_time = chrono::duration<double>(end - start);
    cout << "Diagrama de decisión creado"<< endl;

}

void DD::create_restricted_desition_diagram(int max_width, const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión restringido ..." << endl;
    auto start = chrono::steady_clock::now();

    RestrictedDDBuilder restrictedDDBuilder(problem, max_width);
    Graph* graph = restrictedDDBuilder.get_desition_diagram(verbose);
    graph_DD = *graph;
    auto end = chrono::steady_clock::now();
    
    restricted_dd_builder_time = chrono::duration<double>(end - start);
    cout << "Creación del diagrama de decision restringido terminado" << endl;
}

void DD::create_relaxed_desition_diagram(int max_width, const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión relajado ..." << endl;
    auto start = chrono::steady_clock::now();

    RelaxedDDBuilder relaxedDDBuilder(problem, max_width);
    Graph* graph = relaxedDDBuilder.get_desition_diagram(verbose);
    graph_DD = *graph;

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
    if (graph_DD.nodes.empty()) {
        cout << "No se encuentra guardado el grafo, revisar su construcción" << endl;
        exit(1);
    }
    return graph_DD;
}

Graph DD::get_desition_diagram_copy() {
    if (graph_DD.nodes.empty()) {
        cout << "No se encuentra guardado el grafo, revisar su construcción" << endl;
        exit(1);
    }
    Graph graphCopy(graph_DD);
    return graphCopy; 
}

void DD::export_graph_file(string file_name) {
    GraphFile graphFile(file_name, graph_DD);
}