#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph {
   private:
    int node_total;
    int **graph_matrix;

   public:
    Graph();
    Graph(int node_total);
    void addEdge(int node_1, int node_2, int weight);
    void printGraphMatrix();
    // Your code here
};

#endif  // GRAPH_HPP