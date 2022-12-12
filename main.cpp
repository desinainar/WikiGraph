#include "Graph.h"
int main()
{
    // g++ -g -o main main.cpp src/Node.cpp src/Graph.cpp -Isrc    to compile
    // ./main                                                      to run
   
   
    Graph g = Graph();
    std::string path = "Documents/";
    std::string to_add;
    cout << "What dataset would you like to use? (Please match the name of the file including the '.txt')\nIf Stanford Dataset, enter 'links.txt'.\n";
    cin >> to_add;
    path +=to_add;


    g.readIn(path);
    int starting_page;
    int ending_page;
    int max_page = g.getNodes().size();

    
    
    

    //BFS Example:
    std::string user_bfs = "y";
    while(user_bfs.find('y') != string::npos || user_bfs.find('Y') != string::npos) {

        cout << "Enter number between 0 and " << max_page << " for starting page: ";
        cin >> starting_page;
        while(starting_page < 0 || starting_page > max_page){
            cout << "Sorry, invalid starting number, please try again: ";
            cin >> starting_page;
        }
        
        cout << "\nEnter number between 0 and " << max_page << " for ending page: ";
        cin >> ending_page;
        while(ending_page < 0 || ending_page > max_page){
            cout << "Sorry, invalid ending number, please try again: ";
            cin >> ending_page;
        }

        auto node_list = g.getNodes();
        Node start = node_list[starting_page];
        Node end = node_list[ending_page];
        std::string decoded_start = (start.title_.find('%') != string::npos) ? start.utf8_decode(start.title_) : start.title_;
        std::string decoded_end = (end.title_.find('%') != string::npos) ? end.utf8_decode(end.title_) : end.title_;
        cout << "\nStarting Page Chosen: " << decoded_start << endl;
        cout << "Ending Page Chosen: " << decoded_end << "\n" <<endl;
        std::vector<Node> bfs_result = g.Bfs(node_list[starting_page].title_, node_list[ending_page].title_);
        if (bfs_result.empty()) {
            cout << "Path Not Found\n";
        } else {
            cout << "Path:\n";
            cout << decoded_start;
            for(auto & elem : bfs_result){
                cout << elem.title_ << endl;
            }
        }
        cout << "Would You like to test another path? (y/n)\n";
        user_bfs.clear();
        cin >> user_bfs;
    }
    cout << "\n";


    //Tarjans:
    std::vector<std::set<Node>> tarjan_answer= g.Tarjans();
    cout << "Strongest connected components of given set:\n";
    int comp_count = 1;
    for (std::set<Node> sets : tarjan_answer) {
        if (comp_count > 5) {break;}
        cout << "Component " << comp_count << ":\n";
        std::string to_print;
        for (Node n : sets) {
            to_print += n.print_title();
            to_print += ", ";
        }
        to_print.pop_back(); to_print.pop_back();
        cout << to_print;
        cout << "\n";
        comp_count++;
    }

    std::cout << "Betweenness Centrality of Most Central Nodes: (If running on large datasets, allow for processing time)\n";
    std::map<std::string, double> brandes_answer = g.Brandes();
    int i = 0;
    for(auto & elem : brandes_answer){
        if(i > 10){
            break;
        }
        cout << elem.first << ", " << elem.second << endl;
        i++;
    }


    return 0;
}