#include <iostream>
#include "AdjacencyList.h"
#include <iomanip>
#include <sstream>

void AdjacencyList::add_edge(std::string from, std::string to) {
    // Check whether the from address and/or the to address is new

    if (this->mp.count(from) == 0) { // O(1)
//        std::cout << "New address: " << from << std::endl;
        this->mp[from] = std::to_string(this->num_websites); // O(1)
        this->mp[std::to_string(this->num_websites)] = from; // O(1)
        this->num_websites += 1; // O(1)
        this->out_degree.push_back(0); // O(1)
        this->matrix.push_back({}); // O(1)
//        std::cout << from << " -> " << this->mp[from] << std::endl;
    }

    if (this->mp.count(to) == 0) { // O(1)
//        std::cout << "New address: " << to << std::endl;
        this->mp[to] = std::to_string(this->num_websites); // O(1)
        this->mp[std::to_string(this->num_websites)] = to; // O(1)
        this->num_websites += 1; // O(1)
        this->out_degree.push_back(0);// O(1)
        this->matrix.push_back({});// O(1)
//        std::cout << to << " -> " << this->mp[to] << std::endl;
    }

//    std::cout << "Increasing out degree of " << from << std::endl;
    this->out_degree[stoi(mp[from])] += 1; // O(1)
//    std::cout << from << " out degree: " << this->out_degree[stoi(mp[from])] << std::endl;

//    std::cout << "Adding " << from << " to " << to << "in the matrix" << std::endl;
    this->matrix[stoi(mp[to])].push_back(stoi(mp[from])); // O(1)
//    std::cout << to << "(" << mp[to] << ") row: ";
//
//    for (int i : this->matrix[stoi(mp[to])]) {
//        std::cout << i << " ";
//    }
//
//    std::cout << std::endl;
}

void AdjacencyList::multiply() {
    // If this is the first time the multiply() function is called we initialize all the values to 1 / num_websites.
    if (this->page_rank.size() == 0) { // O(1)
//        std::cout << "This is the first time multiply() has been called" << std::endl;
        for (int i = 0; i < this->num_websites; i++) { // O(num_websites)
            this->page_rank.push_back(((float) 1 / this->num_websites)); // O(1)
//            this->page_rank.push_back(((float) 1 / i));
        }
//        std::cout << "page_rank initialized" << std::endl;
    } else {
//        std::cout << "Before page_rank : | ";
//
//        for (float f : this->page_rank) {
//            std::cout << f << " | ";
//        }
//
//        std::cout << std::endl;

        // We multiply the page rank with the sum of the outdegrees of the row values in the matrix.

        std::vector<float> temp; // O(1)

        for (int i = 0; i < (int) this->matrix.size(); i++) { // O(num_websites)
            float sum = 0.0; // O(1)

            for (int j = 0; j < (int) this->matrix[i].size(); j++) { // O(num_websites)
                sum += (1.0 / this->out_degree[this->matrix[i][j]]) * this->page_rank[this->matrix[i][j]]; // O(1)
//            std::cout << (1.0 / this->out_degree[this->matrix[i][j]]) << ", " << this->page_rank[this->matrix[i][j]] << " | ";
            }

//        std::cout << std::endl;

            temp.push_back(sum); // O(1)
        }

        this->page_rank = temp; // O(1)

//        std::cout << "After page_rank : | ";
//
//        for (float f : this->page_rank) {
//            std::cout << f << " | ";
//        }
//
//        std::cout << std::endl;
    }
}

void AdjacencyList::print_page_rank() {
    auto iter = this->mp.begin(); // O(1)

    for (int i = 0; i < this->num_websites; i++) { // O(num_websites)
        iter++; // O(1)
    }

    while (iter != this->mp.end()) { // O(num_websites)
        std::cout << iter->first << " " << std::fixed << std::setprecision(2) << this->page_rank[stoi(iter->second)] << std::endl; // O(1)
        iter++; // O(1)
    }
}

std::string AdjacencyList::get_page_rank() {
    std::ostringstream stream; // O(1)

    auto iter = this->mp.begin(); // O(1)

    for (int i = 0; i < this->num_websites; i++) { // O(num_websites)
        iter++; // O(1)
    }

    while (iter != this->mp.end()) { // O(num_websites)
        stream << iter->first << " " << std::fixed << std::setprecision(2) << this->page_rank[stoi(iter->second)] << std::endl; // O(1)
        iter++; // O(1)
    }

    return stream.str(); // O(1)
}

void AdjacencyList::read_whole_input(std::string input) {
    int num_lines, power_iterations; // O(1)

    std::istringstream stream(input); // O(1)

    // Read the number of lines and power iterations
    stream >> num_lines >> power_iterations; // O(1)

    std::string from, to; // O(1)
    for (int i = 0; i < num_lines; i++) { // O(input_count)
        stream >> from >> to; // O(1)

        this->add_edge(from, to); // O(1)
    }

    for (int i = 0; i < power_iterations; i++) { // O(power_iterations)
        this->multiply(); // O(num_websites * num_websites)
    }
}
