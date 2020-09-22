#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Graph {
private:
    std::vector<std::vector<int>> graph;
    std::vector<int> orderable_vertices;
    std::unordered_set<int> vertices;
    std::unordered_map<int, int> map;
    std::vector<bool> has_out_edges;
    int number_vertices;
public:
    Graph() : graph(), vertices(), number_vertices(0) {}
    void add_vertex(int vertex) {
        if(vertices.find(vertex) == vertices.end()) {
            vertices.insert(vertex);
            orderable_vertices.push_back(vertex);

            graph.push_back(std::vector<int>());
            has_out_edges.push_back(false);
            number_vertices += 1;
        }
    }

    void add_edge(int source, int destination) {
        graph[source].push_back(destination);
    }
};

#endif