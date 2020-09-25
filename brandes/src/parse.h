#ifndef PARSE_H
#define PARSE_H

#include <fstream>
#include <sstream>
#include <string>

#include "graph.h"

class Parser {
    private:
        Graph graph;
        std::ifstream input_file;
        std::vector<std::pair<int, int>> edges;
        
    public:
        Parser(std::string filename) : graph(), input_file(filename) {
            read_file();
            add_vertices();
            add_edge();
        }

        Graph& get_graph() {
            return graph;
        }
    
    private:
        void read_file() {
            std::string edge;
            
            while (std::getline(input_file, edge)) {
                parse_edge(edge);
            }
        }

        void parse_edge(std::string edge) {
            std::stringstream sstream(edge);
            int source, destination;
            sstream >> source >> destination;
            edges.push_back(std::pair<int, int>(source, destination));
        }

        void add_vertices() {
            for(auto edge : edges) {
                graph.add_vertex(edge.first);
                graph.add_vertex(edge.second);
            }
        }

        void add_edge() {
            for(auto edge : edges) {
                graph.add_edge(edge.first, edge.second);
            }
        }
};

#endif
