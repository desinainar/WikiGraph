
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
    Edge(string source, string destination) : source_(source), destination_(destination), weight_(1) { }

    void print(){
        cout << "Source: " << source_ << "  Destination: " << destination_ << "  Weight: " << weight_ << endl;
    }

};
