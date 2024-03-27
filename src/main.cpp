#include <iostream>

#include "AdjacencyList.h"

using namespace std;

int main() {
    string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    AdjacencyList temp;

    temp.read_whole_input(input);

//    int no_of_lines, power_iterations;
//
//    string from, to;
//
//    cin >> no_of_lines;
//    cin >> power_iterations;
//
//    AdjacencyList list;
//
//    for (int i = 0; i < no_of_lines; i++) {
//        cin >> from;
//        cin >> to;
//
//        list.add_edge(from, to);
//    }
//
//    for (int i = 0; i < power_iterations; i++) {
//        list.multiply();
//    }
//
//    list.print_page_rank();
}
