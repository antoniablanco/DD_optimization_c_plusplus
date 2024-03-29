#ifndef TEMPLATETYPE_DD_H
#define TEMPLATETYPE_DD_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>
#include <chrono>
#include <memory>
#include <thread>

#include "AbstractProblemClass.h"
#include "Graph.h"
#include "GraphFile.h"
#include "DDBuilder.h"
#include "RestrictedDDBuilder.h"
#include "RelaxedDDBuilder.h"
#include "ReduceDDBuilder.h"

using namespace std;

/**
 * @brief Clase que representa un controlador del diagrama de decisión asociado a un problema (DD).
 */
template <typename T>
class DD {
public:
    /**
     * @brief Constructor de la clase DD.
     * @param problem Referencia a un objeto de la clase AbstractProblem que representa el problema a resolver.
     * @param verbose Booleano que indica si se debe visualizar el proceso de construcción del grafo de decisión.
     */
    DD(AbstractProblem<T>& problem, const bool verbose = false);

    AbstractProblem<T>& problem; /**< Referencia al problema a resolver. */

    /**
     * @brief Crea un diagrama de decisión reducido y lo guarda en el atributo graph_DD.
     * @param verbose Booleano que indica si se mostrarán mensajes de progreso durante la construcción del diagrama.
     */
    void create_reduce_decision_diagram(const bool verbose = false);

    /**
     * @brief Crea un diagrama de decisión restringido y lo guarda en el atributo graph_DD.
     * @param verbose Booleano que indica si se mostrarán mensajes de progreso durante la construcción del diagrama.
     */
    void create_restricted_decision_diagram(int max_width, const bool verbose = false);

    /**
     * @brief Crea un diagrama de decisión relajado y lo guarda en el atributo graph_DD.
     * @param verbose Booleano que indica si se mostrarán mensajes de progreso durante la construcción del diagrama.
     */
    void create_relaxed_decision_diagram(int max_width, const bool verbose = false);

    /**
     * @brief Exporta el grafo de decisión a un archivo.
     * @param file_name Nombre del archivo.
     */
    void export_graph_file(string file_name);

    /**
     * @brief Obtiene una referencia al grafo del diagrama de decisión.
     * @return Referencia al grafo del diagrama de decisión.
     */
    Graph<T>& get_desition_diagram();

    /**
     * @brief Obtiene una copia única del grafo del diagrama de decisión.
     * @return Puntero único al grafo del diagrama de decisión.
     */
    Graph<T> get_desition_diagram_copy();

    // Métodos que obtienen el tiempo de construcción de los diagramas de decisión.
    string get_dd_builder_time();
    string get_reduce_dd_builder_time();
    string get_restricted_dd_builder_time();
    string get_relaxed_dd_builder_time();

    /**
     * @brief Destructor de la clase DD.
     */
    ~DD();

private:
    /**
     * @brief Crea el diagrama de decisión.
     * @param verbose Booleano que indica si se mostrarán mensajes de progreso durante la construcción del diagrama.
     */
    void createDecisionDiagram(const bool verbose = false);
    Graph<T> graph_DD; /**< Grafo del diagrama de decisión. */

    // Atributos que almacenan el tiempo de construcción de los diagramas de decisión.
    chrono::duration<double>  dd_builder_time = chrono::duration<double>(0);
    chrono::duration<double>  reduce_dd_builder_time = chrono::duration<double>(0);
    chrono::duration<double>  restricted_dd_builder_time = chrono::duration<double>(0);
    chrono::duration<double>  relaxed_dd_builder_time = chrono::duration<double>(0);

};

#include "DD.tpp"
#endif //TEMPLATETYPE_DD_H
