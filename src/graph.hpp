#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

using namespace std;

class Graph {
   private:
    int node_total;
    int **graph_matrix;

    /*
        Função recursiva que realiza a busca em profundidade na matriz do grafo
        @param start: nó de inicio da DFS
        @param end: nó destino da busca
        @param &path: caminho que está sendo construído
        @param &paths: vetor de todos os caminhos construídos até o momento
        @param &visited: flag que mantém controle de quais nós já foram visitados na busca atual
    */
    void dfs(int start, int end, vector<int> &path, vector<vector<int>> &paths, vector<bool> &visited);

   public:
    Graph();

    // @param node_total: número de nós (cidades) no grafo
    Graph(int node_total);

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

    // Imprime a matriz de adjacência do grafo
    void printGraphMatrix();

    /*
        Calcula o peso total de um caminho
        @param &path: caminho cujo peso deve ser calculado
        @returns weight: peso total do caminho
    */
    int calcPathWeight(vector<int> &path);

    /*
        Encontra todos os caminhos possíveis entre dois nós do grafo, respeitando as condições impostas pelo problema
        O pair representa o caminho e o tamanho total dele
        @param start: começo do caminho
        @param end: fim do caminho
    */
    vector<vector<int>> findAllPaths(int start, int end);
};

#endif  // GRAPH_HPP