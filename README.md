# WikiGraph
CS 225 Final Project by: Matthew Guibord - guibord2, Ruben Neyroud - neyroud2, Desi Nainar - ds34

Organization:
The organization of this project is broken up into 3 major locations. 

WikiGraph/

|

|--src/

|   |--Graph.cpp

|   |--Graph.h

|   |--Edge.h

|   |--Node.h

|   |--Node.pp

|

|

|--tests/

|   |

|   |--data/ *contains testing .tsv files*

|

|

|--Documents/ *contains custom .tsv files*

|

|--README.md

|

|--RESULTS.md

In the WikiGraph/ the Main file form that the user runs is found, along with the README, RESULTS, and the other three important files. The meat of the project is all in src/. The algorithms and Graph construction can be found in Graph.cpp. The implementation of the full graph is done over three files. The Graph is made up of Nodes and those nodes contain their title and their Edgelist along other utility parameters. In Graph.cpp, the nodes and their edgelist are created and they are read into a map- making it so that our graph effectively uses an adjacency list. In tests/ our tests for each algorithm and the graph are found as well as data/ where the .tsv files we used. The Documents/ is for the user to input any datasets they want processed beyond the one provided.

Running Instructions:
First, compile the code using "g++ -o main main.cpp src/Node.cpp src/Graph.cpp -Isrc" while in the WikiGraph base directory. Once compiled, use "./main" to run the program. You will be prompted on which data set you want to use; the base project comes with the "links.txt" file, which is the Stanford Wikispeedia Links TSV file, and also the "Medium.txt" file, which is a smaller set with Wikipedia-like connections. Follow the prompts outputted by main to find different shortest paths through the file. Once you have found all the desired paths, you can continue to past the BFS as the strongest components will be printed along with the most central articles.

To add a dataset, we reccomend using excels .tsv format, which provides a standard size of tabs to prevent any read-in errors. The format should be Node names in the first column, and a connection in the right column like so:

Node1 , Edge1

Node1 , Edge2

Node2 , Edge1

...

Once the set is created, save it into WikiGraphs/Documents. Once you run main, you can follow the instructions provided while running the program to read-
in this file.

Test Suite Instructions:

From the WikiGraph directory, cd into tests. Once in the tests file, use "g++ -g -o test tests.cpp ../src/Node.cpp ../src/Graph.cpp" to compile and "./test" to run the suite.
Generally, tests included a test for empty graphs, different numbers of componenets, and validation of correct output. Tarjans required more tests to validate its unexpected output on Wikipedias graphs, and Brandes required less since BFS was also tested and was the primary moving part of the algorithm.
