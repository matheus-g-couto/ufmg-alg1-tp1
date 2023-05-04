#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    // @var node_total: N
    int node_total, edge_total;
    std::cin >> node_total >> edge_total;

    Graph *travel_graph = new Graph(node_total);

    int node_1, node_2, weight;
    for (int i = 0; i < edge_total; i++) {
        std::cin >> node_1 >> node_2 >> weight;

        // adiciona ao grafo apenas as arestas pares
        if (weight % 2 == 0) {
            travel_graph->addEdge(node_1, node_2, weight);
        }
    }

    vector<vector<int>> paths = travel_graph->findAllPaths(0, node_total - 1);
    int min_weight = INT_MAX;
    if (paths.empty())
        min_weight = -1;
    else {
        vector<int> sizes;
        for (auto path : paths) {
            int path_weight = travel_graph->calcPathWeight(path);

            if (path_weight < min_weight) min_weight = path_weight;
            sizes.push_back(path_weight);
        }
    }

    std::cout << min_weight << std::endl;

    delete travel_graph;

    return 0;
}