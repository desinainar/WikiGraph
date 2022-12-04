
#include "../src/Node.h"
#include "../src/Graph.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

// navicate to tests directory
// to compile: make test
// to run:     ./test

// //g++ -g -o test tests.cpp ../src/Node.cpp ../src/Graph.cpp          to compile without make file
// // ./test                                                            to run

TEST_CASE("'==' operator test1", "[weight=5]") {
    Graph g = Graph();
    g.readIn("data/OneNode2.txt");
    Graph g1 = Graph();
    g1.readIn("data/OneNode2.txt");

    //Check Each Node
    std::map<std::string, Node> g1_map = g1.get_map();
    std::map<std::string, Node> g_map = g.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}

TEST_CASE("Empty Graph Test", "[weight=5]"){
    //Empty Graph Test
    Graph emptyreadin = Graph();
    emptyreadin.readIn("data/EmptyGraph.txt");
    Graph emptymanual = Graph();
    std::map<std::string, Node> g1_map = emptyreadin.get_map();
    std::map<std::string, Node> g_map = emptymanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}


TEST_CASE("Graph with 1 Node Test", "[weight=5]"){
    //Graph with 1 Node
    Graph onenodereadin = Graph();
    onenodereadin.readIn("data/OneNode1.txt");
    Graph onenodemanual = Graph();
    //add node and edge to the artificial graph
    onenodemanual.addNode("Baseball", "Ruben");
    std::map<std::string, Node> g1_map = onenodereadin.get_map();
    std::map<std::string, Node> g_map = onenodemanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}


TEST_CASE("Graph with 2 Node Test", "[weight=5]"){
    //Graph with 2 Nodes
    Graph twonodereadin = Graph();
    twonodereadin.readIn("data/OneNode2.txt");
    Graph twonodemanual = Graph();
    twonodemanual.addNode("Baseball", "Matt");
    twonodemanual.addNode("Baseball", "Ruben");
    std::map<std::string, Node> g1_map = twonodereadin.get_map();
    std::map<std::string, Node> g_map = twonodemanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}


TEST_CASE("Graph Wih Only Bad Nodes Test", "[weight=5]"){
    //Graph With only bad nodes
    Graph badreadin = Graph();
    badreadin.readIn("data/onlybadnodes.txt");
    Graph badmanual = Graph();
    std::map<std::string, Node> g1_map = badreadin.get_map();
    std::map<std::string, Node> g_map = badmanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}



TEST_CASE("Graph With Mixture of Good and Bad Nodes Test", "[weight=5]"){
    //Graph with mixture of good and bad nodes
    Graph badmixturereadin = Graph();
    badmixturereadin.readIn("data/badmixture.txt");
    Graph badmixturemanual = Graph();
    badmixturemanual.addNode("Baseball", "Matt");
    badmixturemanual.addNode("Baseball", "Ruben");
    badmixturemanual.addNode("Baseball", "Desi");
    std::map<std::string, Node> g1_map = badmixturereadin.get_map();
    std::map<std::string, Node> g_map = badmixturemanual.get_map();
    std::map<std::string, Node>::iterator g_it = g_map.begin();
    std::map<std::string, Node>::iterator g1_it = g1_map.begin();
    
    REQUIRE(g1_map.empty() == g_map.empty());
    while(g_it != g_map.end()){
        REQUIRE(g_it->first == g1_it->first);
        
        //Check Edges
        Node g_node = g_it->second;
        Node g1_node = g1_it->second;
        std::vector<Edge>::iterator g_edge_it = g_node.edge_list_.begin();
        std::vector<Edge>::iterator g1_edge_it = g1_node.edge_list_.begin();
        REQUIRE(g_node.edge_list_.empty() == g1_node.edge_list_.empty());
        while(g_edge_it != g_node.edge_list_.end()){
            REQUIRE(g_edge_it->source_ == g1_edge_it->source_);
            REQUIRE(g_edge_it->destination_ == g1_edge_it->destination_);
            g_edge_it++;
            g1_edge_it++;
        }
        REQUIRE(g1_edge_it == g1_node.edge_list_.end());
        REQUIRE(g_edge_it == g_node.edge_list_.end());

        g_it++;
        g1_it++;
    }
    REQUIRE(g1_it == g1_map.end());
    REQUIRE(g_it == g_map.end());
}