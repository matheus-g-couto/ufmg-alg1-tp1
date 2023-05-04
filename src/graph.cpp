#include "graph.hpp"

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

Graph::Graph() {}

Graph::Graph(int node_total) {
    this->node_total = node_total;
    this->adjacency_list.resize(node_total);
    this->transformed_adjacency_list.resize(node_total);
}

Graph::~Graph() {
    this->adjacency_list.resize(0);
    this->transformed_adjacency_list.resize(0);
    this->node_total = -1;
}

void Graph::addEdge(int node_1, int node_2, int weight) {
    adjacency_list[node_1 - 1].push_back({node_2 - 1, weight});
    adjacency_list[node_2 - 1].push_back({node_1 - 1, weight});
}

void Graph::transformGraph() {
    for (int i = 0; i < node_total; i++) {
        for (auto edge : this->adjacency_list[i]) {
            for (auto second_edge : this->adjacency_list[edge.first]) {
                if (second_edge.first > i) {
                    transformed_adjacency_list[i].push_back({second_edge.first, edge.second + second_edge.second});
                    transformed_adjacency_list[second_edge.first].push_back({i, edge.second + second_edge.second});
                }
            }
        }
    }
}

void Graph::dijkstra(vector<int> &path_weights) {
    path_weights.assign(this->node_total, INF);
    path_weights[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    // {vertice, distancia}
    heap.push({0, 0});

    while (!heap.empty()) {
        int v = heap.top().first;
        int dist = heap.top().second;
        heap.pop();

        if (dist > path_weights[v]) continue;

        for (auto edge : this->transformed_adjacency_list[v]) {
            if (path_weights[v] + edge.second < path_weights[edge.first]) {
                path_weights[edge.first] = path_weights[v] + edge.second;
                heap.push({edge.first, path_weights[edge.first]});
            }
        }
    }
}

int Graph::findPath() {
    vector<int> path_weights;
    path_weights.resize(this->node_total);

    this->transformGraph();
    this->dijkstra(path_weights);

    return path_weights[this->node_total - 1];
}

int Graph::getNodeTotal() { return this->node_total; }

void Graph::printAdjacencyList() {
    for (int i = 0; i < node_total; i++) {
        std::cout << "Node " << i << ": { ";
        for (int j = 0; j < (int)transformed_adjacency_list[i].size(); j++) {
            std::cout << "(" << transformed_adjacency_list[i][j].first << "," << transformed_adjacency_list[i][j].second
                      << ") ";
        }
        std::cout << "}" << std::endl;
    }
}
