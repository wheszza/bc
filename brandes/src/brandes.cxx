#include <iostream>
#include <fstream>
#include <string>

#include "graph.h"
#include "dependency_calculator.h"
#include "parse.h"

std::string input_file;
std::string output_file;

Graph graph;
std::vector<double> betweenness;

void parse_args(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr
            << "USAGE: ./brandes  <input-file> <output-file>"
            << std::endl;
        exit(1);
    }

    input_file = argv[1];
    output_file = argv[2];
}

void parse_input() {
    Parser parser(input_file);
    graph = parser.get_graph();
}

void init() {
    for(int index = 0; index < graph.get_number_vertices(); index++) {
        betweenness.push_back(0);
    }
}

void calculate_betweenness() {
    for(int index = 0; index < graph.get_number_vertices(); index++) {
        int s = graph.get_vertex(index);
        DependencyCalculator dc(graph, s);
        for(int index = 0; index < graph.get_number_vertices(); index++) {
            int v = graph.get_vertex(index);
            if(s != v) {
                betweenness[index] += dc.get_dependency(index);
            }
        }
    }
}

void print_graph() {
    std::ofstream fout(output_file);

    for(int index = 0; index < graph.get_number_vertices(); index++) {
        int source = graph.get_vertex(index);
        if (graph.has_neighbors(source)) {
            std::vector<int> neighbors = graph.get_neighbors(source);
            for(int i = 0; i < neighbors.size(); i++)
                fout << source << " "
                    <<neighbors[i] <<std::endl;
        }
    }
}

void print_betweenness() {
    std::ofstream fout(output_file);

    for (int index = 0; index < graph.get_number_vertices(); index++) {
        int vertex = graph.get_vertex(index);
        if (graph.has_neighbors(vertex)) {
            fout << vertex << " "
                << betweenness[index] << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    parse_args(argc, argv);
    parse_input();

    init();
    calculate_betweenness();
    print_betweenness();
    //print_graph();
    return 0;
}
