#include"Graph.h"
#include <queue>
#include <fstream>
#include <string>
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
	while (getline(in, line)) {
		std::stringstream ss(line);
		std::vector<std::string> current_tab;
		std::string tmp;

		for (std::string each; std::getline(ss, each, '\t'); current_tab.push_back(each)); // put each value in array
		current_tab[1].pop_back();
		Node* it = &node_map[current_tab[0]]; //access of create new key with currenttab[0]
		if (it->title_ == "empty") {
			*it = Node(current_tab[0], count);
			nodes.push_back(*it);
			count++;
		}
		it->add_edge(current_tab[1]);
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
 	std::vector<Node> pred(node_map.size(), Node());
	vector<int> dist(node_map.size(), -1);
	queue<Node> traversal;
	auto curr = node_map[source];
	int srcind = curr.index_;
	curr.explored_ = true;
	dist[srcind]= 0;
	traversal.push(curr);

	while (!traversal.empty()) {
		Node article = traversal.front();
		traversal.pop();
		for (Edge e : article.edge_list_) {
			auto next_article_pair = node_map.find(e.destination_);
			if (next_article_pair != node_map.end()) {
				Node *next_article = &next_article_pair->second;
				if (next_article->explored_ == false) {
					traversal.push(*next_article);
					next_article->explored_ = true;
					dist[next_article->index_] =  dist[next_article->index_] + 1;
					pred[next_article->index_] = article;
				}
				if (next_article->title_ == target) {
					Node path = node_map[target];
					vector<Node> to_return;
					to_return.push_back(path);
					while (pred[path.index_].title_ != "empty" && pred[path.index_].title_ != source) {
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

std::map<string, double> Graph::Brandes() {
	std::vector<string> node_titles;
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
        node_titles.push_back(node.second.title_);
		centrality.push_back(node_cen); 
	}
    std::map<string, double> brandes_map;
    for (size_t i = 0; i < node_titles.size(); i++) {
        brandes_map[node_titles[i]] = centrality[i];
    }
	return brandes_map;
}



std::vector<std::set<Node>> Graph::Tarjans() {
    std::vector<int> depth(node_map.size(), -1); //depth index for every node
    std::vector<std::set<Node>> to_return; //contains each connected componenet
    std::vector<bool> onStack(node_map.size()); //bool to check if v has been on stack
	std::vector<int> lowlinks(node_map.size(), -1);
    int index = 0;
    std::stack<Node> s;
    for (auto n : node_map) {
        if (depth[n.second.index_] == -1) {
			Node pass = n.second;
			auto to_add = strongconnect(pass, index, depth, s, onStack, lowlinks);
			if (!to_add.empty()) {
				if (!to_return.empty()) {
					bool already= false;
					for (std::set<Node> check: to_return) {
						if(includes(check.begin(), check.end(), to_add.begin(), to_add.end())) {
							check = (check.size() > to_add.size()) ? check : to_add;
							already = true;
							break;
						}
					}
					if (!already) {
						to_return.push_back(to_add);
					}
				} else if (to_return.empty()) {
					to_return.push_back(to_add);
				}
			}
        }
    }

    return to_return;
}
std::set<Node> Graph::strongconnect(Node n, int &index, std::vector<int> &depth, std::stack<Node> &s, std::vector<bool> &onStack, std::vector<int> &lowlinks) {
	std::set<Node> to_return;
	int node_index = n.index_;
    depth[node_index] = index;
    lowlinks[node_index] = index;
    index++;
    s.push(n);
    onStack[node_index] = true;
    for (Edge edge : n.edge_list_) {
        if (node_map.find(edge.destination_) != node_map.end()) {
			Node w = node_map[edge.destination_];
			int w_index = w.index_;
			if (depth[w_index] == -1) {
				auto to_add = strongconnect(w, index, depth, s, onStack, lowlinks);
				to_return.insert(to_add.begin(), to_add.end());
				lowlinks[node_index] = (lowlinks[node_index] < lowlinks[w_index]) ? lowlinks[node_index ]: lowlinks[w_index];
			} else if(onStack[w_index]) {
				lowlinks[node_index] = (lowlinks[node_index] < depth[w_index]) ? lowlinks[node_index]:depth[w_index];
			}
		}
		
    }
	Node top;
	
    if (lowlinks[node_index] == depth[node_index]) {
        while (top != n && s.size() >= 1) {
            top = s.top();
        	s.pop();
			onStack[top.index_] = false;
            to_return.insert(top);
        }
    }
    return to_return;
}
