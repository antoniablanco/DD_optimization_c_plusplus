
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

class GraphFile {
public:
    GraphFile() = default;
    GraphFile(string file_name, Graph& graph);
    ~GraphFile() = default;

private:
    string file_name;
    Graph graph;
    bool is_graph_binary;
    ofstream* bdd_file;
    
    void create_gml_file();
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
