
#ifndef DD_OPTIMIZATION_PROGRAM_GRAPHFILE_H
#define DD_OPTIMIZATION_PROGRAM_GRAPHFILE_H

#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"
#include "Node.h"
#include "Arc.h"
#include "utils.h"

#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

/**
 * @brief Clase que representa un archivo de grafo.
 */
class GraphFile {
public:
    /**
     * @brief Constructor de la clase GraphFile.
     * @param file_name Nombre del archivo de grafo.
     * @param graph Grafo que se va a escribir en el archivo.
     */
    GraphFile(string file_name, Graph& graph);

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
    Graph graph; /**< Grafo que se va a escribir en el archivo. */
    bool is_graph_binary; /**< Indica si el grafo es binario. */
    ofstream* bdd_file; /**< Puntero al archivo de grafo. */
    
    /**
     * @brief Crea el archivo de grafo.
     */
    void create_gml_file();

    // Métodos que trabajan a partir de la estructura de nodos del grafo para representarlos en el archivo .gml
    void start_file();
    void add_nodes_and_arcs();
    bool check_if_graph_is_binary();
    bool is_node_binary(Node* node);
    void add_node(Node* node);
    void add_arcs(vector<Arc*> arcs);
    void add_arc(Arc* arc);
    void add_arc_source(Arc* arc);
    void add_arc_label(Arc* arc);
    void add_arc_target(Arc* arc);
    void add_arc_graphics(Arc* arc);
    void add_normal_arc_graphics(Arc* arc);
    void add_binary_arc_graphics(Arc* arc);
    void end_file();
};

#endif //DD_OPTIMIZATION_PROGRAM_GRAPHFILE_H
