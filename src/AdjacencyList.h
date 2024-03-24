#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class AdjacencyList {
private:
    std::unordered_map<std::string, std::string> mp;
    std::vector<std::vector<int>> matrix;
    std::vector<int> out_degree;
    std::vector<double> page_rank;
    int num_websites;
public:
    void multiply();
    std::string get_page_rank();
    void add_edge(std::string from, std::string to);
};
