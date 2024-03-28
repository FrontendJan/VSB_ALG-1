#include "../include/graph.h"
#include <iostream>

int main() {
    std::string filename = "../data/graph.txt";
    Graph graph = readGraphFromFile(filename);
    printGraph(graph);

    std::vector<std::vector<int>> adjacencyMatrix = createAdjacencyMatrix(graph);
    std::cout << "Adjacency Matrix:" << std::endl;
    printMatrix(adjacencyMatrix);

    return 0;
}