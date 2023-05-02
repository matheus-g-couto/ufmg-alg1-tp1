#include "graph.hpp"

#include <iostream>
#include <vector>

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

int Graph::getNodeTotal() { return this->node_total; }

void Graph::printGraphMatrix() {
    for (int i = 0; i < node_total; i++) {
        for (int j = 0; j < node_total; j++) {
            std::cout << graph_matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

// Busca em profundidade
void Graph::dfs(int start, int end, vector<int> &path, vector<vector<int>> &paths, vector<bool> &visited) {
    visited[start] = true;
    path.push_back(start);

    if (start == end) {
        // Só armazena os caminhos com número ímpar de nós, portanto par de arestas
        if ((int)path.size() % 2 == 1) paths.push_back(path);
    } else {
        for (int i = 0; i < this->node_total; i++) {
            if (graph_matrix[start][i]) {
                if (!visited[i]) dfs(i, end, path, paths, visited);
            }
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
        weight += graph_matrix[path[i]][path[i + 1]];
    }

    return weight;
}