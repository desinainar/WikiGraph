#include"Graph.h"
#include <queue>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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
	}
	return true;
}
void Graph::addNode(string title, string destination) {
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
		if (line.find("%") == string::npos) {
			for (std::string each; std::getline(ss, each, '\t'); current_tab.push_back(each)); // put each value in array
		
			Node* it = &node_map[current_tab[0]]; //access of create new key with currenttab[0]
			if (it->title_ == "empty") {
				*it = Node(current_tab[0], count);
				count++;
			}
			current_tab[1].pop_back();
			it->add_edge(current_tab[1]);
			//node_map[current_tab[0]] = *it;
			
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
 	std::vector<Node> pred;
	vector<int> dist;
	queue<Node> traversal;
	
	//map<Node, bool> visited; //to check if ivisited
	auto curr = node_map[source];
	for (auto node : node_map) {
		dist.push_back(-1);
		pred.push_back(Node());
	}
	int srcind = curr.index_;
	curr.explored_ = true;
	dist[srcind]= 0;
	traversal.push(curr);

	while (!traversal.empty()) {
		Node article = traversal.front();
		traversal.pop();
		for (Edge e : article.edge_list_) {
			
			if (node_map.find(e.destination_) != node_map.end()) {
				auto next_article = node_map.at(e.destination_);
				if (next_article.explored_ == false) {
					traversal.push(next_article);
					next_article.explored_ = true;
					dist[next_article.index_] =  dist[next_article.index_] + 1;
					pred[next_article.index_] = article;
				}
				if (next_article.title_ == target) {
					Node path = node_map[target];
					vector<Node> to_return;
					to_return.push_back(path);
					while (pred[path.index_].title_ != "empty") {
						auto it = to_return.begin();
						to_return.insert( it, pred[path.index_]);
						path = pred[path.index_];
					}
					return to_return;
				}
			}
		}
	}
	
	return vector<Node>();
 }

std::vector<double> Graph::Brandes() {
	std::vector<double> centrality;
	std::vector<std::vector<Node>> shortest_paths;
	for (auto node1 : node_map) {
		for (auto node2 : node_map) {
			if (node1.second != node2.second) {
				std::vector<Node> shortest_path = Bfs(node1.first, node2.first);
				shortest_paths.push_back(shortest_path);
			}
		}
	}
	for (auto node : node_map) {
		size_t count = 0;
		for (auto path : shortest_paths) {
			for (auto path_node : path) {
				if (!(path_node != node.second)) {
					count++;
				}
			}
		}
		double node_cen = static_cast<double>(count) / shortest_paths.size();
		centrality.push_back(node_cen); 
	}
	return centrality;
}



std::vector<std::vector<Node>> Graph::Tarjans() {
    std::vector<int> depth(node_map.size(), -1); //depth index for every node
    std::vector<std::vector<Node>> to_return; //contains each connected componenet
    std::vector<bool> onStack(node_map.size()); //bool to check if v has been on stack
	std::vector<int> lowlinks(node_map.size());
    int index = 0;
    std::stack<Node> s;
    for (auto n : node_map) {
        if (depth[n.second.index_] == -1) {
            to_return.push_back(strongconnect(n.second, depth, index, s, onStack, lowlinks));
        }
    }
    return to_return;
}
std::vector<Node> Graph::strongconnect(Node n, std::vector<int> depth, int &index, std::stack<Node> &s, std::vector<bool> &onStack, std::vector<int> &lowlinks) {
    int node_index = n.index_;
    depth[node_index] = index;
    lowlinks[node_index] = index;
    index++;
    s.push(n);
    onStack[node_index] = true;
    for (Edge edge : n.edge_list_) {
        Node w = node_map[edge.destination_];
        int w_index = w.index_;
        if (depth[w_index] == -1) {
            strongconnect(w, depth, index, s, onStack, lowlinks);
            lowlinks[node_index] = (lowlinks[node_index] < lowlinks[w_index]) ? lowlinks[node_index ]: lowlinks[w_index];
        } else if(onStack[w_index]) {
            lowlinks[node_index] = (lowlinks[node_index] < depth[w_index]) ? lowlinks[node_index]:depth[w_index];
        }
    }
    if (lowlinks[node_index] == depth[node_index]) {
        std::vector<Node> to_return;
        Node curr = s.top();
        s.pop();
        while (curr != n) {
            onStack[curr.index_] = false;
            to_return.push_back(curr);
        }
        return to_return;
    }
    return std::vector<Node>();
}








/*
For every node v in V , set CB(v) = 0.
2. For each node s in V , use a BFS algorithm to find all the shortest paths
between s and all other nodes. Store all these paths for each pair s,t.
3. For each pair s,t, count the number of times v appears in the stored paths
to give σ(s, t|v) and divide by the total number of paths between s and t
(i.e., σ(s, t)). Add the result to CB(v).
4. CB(v) gives the final result.
*/



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