#include "Graph.h"
int main()
{
    // g++ -o main main.cpp src/Node.cpp src/Graph.cpp -Isrc    to compile without make file
    // ./main                                                to run
    Graph g = Graph();
    g.readIn("Book3.txt");
    g.print();
    std::cout<<"---------------------------------\n\n";
    std::vector<Node> answer = g.Bfs("1", "5");
    for (Node node : answer) {
        std::cout << node.title_ << " -> ";
    }
    std::cout<<"\n---------------------------------\n";
    std::vector<double> central = g.Brandes();
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
    std::cout<<"\n---------------------------------\n";
    std::vector<std::vector<Node>> connected = g.Tarjans();
    int count = 1;
    for (auto component : connected) {
        std::cout << "Component " << count << ":\n";
        for (Node node : component) {
            std::cout << node.title_ << " - ";
        }
        std::cout << "\n";
    }
    return 0;
}