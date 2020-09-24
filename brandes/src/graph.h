#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>

class Graph {
    private:
        std::vector<std::vector<int>> graph;
        std::vector<int> vertices;
        std::map<int, int> map;
        std::vector<bool> has_out_edges;
        int number_vertices;
    public:
        Graph() : graph(), vertices(), number_vertices(0) {}
        void add_vertex(int vertex) {
            if(map.find(vertex) == map.end()) {
                map.insert(std::pair<int, int>(vertex, number_vertices));
                vertices.push_back(vertex);
                graph.push_back(std::vector<int>());
                has_out_edges.push_back(false);
                number_vertices += 1;
            }
        }

        void add_edge(int source, int destination) {
            graph[map[source]].push_back(destination);
            has_out_edges[map[source]] = true;
        }

        int get_number_vertices() {
            return number_vertices;
        }

        int get_vertex(int index) {
            return vertices[index];
        }

        int get_index(int vertex) {
            return map[vertex];
        }
        
        std::vector<int>& get_neighbors(int vertex) {
            return graph[map[vertex]];
        }

        bool has_neighbors(int vertex) {
            return has_out_edges[map[vertex]];
        }
};

#endif
