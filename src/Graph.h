#pragma once
#include<Node.h>
#include <vector>
#include <iostream>
class Graph {
    public:
    void readIn(std::string tsv);
    private:
    std::vector<Node> node_list;
};
//reaed in nodes, then bfs through each nodes adjacency list until we find target article, then 