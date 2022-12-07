
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


TEST_CASE("BFS Small Test", "[weight=5]"){
    Graph g = Graph();
    g.readIn("data/bfs_small.txt");
    std::vector<Node> bfs_vect = g.Bfs("Desi", "Ruben");
    std::map<std::string, Node> g_map = g.get_map();
    std::vector<Node> manual_vect = {g_map["Desi"], g_map["Matt"], g_map["Ruben"]};

    //Loop through both vectors to see if they match
    std::vector<Node>::iterator bfs_it = bfs_vect.begin();
    std::vector<Node>::iterator man_it = manual_vect.begin();

    REQUIRE(bfs_vect.empty() == manual_vect.empty());
    
    while(bfs_it != bfs_vect.end() && man_it != manual_vect.end()){
        //Check Edges
        Node g_node = *bfs_it;
        Node g1_node = *man_it;
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
        bfs_it++;
        man_it++;
    }
    REQUIRE(bfs_it == bfs_vect.end());
    REQUIRE(man_it == manual_vect.end());

}

TEST_CASE("Tarjans no connections", "[weight=5]"){
    Graph g = Graph();
    g.readIn("Final proj/WikiGraph/tests/data/Tarjans1.txt");
    std::vector<std::set<Node>> answer = g.Tarjans();
    REQUIRE(answer.size() == 3);
}


TEST_CASE("Tarjan's algorithm", "[weight=5]") {
    // Test a simple case with only one connected component
    SECTION("Single connected component") {
        Graph a = Graph();
        a.readIn("data/Tarjans2.txt");
        vector<set<Node>> connected_components = a.Tarjans();
        
        REQUIRE(connected_components.size() == 1);
        REQUIRE(connected_components[0] == set<Node>({Node("1"),Node("2"),Node("3"),Node("4"),Node("5")}));
    }

    // Test a case with multiple connected components
    SECTION("Multiple connected components") {
        Graph b = Graph();
        b.readIn("data/Tarjans3.txt");
        vector<set<Node>> connected_components = b.Tarjans();

        REQUIRE(connected_components.size() == 2);
        REQUIRE(connected_components[0] == set<Node>({Node("1"),Node("2"),Node("3"),Node("4"),Node("5")}));
        REQUIRE(connected_components[1] == set<int>({Node("6")}));
    }

    // Test a case with no connected components
    SECTION("No connected components") {
        Graph c = Graph();

        vector<set<Node>> connected_components = Tarjans();

        REQUIRE(connected_components.size() == 0);
    }

    // Test a case with a disconnected graph
    SECTION("Disconnected graph") {
        Graph d = Graph();
        d.readIn("data/Tarjans4.txt");

        vector<set<Node>> connected_components = d.Tarjans();

        REQUIRE(connected_components.size() == 3);
        REQUIRE(connected_components[0] == set<int>({Node("1"),Node("2")}));
        REQUIRE(connected_components[1] == set<int>({Node("3"),Node("4")}));
        REQUIRE(connected_components[2] == set<int>({Node("5")}));
    }

    // Test a case with a graph that contains a cycle
    SECTION("Graph with a cycle") {
        
        Graph e = Graph();
        e.readIn("data/Tarjans5.txt");

        vector<set<Node>> connected_components = e.Tarjans();

        REQUIRE(connected_components.size() == 1);
        REQUIRE(connected_components[0] == set<int>({Node("1"),Node("2"),Node("3"),Node("4"),Node("5")}));
    }
}


TEST_CASE("Test", "[weight=5]"){
    REQUIRE("1" == "1");
}