// graph.cpp
#include "../include/graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_set>

Graph readGraphFromFile(const std::string& filename) {
    Graph graph;
    std::ifstream file(filename);
       if (!file.is_open()) {
           std::cout << "Failed to open file: " << filename << std::endl;
           return graph;
       }
    std::string line;
    std::unordered_set<int> unique_vertices;

    while (std::getline(file, line)) {
        std::cout << "Reading file: " << filename << std::endl;

        std::cout << "Read line: " << line << std::endl;
        std::stringstream ss(line);
        int vertex;
        char colon;
        ss >> vertex >> colon;
        std::cout << "Vertex: " << vertex << std::endl;
        unique_vertices.insert(vertex);

        int neighbor;
        while (ss >> neighbor) {
            std::cout << "Neighbor: " << neighbor << std::endl;
            graph.adjacency_list[vertex].push_back(neighbor);
            unique_vertices.insert(neighbor);
            graph.no_of_edges++;
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
    }

    file.close();
    graph.no_of_vertices = unique_vertices.size();
    return graph;
}

std::vector<std::vector<int>> createAdjacencyMatrix(const Graph& graph) {
    int n = graph.no_of_vertices;
    std::cout << "Number of vertices: " << n << std::endl;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    for (const auto& pair : graph.adjacency_list) {
        int vertex = pair.first;
        const std::vector<int>& neighbors = pair.second;
        for (int neighbor : neighbors) {
            matrix[vertex][neighbor] = 1;
        }
    }

    return matrix;
}


void printGraph(const Graph& graph) {
    std::cout << "Graph:\n";
    for (const auto& pair : graph.adjacency_list) {
        int vertex = pair.first;
        const std::vector<int>& neighbors = pair.second;
        std::cout << vertex << ": ";
        for (int neighbor : neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& line : matrix) {
        for (int val : line) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}