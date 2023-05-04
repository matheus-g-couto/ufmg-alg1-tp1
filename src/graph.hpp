#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

using namespace std;

class Graph {
   private:
    int node_total;
    vector<vector<pair<int, int>>> adjacency_list;
    vector<vector<pair<int, int>>> transformed_adjacency_list;

    /*
        Processa o grafo original, de maneira que cada par de arestas (u,v) e (v,w) no grafo original se transforma numa
        aresta (u,w) com os pesos das outras duas somados
    */
    void transformGraph();

    /*
        Executa o algoritmo de Dijkstra no grafo transformado
        @param &path_weights: vetor que armazena a distância mínima entre a origem e todos os vértices do grafo
    */
    void dijkstra(vector<int> &path_weights);

   public:
    Graph();

    // @param node_total: número de nós (cidades) no grafo
    Graph(int node_total);

    ~Graph();

    /*
        Adicona uma aresta ao grafo
        @param node_1: extremidade da aresta
        @param node_2: extremidade da aresta
        @param weight: peso da aresta, que corresponde à distância entre as cidades
    */
    void addEdge(int node_1, int node_2, int weight);

    /*
        Retorna o total de nós do grafo
        @returns node_total: total de nós do grafo
    */
    int getNodeTotal();

    // Imprime a lista de adjacências do grafo
    void printAdjacencyList();

    /*
        Encontra o caminho mais curto entre a origem e o destino
        @returns distance: menor distância entre a origem e o destino
    */
    int findPath();
};

#endif  // GRAPH_HPP