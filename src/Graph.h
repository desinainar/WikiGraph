#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
class Graph {
    public:    
    
    //Check to see if two graphs are identical
    bool operator==(Graph g1);
    void addNode(string title, string destination);
    //read a tsv and load into
    void readIn(std::string tsv);
    void print();
    std::vector<Node> Bfs(std::string source, std::string target);
    std::map<std::string, Node> get_map() {return node_map;}
    std::map<string, double> Brandes();
    std::vector<std::set<Node>> Tarjans();
    std::set<Node> strongconnect(Node n, std::vector<int> depth, std::stack<Node> &s, std::vector<bool> &onStack, std::vector<int> &lowlinks);
    std::vector<Node> getNodes() {return nodes;}
    private:
    std::map<std::string, Node> node_map;
    std::vector<Node> nodes;
    std::vector<std::vector<int>> adjacency_matrix;
};
//reaed in nodes, then bfs through each nodes adjacency list until we find target article, then 