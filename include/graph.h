#pragma once

#include <unordered_map>
#include <vector>
#include <string>

struct Graph {
    std::unordered_map<int, std::vector<int>> adjacency_list;
    int no_of_vertices;
    int no_of_edges;
};

Graph readGraphFromFile(const std::string& filename);
void printGraph(const Graph& graph);
std::vector<std::vector<int>> createAdjacencyMatrix(const Graph& graph);
void printMatrix(const std::vector<std::vector<int>>& matrix);