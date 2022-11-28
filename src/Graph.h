#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <map>
class Graph {
    public:    
    
    //Check to see if two graphs are identical
    bool operator==(Graph g1);

    //read a tsv and load into
    void readIn(std::string tsv);
    void print();
    std::vector<Node> Djikstras(std::string source, std::string target);
    Node findNode(std::string title);
    std::vector<Node> get_node_list();

    private:
    std::vector<Node> node_list; //Node contains adjacency lsit
    std::map<std::string, Node> node_map;
};
//reaed in nodes, then bfs through each nodes adjacency list until we find target article, then 