#pragma once
#include<Node.h>
#include <vector>
#include <iostream>
class Graph {
    public:
    void readIn(std::string tsv);
    std::string Djikstras(std::string target);
    Node findNode(std::string title)

    private:
    std::vector<Node> node_list; //Node contains adjacency lsit

};
//reaed in nodes, then bfs through each nodes adjacency list until we find target article, then 