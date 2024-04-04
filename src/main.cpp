#include <iostream>

#include "AdjacencyList.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations; // O(1)

    string from, to; // O(1)

    cin >> no_of_lines; // O(1)
    cin >> power_iterations; // O(1)

    AdjacencyList list; // O(1)

    for (int i = 0; i < no_of_lines; i++) { // O(input_count)
        cin >> from; // O(1)
        cin >> to; // O(1)

        list.add_edge(from, to); // O(1)
    }

    for (int i = 0; i < power_iterations; i++) { // O(power_iterations)
        list.multiply(); // O(n^2)
    }

    list.print_page_rank(); // O(n)
}
