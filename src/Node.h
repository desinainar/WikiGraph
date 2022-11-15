#pragma once
using namespace std;

#include <vector>
#include <string>
#include <iostream>
#include "Edge.h"

struct Node{
    string title_;
    vector<Edge> edge_list_;
    bool explored_;

    //Constructor:
    Node(string title) : title_(title) { }

    //Adding an edge to a node
    void add_edge(string page_name){
        edge_list_.push_back(Edge(title_, page_name));
    }

    //Returns bool if desired edge exists in edge list:
    bool edge_exists(string page_name){
        for (auto & element : edge_list_)
            if(element.destination_ == page_name){return true;}
        return false ;
    }

    //Prints the contents of the Node
    void print(){
        cout << "Title: " << title_ << endl;
        cout << "Edges: \n";
        for (auto & elem : edge_list_)
            elem.print();
    }
};