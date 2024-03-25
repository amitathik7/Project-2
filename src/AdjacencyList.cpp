#include <iostream>
#include "AdjacencyList.h"

void AdjacencyList::add_edge(std::string from, std::string to) {
    // Check whether the from address and/or the to address is new

    if (this->mp.count(from) == 0) {
        this->mp[from] = std::to_string(this->num_websites);
        this->mp[std::to_string(this->num_websites)] = from;
        this->num_websites += 1;
        this->out_degree.push_back(0);
        this->matrix.push_back({});
    }

    if (this->mp.count(to) == 0) {
        this->mp[to] = std::to_string(this->num_websites);
        this->mp[std::to_string(this->num_websites)] = to;
        this->num_websites += 1;
        this->out_degree.push_back(0);
        this->matrix.push_back({});
    }

    this->out_degree[stoi(mp[from])] += 1;
    this->matrix[stoi(mp[to])].push_back(stoi(mp[from]));
}