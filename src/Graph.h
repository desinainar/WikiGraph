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

    //Adds node to graph object
    void addNode(string title, string destination);
    
    //Reads in a tab delimited text file and loads all nodes and edges into graph object
    void readIn(std::string tsv);
    
    //Prints out all aspects of the graph object (nodes and edges) 
    void print();
    
    //Returns a vector of nodes which is a path in-between the source node and target node
    //If there is no path, returns an empty vector of nodes
    std::vector<Node> Bfs(std::string source, std::string target);
    
    //Returns a map of all the nodes in the graph object
    std::map<std::string, Node> get_map() {return node_map;}
    
    //Returns a map of each node and its respective betweenness centrality
    std::map<string, double> Brandes();
    
    //Returns a vector of sets of nodes while each set is strongly connected with on another
    std::vector<std::set<Node>> Tarjans();
    
    //Returns a set of strongly connected components
    std::set<Node> strongconnect(Node n, int &index, std::vector<int> &depth, std::stack<Node> &s, std::vector<bool> &onStack, std::vector<int> &lowlinks);
    
    //Returns the vector of nodes that the graph consists of
    std::vector<Node> getNodes() {return nodes;}
    
    private:
    
    //Node map for storing all nodes in the graph
    std::map<std::string, Node> node_map;
    
    //Node vector for storing all nodes in the graph
    std::vector<Node> nodes;
    
    //Adjacency matrix for all nodes in the graph
    std::vector<std::vector<int>> adjacency_matrix;
};