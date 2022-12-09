# WikiGraph
CS 225 Final Project by
Matthew Guibord - guibord2
Ruben Neyroud - neyroud2
Desi Nainar - ds34

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
|   |--data/
|
|
|--Documents/
|
|--README.md
|
|--RESULTS.md

In the WikiGraph/ the Main file form that the user runs is found, along with the README, RESULTS, and the other three important files. The meat of the project is all in src/. The algorithms and Graph construction can be found in Graph.cpp. The implementation of the full graph is done over three files. The Graph is made up of Nodes and those nodes contain their title and their Edgelist along other utility parameters. In Graph.cpp, the nodes and their edgelist are created and they are read into a map- making it so that our graph effectively uses an adjacency list. In tests/ our tests for each algorithm and the graph are found as well as data/ where the .tsv files we used. The Documents/ is for the user to input any datasets they want processed beyond the one provided.

Running Instructions:
