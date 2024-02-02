#include "GraphFile.h"

GraphFile::GraphFile(string file_name, Graph& graph) : file_name(file_name), graph(graph) {

    string source_directory = fs::current_path().parent_path().string();
    string full_file_path = source_directory + "/DD_optimization_program/" + file_name + ".gml";

    bdd_file = new ofstream(full_file_path);
    is_graph_binary = check_if_graph_is_binary();
    create_gml_file();

}

bool GraphFile::check_if_graph_is_binary() {
    for (auto& layer: graph.structure) {
        for (auto& node: layer) {
            if (!is_node_binary(node)) {
                return false;
            }
        }
    }    
    return true;
}

bool GraphFile::is_node_binary(Node* node) {
    for (auto& arc: node->out_arcs) {
        if (arc->variable_value != 0 && arc->variable_value != 1) {
            return false;
        }
    }

    return true;
}

void GraphFile::create_gml_file() {
    start_file();
    add_nodes_and_arcs();
    end_file();
}

void GraphFile::start_file() {
    (*bdd_file) << "graph [\n";
    (*bdd_file) << "\t directed 1\n";
    (*bdd_file) << "\t hierarchic 1\n";
}

void GraphFile::add_nodes_and_arcs() {
    vector<Arc*> arcs = {};
    for (auto& layer: graph.structure) {
        for (auto& node: layer) {
            add_node(node);
            for (auto& arc: node->out_arcs) {
                arcs.push_back(arc);
            }
        }
    }  
    add_arcs(arcs);
}

void GraphFile::add_node(Node* node) {
    (*bdd_file) << "\n node [\n";
    (*bdd_file) << "\t id " << node->id << "\n";
    (*bdd_file) << "\t label \"" << node->id << "             " << to_string_int_vector(node->state) << "\"\n";
    (*bdd_file) << " \tgraphics [\n";
    (*bdd_file) << "\t type \"ellipse\"\n";
    (*bdd_file) << "\t hasFill 0\n";
    (*bdd_file) << "\t w 90.0   h 110.0\n";
    (*bdd_file) << "\t outline \"#000000\" ]\n";
    (*bdd_file) << "]\n";
    (*bdd_file) << " \tLabelGraphics [\n";
    (*bdd_file) << "\t text \"" << node->id << "             " << to_string_int_vector(node->state) << "\"\n";
    (*bdd_file) << "\t fontSize 12\n";
    (*bdd_file) << "\t fontName \"Dialog\"\n";
    (*bdd_file) << "\t model \"sides\"\n";
    (*bdd_file) << "\t anchor \"e\"\n";
    (*bdd_file) << "\t borderDistance -50.0\n";
    (*bdd_file) << "]\n";
}

void GraphFile::add_arcs(vector<Arc*> arcs) {
    for (auto& arc: arcs) {
        add_arc(arc);
    }
}

void GraphFile::add_arc(Arc* arc) {
    (*bdd_file) << "\nedge [\n";
    add_arc_source(arc);
    add_arc_target(arc);

    if (not is_graph_binary) {
        add_arc_label(arc);
    }

    add_arc_graphics(arc);
    (*bdd_file) <<"]\n";
}

void GraphFile::add_arc_source(Arc* arc) {
    (*bdd_file) << "\t source " << arc->out_node->id << "\n";
}

void GraphFile::add_arc_label(Arc* arc) {
    (*bdd_file) << "\tlabel \"" << arc->variable_value << "\"\n";
}

void GraphFile::add_arc_target(Arc* arc) {
    (*bdd_file) << "\ttarget " << arc->in_node->id << "\n";
}

void GraphFile::add_arc_graphics(Arc* arc) {
    (*bdd_file) << "\tgraphics [\n";
    
    if (is_graph_binary) {
        add_binary_arc_graphics(arc);
    } else {
        add_normal_arc_graphics(arc);
    }
    (*bdd_file) << "]";
}

void GraphFile::add_normal_arc_graphics(Arc* arc) {
    (*bdd_file) << "\tfill \"#000000\" 		targetArrow \"standard\"	 	 \n";
}

void GraphFile::add_binary_arc_graphics(Arc* arc) {
    if (arc->variable_value == 0) {
        (*bdd_file) << "\tfill \"#808080\" 		targetArrow \"standard\"	  style	  \"dashed\"	\n";
    } else {
        (*bdd_file) << "\tfill \"#000000\" 		targetArrow \"standard\"	 	 \n";
    }
}

void GraphFile::end_file() {
    (*bdd_file) << "]\n";
    bdd_file->close();
}
