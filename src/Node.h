#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Edge.h"

using namespace std;

struct Node{
    string title_;
    vector<Edge> edge_list_;
    bool explored_;
    int index_; //in lieu of a full adjacency list
    //int lowlink_; //for tarjans
    //Constructor:
    Node() : title_("empty"){}
    Node(string title) : title_(title), explored_(false){ }
    Node(string title, int index) : title_(title), index_(index), explored_(false){ }

    //Adding an edge to a node
    void add_edge(string page_name){
        edge_list_.emplace_back(Edge(title_, page_name));
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
        cout << "Edges (" << edge_list_.size() << ") " << endl;
        for (auto & elem : edge_list_)
            elem.print();
    }

    
    bool operator!=(const Node n1){
        if(title_ != n1.title_){
            return true;
        }
        if(edge_list_.size() != n1.edge_list_.size()){
            return true;
        }
        for(unsigned i = 0; i < edge_list_.size(); i++){
            if((edge_list_[i] != n1.edge_list_[i]) == true){
                return true;
            }
        }
        return false;
    }
};