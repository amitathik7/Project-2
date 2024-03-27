#pragma once

#include <string>
#include <map>
#include <vector>

class AdjacencyList {
public:
    std::map<std::string, std::string> mp;
    std::vector<std::vector<int>> matrix;
    std::vector<int> out_degree;
    std::vector<float> page_rank;
    int num_websites = 0;
public:
    void multiply();
    void print_page_rank();
    void add_edge(std::string from, std::string to);
    std::string get_page_rank();
    void read_whole_input(std::string input);
};
