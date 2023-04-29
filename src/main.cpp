#include <iostream>

#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    // node_total: N, edge_total: A
    int node_total, edge_total;
    std::cin >> node_total >> edge_total;

    Graph *travel_graph = new Graph(node_total);

    int node_1, node_2, weight;
    for (int i = 0; i < edge_total; i++) {
        std::cin >> node_1 >> node_2 >> weight;

        if (weight % 2 == 0) {
            travel_graph->addEdge(node_1, node_2, weight);
        }
    }

    travel_graph->printGraphMatrix();

    return 0;
}