# WikiGraph
The Wikispeedia solver is a tool that allows users to improve their Wikispeedia skills. Using a BFS to find the shortest paths between articles in tandem with Brandes and Tarjans algorithm, the user is able to learn to recognize what key articles look like and waht attributes to search for when trying to make shorter paths. Tarjans algorithm allows the user to learn what articles are more likely to be connected to ensure a finished path with no backtracking. Brandes algorithm provides information on what articles are key subjects when finding short paths. By being able to recognize connected subjects and which of those are more likely to lead to other nodes closer to the target article, the user can improve their playstyle and generate shorter paths.

The BFS is the core of this project and is used to find the shortest path between two user-defined articles. If a path is found, it is printed out for the user to see. The tests ran on BFS to ensure functionality ranged from small batch tests to larger datasets. We also tested invalid paths and graphs with cycles to ensure that the BFS could handle edge-cases well.
    Examples of BFS paths on the full-scale dataset:

Brandes

Tarjans algorithm is used to find strongly connected components within a graph, printing each component from strongest to weakest connections. To test Tarjan, used graphs with single and multiple connected components, as well as completely disjoint graphs, empty graphs, and graphs with cycles.
    Connected components of the full dataset: