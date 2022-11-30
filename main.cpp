#include "Graph.h"
int main()
{
    // g++ -o main main.cpp src/Node.cpp src/Graph.cpp -Isrc    to compile without make file
    // ./main                                                to run
    Graph g = Graph();
    g.readIn("Book3.txt");
    g.print();
    vector<Node> solution = g.Djikstras("article 1", "article 4");
    cout << "solution: ";
    for (Node cur : solution) {
        cout << cur.title_ << " ";
    }
    cout << "\n";
    return 0;
}