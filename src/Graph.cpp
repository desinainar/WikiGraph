#include<Graph.h>
void Graph::readIn() {
    ifstream in("links.tsv");
    if (in.fail()) {
		std::cerr << "error" << std::endl;
		return;
	}
	std::string line;
	while (getline(in, line)) {
		std::stringstream ss(line);
		std::vector<std::string> item;
		std::string tmp;
		while(getline(ss, tmp, '\t')) {
			item.push_back(tmp);
		}
        Node temp(item, std::vector<string>(), false);
		node_list.push_back(temp);
	}
}