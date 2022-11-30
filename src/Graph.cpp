#include"Graph.h"
#include <queue>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//check to see if 2 graphs are identical
bool Graph::operator==(Graph g1){
	if (node_map.size() != g1.node_map.size()) {
		return false;
	}
	for (auto it_1 = node_map.begin(), it_2 = g1.node_map.begin(); it_1 != node_map.end(); ++it_1, ++it_2) {
		if ((it_1 -> second != it_2 -> second) == true) {
			return false;
		}
		return true;
	}
}
void addNode(string title, string destination) {
	Node* it = &node_map[title]; //access of create new key with currenttab[0]
	if (it->title_ == "empty") {
		*it = Node(title);
	}
	it->add_edge(destination);
}

void Graph::readIn(std::string tsv) {
	ifstream in(tsv);
    if (in.fail()) {
		std::cout << "error" << std::endl;
		return;
	}
	std::string line;
	int count = 0;
	//node_list.push_back(Node(std::string, count)); //empty node
	while (getline(in, line)) {
		std::stringstream ss(line);
		std::vector<std::string> current_tab;
		std::string tmp;
		for (std::string each; std::getline(ss, each, '\t'); current_tab.push_back(each)); // put each value in array
		
		if (current_tab[0].find("%") == 0) {
			Node* it = &node_map[current_tab[0]]; //access of create new key with currenttab[0]
			if (it->title_ == "empty") {
				*it = Node(current_tab[0], count);
			}
			it->add_edge(current_tab[1]);
			//node_map[current_tab[0]] = *it;
			count++;
		}
	}
}

void Graph::print(){
	for (auto & node : node_map){
		node.second.print();
		cout<< " " << endl;
	}
}

//add heap from lab
std::vector<Node> Graph::Bfs(std::string source, std::string target) { 
 	std::vector<Node> to_return;
	return std::vector<Node>();
 }






/*
while prev[u] is defined:                 // Construct the shortest path with a stack S
4      insert u at the beginning of S          // Push the vertex onto the stack
5      u ← prev[u]                             // Traverse from target to source
6  end while




function Dijkstra(Graph, source):
 2      
 3      for each vertex v in Graph.Vertices:
 4          dist[v] ← INFINITY
 5          prev[v] ← UNDEFINED
 6          add v to Q
 7      dist[source] ← 0
 8      
 9      while Q is not empty:
10          u ← vertex in Q with min dist[u]
11          remove u from Q
12          
13          for each neighbor v of u still in Q:
14              alt ← dist[u] + Graph.Edges(u, v)
15              if alt < dist[v]:
16                  dist[v] ← alt
17                  prev[v] ← u
18
19      return dist[], prev[]
*/