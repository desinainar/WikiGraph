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
	std::vector<Node> g1_list = g1.get_node_list();
	if(node_list.size() != g1_list.size()){
		return false;
	}
	else{
		for (unsigned i = 0; i < node_list.size(); i++){
			if(node_list[i] != g1_list[i]){
				return false;
			}
		}
		return true;
	}
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
		if (count == 0 || current_tab[0] != node_list[count-1].title_) { //if the title is not the same as the node we are working in, create new node
			count++;
			node_list.push_back(Node(current_tab[0], count));
		}
		node_list.back().add_edge(current_tab[1].substr(0, current_tab[1].size()-1));
	}
}

void Graph::print(){
	for (auto & node : node_list){
		node.print();
		cout<< " " << endl;
	}
}


std::vector<Node> Graph::Djikstras(std::string source, std::string target) { 
// https://stackoverflow.com/questions/28998597/how-to-save-shortest-path-in-dijkstra-algorithm - to print path itself
 	std::vector<int> distances(node_list.size());
 	std::vector<Node> previous(node_list.size());
 	Node src = Node("empty");
 	std::queue<Node> q;
 	for (Node cur : node_list) {
 		distances[cur.index_] = -1;
 		previous[cur.index_] = Node("empty");
 		q.push(cur);
 		if (cur.title_ == source) {
 			src = cur;
 		}
 	}
 	if (src.title_ == "empty") return std::vector<Node>();  //will be called by a helper function that if vector is empty, return that source doesnt exist
 	distances[src.index_] = 0;
 	//heap Q(node_list); might just need a regualr queue if we are saying all weights are 1
 	while (!q.empty()) { //problem with edge list: we need to make it faster to find the node according to its title-maybe map where k=title, v = node
 		Node u = q.front();
 		q.pop();
 		u.explored_ = true;
 		for(Edge edge : u.edge_list_) {
 			Node v = findNode(edge.destination_);
 			if (v.explored_ == false) {
 				int alt = distances[u.index_] + 1; // 1 since all weights are 1
 				if (alt < distances[v.index_]) {
 					distances[v.index_] = alt;
 					previous[v.index_] = u;
 				}
 			}
 		}
 	}
 	std::vector<Node> shortest_path;
 	Node end = findNode(target);
 	while(end.index_ < (int)previous.size()) { //parse thru previous list to get shortest path
 		shortest_path.insert(shortest_path.begin(), end);
 		end = previous[end.index_];
 	}
 	return shortest_path; // we need to write some stuff for if the path doesnt exist aswell.
 }

 Node Graph::findNode(std::string title) { // super expenisve, map might be better to be able to find nodes according to title
 	for(Node cur : node_list) {
 		if (cur.title_ == title) {
 			return cur;
 		}
 	}
	return Node("no");
 }

std::vector<Node> Graph::get_node_list(){
	return node_list;
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