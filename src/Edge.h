
#pragma once
using namespace std;

#include <vector>
#include <string>
#include <iostream>

#include "Node.h"

struct Edge{
    
    string source_;
    string destination_;
    int weight_;

    //Constructor:
    Edge(string source, string destination) : source_(source), destination_(destination) { }

    bool operator!=(const Edge e1){
        if(source_ != e1.source_){return true;}
        else if(destination_ != e1.destination_){return true;}
        return false;
    }

    void print(){
        cout << source_ << " -> " << destination_ << endl;
    }

};
