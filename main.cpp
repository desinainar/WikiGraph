// Main

#include <iostream>
#include "src/Node.h"
#include "src/Graph.h"

using namespace std;

int main()
{
    // g++ -g -o main main.cpp src/Node.cpp src/Graph.cpp    to compile without make file
    // ./main                                                to run
    Graph g = Graph();
    g.readIn("Book3.txt");
    g.print();
    //vector<Node> solution = g.Djikstras("Baseball", "Matt");
    //for (Node cur : solution) {
    //    cout << cur.title_ << " ";
   // }
    return 0;
}