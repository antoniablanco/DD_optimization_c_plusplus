
#ifndef DD_OPTIMIZATION_PROGRAM_NODE_H
#define DD_OPTIMIZATION_PROGRAM_NODE_H

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Arc;

template <typename T>
class Node {
public:
    Node(int id, T state);
    int id;
    T state;
    std::vector<Arc<T>*> in_arcs;
    std::vector<Arc<T>*> out_arcs;

    std::string to_string();
    void add_in_arc(Arc<T>* arc);
    void add_out_arc(Arc<T>* arc);
    void remove_in_arc(Arc<T>* arc);
    void remove_out_arc(Arc<T>* arc);
};

#endif //DD_OPTIMIZATION_PROGRAM_NODE_H
