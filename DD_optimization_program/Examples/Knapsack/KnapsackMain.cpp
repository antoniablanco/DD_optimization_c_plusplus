//
// Created by antonia blanco on 18-01-24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Graph.h"
#include "Node.h"
#include "Arc.h"

using namespace std;

int main() {
    vector<int> aux = {1, 2, 3};
    Node<vector<int>> node_0(0, aux);
    Graph<vector<int>> graph(&node_0);


    return 0;
}
