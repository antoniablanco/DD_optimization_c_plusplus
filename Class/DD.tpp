#include "DD.h"
#include <utility>


template <typename T>
DD<T>::DD(AbstractProblem<T>& problem, const bool verbose) :
        problem(problem),
        graph_DD()
{
    createDecisionDiagram(verbose);
}

template <typename T>
DD<T>::~DD() {}

template <typename T>
void DD<T>::createDecisionDiagram(const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión..." << endl;
    auto start = chrono::steady_clock::now();
    DDBuilder dDBuilder(problem);
    Graph<T>* graph = dDBuilder.getDecisionDiagram(verbose);
    graph_DD = *graph;
    auto end = chrono::steady_clock::now();

    dd_builder_time = chrono::duration<double>(end - start);
    cout << "Diagrama de decisión creado"<< endl;

}

template <typename T>
void DD<T>::createRestrictedDecisionDiagram(int max_width, const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión restringido ..." << endl;
    auto start = chrono::steady_clock::now();

    RestrictedDDBuilder restrictedDDBuilder(problem, max_width);
    Graph<T>* graph = restrictedDDBuilder.getDecisionDiagram(verbose);
    graph_DD = *graph;
    auto end = chrono::steady_clock::now();

    restricted_dd_builder_time = chrono::duration<double>(end - start);
    cout << "Creación del diagrama de decision restringido terminado" << endl;
}

template <typename T>
void DD<T>::createRelaxedDecisionDiagram(int max_width, const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión relajado ..." << endl;
    auto start = chrono::steady_clock::now();

    RelaxedDDBuilder relaxedDDBuilder(problem, max_width);
    Graph<T>* graph = relaxedDDBuilder.getDecisionDiagram(verbose);
    graph_DD = *graph;

    auto end = chrono::steady_clock::now();
    cout << "Creación del diagrama de decision relajado terminado" << endl;

    relaxed_dd_builder_time = chrono::duration<double>(end - start);
}

template <typename T>
void DD<T>::createReduceDecisionDiagram(const bool verbose) {
    cout << endl;
    cout << "Iniciando la creación del diagrama de decisión reducido ..." << endl;
    auto start = chrono::steady_clock::now();

    ReduceDDBuilder reduceDDBuilder(&graph_DD, problem);
    Graph<T> graph = reduceDDBuilder.GetDecisionDiagram(verbose);
    graph_DD = graph;

    auto end = chrono::steady_clock::now();
    cout << "Creación del diagrama de decision reducido terminado" << endl;

    reduce_dd_builder_time = chrono::duration<double>(end - start);
}

template <typename T>
string DD<T>::getDdBuilderTime() {
    return to_string(dd_builder_time.count());
}

template <typename T>
string DD<T>::getReduceDdBuilderTime() {
    return to_string(reduce_dd_builder_time.count());
}

template <typename T>
string DD<T>::getRestrictedDdBuilderTime() {
    return to_string(restricted_dd_builder_time.count());
}

template <typename T>
string DD<T>::get_relaxed_dd_builder_time() {
    return to_string(relaxed_dd_builder_time.count());
}

template <typename T>
Graph<T>& DD<T>::get_desition_diagram() {
    if (graph_DD.nodes.empty()) {
        cout << "No se encuentra guardado el grafo, revisar su construcción" << endl;
        exit(1);
    }
    return graph_DD;
}

template <typename T>
Graph<T> DD<T>::get_desition_diagram_copy() {
    if (graph_DD.nodes.empty()) {
        cout << "No se encuentra guardado el grafo, revisar su construcción" << endl;
        exit(1);
    }
    Graph graphCopy(graph_DD);
    return graphCopy;
}

template <typename T>
void DD<T>::export_graph_file(string file_name) {
    GraphFile graphFile(std::move(file_name), graph_DD, problem);
}
