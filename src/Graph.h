#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <map>
class Graph {
    public:    
    void readIn(std::string tsv);
    void print();
    std::vector<Node> Djikstras(std::string source, std::string target);
    Node findNode(std::string title);

    private:
    std::vector<Node> node_list; //Node contains adjacency lsit
    std::map<std::string, Node> node_map;
};
//reaed in nodes, then bfs through each nodes adjacency list until we find target article, then 