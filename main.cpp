// Main

#include <iostream>
#include "src/Node.h"

using namespace std;

int main()
{
    // g++ -o main main.cpp src/Node.cpp    to run without make file
    cout<< "Hello World" << endl;
    Node node1 = Node("Matt");
    node1.add_edge("Desi");
    node1.add_edge("Ruben");
    node1.print();
    cout << node1.edge_exists("Ruben") << endl;
    cout << node1.edge_exists("Desi") << endl;
    cout << node1.edge_exists("Michael") << endl;
    return 0;
    
}
