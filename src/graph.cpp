#include "graph.hpp"

#include <iostream>

using namespace std;

Graph::Graph() {}

Graph::Graph(int node_total) {
    this->node_total = node_total;

    graph_matrix = new int *[node_total];
    for (int i = 0; i < node_total; i++) {
        graph_matrix[i] = new int[node_total];
    }
}

void Graph::addEdge(int node_1, int node_2, int weight) {
    graph_matrix[node_1 - 1][node_2 - 1] = graph_matrix[node_2 - 1][node_1 - 1] = weight;
}

void Graph::printGraphMatrix() {
    for (int i = 0; i < node_total; i++) {
        for (int j = 0; j < node_total; j++) std::cout << graph_matrix[i][j] << " ";

        std::cout << std::endl;
    }
}