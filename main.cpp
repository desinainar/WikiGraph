// Main

#include <iostream>
#include "src/Node.h"
#include "src/Graph.h"

using namespace std;

int main()
{
    // g++ -o main main.cpp src/Node.cpp src/Graph.cpp    to compile without make file
    // ./main                                             to run
    cout << "Hello World" << endl;
    Graph g = Graph();
    g.readIn("Book1.txt");
    g.print();

    return 0;
    
}
