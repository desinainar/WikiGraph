#include <iostream>
#include "../src/Node.h"
#include "../src/Graph.h"

using namespace std;

//g++ -g -o test tests.cpp ../src/Node.cpp ../src/Graph.cpp          to compile without make file
// ./test                                                to run
int main(){

    // '==' operator test1
    Graph g = Graph();
    g.readIn("data/OneNode2.txt");
    Graph g1 = Graph();
    g1.readIn("data/OneNode2.txt");
    bool flag = false;
    if(g == g1){flag = true;}
    if(flag == true){cout << "'==' operator test1 passed" << endl;}
    else{cout << "'==' operator test1 failed" << endl;}


    // '==' operator test2
    Graph g2 = Graph();
    g2.readIn("data/OneNode1.txt");
    Graph g3 = Graph();
    g3.readIn("data/OneNode2.txt");
    bool flag1;
    if(g2 == g3){flag1 = true;}
    else{flag1 = false;}
    if(flag1 == false){cout << "'==' operator test2 passed" << endl;}
    else{cout << "'==' operator test2 failed" << endl;}


    //Empty Graph Test
    Graph emptyreadin = Graph();
    emptyreadin.readIn("data/EmptyGraph.txt");
    Graph emptymanual = Graph();
    if(emptyreadin == emptymanual){cout << "Empty graph test passed" << endl;}
    else{cout << "Empty graph test fail" << endl;}


    //Graph with 1 Node
    Graph onenodereadin = Graph();
    onenodereadin.readIn("data/OneNode1.txt");
    Graph onenodemanual = Graph();
        //add node and edge to the artificial graph
    if(onenodereadin == onenodemanual){cout << "Graph with 1 Node test passed" << endl;}
    else{cout << "Graph with 1 Node test failed" << endl;}


    //Graph with 2 Nodes
    Graph twonodereadin = Graph();
    twonodereadin.readIn("data/OneNode2.txt");
    Graph twonodemanual = Graph();
        //add two nodes and two edges
    if(twonodereadin == twonodemanual){cout << "Graph with 2 Nodes test passed" << endl;};
    // else{cout << "Graph with 2 Nodes test failed" << endl;}

    //Graph With only bad nodes


    //Graph with mixture of good and bad nodes


    //Large Graph

}