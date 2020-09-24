#ifndef DEPENDENCY_CALCULATOR_H
#define DEPENDENCY_CALCULATOR_H

#include <queue>
#include <stack>
#include <vector>

#include "graph.h"

class DependencyCalculator {
    private:
        Graph& graph; //G
        int vertex; //s
        std::stack<int> stack; //S
        std::vector<std::vector<int>> shortest_path_predecessor; //P
        std::vector<int> num_shortest_path; //sigma
        std::vector<int> distance; //d
        std::queue<int> queue; //Q
        std::vector<double> dependency; //delta

    public:
        DependencyCalculator(Graph& graph, int vertex) : graph(graph),vertex(vertex) {
            
        }

        double get_dependency(int index) {
            return dependency[index];
        }

    private:
        void init() {
            for(int index = 0; index < graph.get_number_vertices(); index++) {
                shortest_path_predecessor.emplace_back();
                num_shortest_path.push_back(0);
                distance.push_back(-1);
                dependency.push_back(0);
            }

            num_shortest_path[graph.get_index(vertex)] = 1;
            distance[graph.get_index(vertex)] = 0;
            queue.push(vertex);
        }

        void find_num_shortest_paths() {
            while(!queue.empty()){
                int v = queue.front();
                int index_v = graph.get_index(v);
                queue.pop();
                stack.push(v);
                std::vector<int> neighbors = graph.get_neighbors(v);
                for(int index = 0; index < neighbors.size(); index++){
                    int w = neighbors[index];
                    int index_w = graph.get_index(w);
                    if(distance[index_w] < 0) {
                        queue.push(w);
                        distance[index_w] = distance[index_v] + 1;
                    }
                    if(distance[index_w] = distance[index_v] + 1) {
                        num_shortest_path[index_w] += num_shortest_path[index_w];
                        shortest_path_predecessor[index_w].push_back(v);
                    }
                }
            }
        }

        void calculate_dependencies_() {
            while(!stack.empty()) {
                int w = stack.top();
                int index_w = graph.get_index(w);
                stack.pop();
                for(auto v: shortest_path_predecessor[index_w]) {
                    int index_v = graph.get_index(v);
                    dependency[index_v] += (
                        (double) num_shortest_path[index_v] / 
                        (double) num_shortest_path[index_v] ) * 
                        (1 + dependency[index_v]);
                }
            }
        }
};

#endif