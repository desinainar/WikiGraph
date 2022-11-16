#include<Graph.h>
void Graph::readIn(std::string tsv) {
    ifstream in(tsv);
    if (in.fail()) {
		std::cout << "error" << std::endl;
		return;
	}
	std::string line;
	node_list.push_back(Node(std::string, std::vector<string>, false));
	while (getline(in, line)) {
		std::stringstream ss(line);
		std::vector<std::string> current_tab;
		std::string tmp;
		for (std::string each; std::getline(split, each, '\t'); current_tab.push_back(each)); // put each value in array
		if (current_tab[0] != nodes[curr_node].title_) { //if the title is not the same as the node we are working in, create new node
			node_list.push_back(nodes.push_back(Node(current_tab[0], std::vector<string>, false)));
		}
		node_list.back().edge_list_.push_back(current_tab[1]); //push link to nodes edges vector
	}
}