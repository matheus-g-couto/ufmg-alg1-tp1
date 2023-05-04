#include "graph.hpp"

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

Graph::Graph() {}

Graph::Graph(int node_total) {
    this->node_total = node_total;
    this->adjacency_list.resize(node_total);
}

Graph::~Graph() {
    this->adjacency_list.resize(0);
    this->node_total = -1;
}

void Graph::addEdge(int node_1, int node_2, int weight) {
    adjacency_list[node_1 - 1].push_back({node_2 - 1, weight});
    adjacency_list[node_2 - 1].push_back({node_1 - 1, weight});
}

int Graph::getNodeTotal() { return this->node_total; }

// Busca em profundidade
void Graph::dfs(int start, int end, vector<int> &path, vector<vector<int>> &paths, vector<bool> &visited) {
    visited[start] = true;
    path.push_back(start);

    if (start == end) {
        // Só armazena os caminhos com número ímpar de nós, portanto par de arestas
        if ((int)path.size() % 2 == 1) paths.push_back(path);
    } else {
        for (auto v : this->adjacency_list[start]) {
            // v.first: identificador do nó vizinho
            if (!visited[v.first]) dfs(v.first, end, path, paths, visited);
        }
    }

    path.pop_back();
    visited[start] = false;
}

vector<vector<int>> Graph::findAllPaths(int start, int end) {
    vector<vector<int>> paths;  // Todos os caminhos já explorados
    vector<int> path;           // Caminho sendo explorado no momento
    vector<bool> visited(this->node_total, false);

    dfs(start, end, path, paths, visited);
    return paths;
}

int Graph::calcPathWeight(vector<int> &path) {
    int weight = 0;
    int path_size = path.size();

    for (int i = 0; i < path_size - 1; i++) {
        for (auto node : this->adjacency_list[path[i]]) {
            if (node.first == path[i + 1]) {
                weight += node.second;
                break;
            }
        }
    }

    return weight;
}