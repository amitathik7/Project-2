#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    Node* next;
    int to_index;
    int outdegree;
    Node(int to_index, int out_degree) {
        this->next = nullptr;
        this->to_index = to_index;
        this->outdegree = out_degree;
    }
};

class AdjacencyList {
private:
    vector<Node*> matrix;
    unordered_map<string, int> mp;
    vector<int> page_rank;
    int num_websites;
public:
    AdjacencyList();
    void add_edge(string from, string to);
    void power_iteration();
    string get_page_rank();
    void read_whole_input(string input);
};

// This class and method are optional.
