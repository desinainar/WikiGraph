#include "Graph.h"
int main()
{
    // g++ -g -o main main.cpp src/Node.cpp src/Graph.cpp -Isrc    to compile without make file
    // ./main                                                to run
   
   
    Graph g = Graph();
    cout << "Would you like to truncate edge lists? Y / N(Reccomended for Large Datasets)\n";
    std::string answer;
    cin >> answer;
    int edge_max;
    if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes") {
        cout << "What would you like the maximum to be?\n";
        cin >> edge_max;
    } else {
        edge_max = 100;
    }
    g.readIn("Medium.txt", edge_max);
    int starting_page;
    int ending_page;
    
    cout << "Enter number between 0 and 4586 for starting page: ";
    cin >> starting_page;
    while(starting_page < 0 || starting_page > 4586){
        cout << "Sorry, invalid starting number, please try again: ";
        cin >> starting_page;
    }
    
    cout << "\nEnter number between 0 and 4586 for ending page: ";
    cin >> ending_page;
    while(ending_page < 0 || ending_page > 4586){
        cout << "Sorry, invalid ending number, please try again: ";
        cin >> ending_page;
    }
    
    
    
    std::map<std::string, Node> graph_map = g.get_map();
    auto it_start = graph_map.begin();
    auto it_end = graph_map.begin();
    for (int i = 0; i < starting_page; i++){it_start++;}
    for(int j = 0; j < ending_page; j++){it_end++;}
    std::string decoded_start = (it_start->second).utf8_decode(it_start->first);
    std::string decoded_end = (it_end->second).utf8_decode(it_end->first);
    cout << "\nStarting Page Chosen: " << decoded_start << endl;
    cout << "Ending Page Chosen: " << decoded_end << endl;

    //BFS Example:
    std::vector<Node> bfs_result = g.Bfs(it_start->first, it_end->first);
    for(auto & elem : bfs_result){
        cout << elem.title_ << endl;
    }

    return 0;
}