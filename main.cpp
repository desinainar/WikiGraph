#include "Graph.h"
int main()
{
    // g++ -o main main.cpp src/Node.cpp src/Graph.cpp -Isrc    to compile without make file
    // ./main                                                to run
    Graph g = Graph();
    g.readIn("Book3.txt");
    g.print();
    std::vector<Node> answer = g.Bfs("1", "5");
    std::vector<double> central = g.Brandes();
    std::cout <<"here\n";
    if (answer.empty()) {std::cout << "empty\n";}
    else {
        for (Node node : answer) {
            std::cout << node.title_ << " -> "; 
        }
        std::cout << "\n";
        for (double next : central) {
            std::cout << next << " ->";
        }
    }
    
    return 0;
}