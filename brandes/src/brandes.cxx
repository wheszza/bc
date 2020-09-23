#include <iostream>
#include <fstream>
#include <string>

#include "graph.h"
#include "dependency_calculator.h"
#include "parse.h"

std::string input_file;
std::string ouput_file;

Graph graph;

void parse_args(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr
            << "USAGE: ./brandes  <input-file> <output-file>"
            << std::endl;
        exit(1);
    }

    input_file = argv[1];
    ouput_file = argv[2];
}

void parse_input() {
    Parser parser(input_file);
    graph = parser.get_graph();
}

void print_graph() {
    std::ofstream fout(ouput_file);

    for(int index = 0; index < graph.get_number_vertices(); index++) {
        if (graph.has_neighbors(index)) {
            int source = graph.get_vertex(index);
            std::vector<int> neighbors = graph.get_neighbors(source);
            for(int i = 0; i < neighbors.size(); i++)
                fout << source << " "
                    <<neighbors[i] <<std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    parse_args(argc, argv);
    parse_input();
    print_graph();
    return 0;
}
