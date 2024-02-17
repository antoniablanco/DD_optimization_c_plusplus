#ifndef TEMPLATETYPE_GRAPHFILE_H
#define TEMPLATETYPE_GRAPHFILE_H

#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"

#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

/**
 * @brief Clase que representa un archivo de grafo.
 */
template <typename T>
class GraphFile {
public:
    /**
     * @brief Constructor de la clase GraphFile.
     * @param file_name Nombre del archivo de grafo.
     * @param graph Grafo que se va a escribir en el archivo.
     */
    GraphFile(const string& file_name, Graph<T>& graph, AbstractProblem<T>& problem);

    /**
     * @brief Constructor por defecto de la clase GraphFile.
     */
    GraphFile() = default;

    /**
     * @brief Escribe el grafo en el archivo.
     */
    ~GraphFile() = default;

private:
    string file_name; /**< Nombre del archivo de grafo. */
    Graph<T> graph; /**< Grafo que se va a escribir en el archivo. */
    bool is_graph_binary; /**< Indica si el grafo es binario. */
    ofstream* bdd_file; /**< Puntero al archivo de grafo. */
    AbstractProblem<T>& problem; /**< Referencia al problema asociado al grafo. */

    /**
     * @brief Crea el archivo de grafo.
     */
    void create_gml_file();

    // Métodos que trabajan a partir de la estructura de nodos del grafo para representarlos en el archivo .gml
    void start_file();
    void add_nodes_and_arcs();
    bool check_if_graph_is_binary();
    bool is_node_binary(Node<T>* node);
    void add_node(Node<T>* node);
    void add_arcs(const vector<Arc<T>*>& arcs);
    void add_arc(Arc<T>* arc);
    void add_arc_source(Arc<T>* arc);
    void add_arc_label(Arc<T>* arc);
    void add_arc_target(Arc<T>* arc);
    void add_arc_graphics(Arc<T>* arc);
    void add_normal_arc_graphics(Arc<T>* arc);
    void add_binary_arc_graphics(Arc<T>* arc);
    void end_file();
};
#include "GraphFile.tpp"
#endif //TEMPLATETYPE_GRAPHFILE_H
