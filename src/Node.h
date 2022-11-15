#pragma once
using namespace std

#include <vector>
struct Node{
    string title_;
    vector<string> edge_list_;
    bool explored_;
}