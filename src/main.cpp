#include <iostream>

#include "AdjacencyList.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations;

    string from, to;

    cin >> no_of_lines;
    cin >> power_iterations;

    AdjacencyList list;

    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;

        list.add_edge(from, to);

        cout << endl;
    }

    for (int i = 0; i < power_iterations; i++) {
        list.multiply();

        cout << endl;
    }
}
