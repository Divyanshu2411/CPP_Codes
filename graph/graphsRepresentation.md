# Graph Represenation

## [Adjacency Matrix](https://takeuforward.org/graph/graph-representation-in-c)
- n X n matrix banaao, where n is number of nodes(vetices).
- agar undriected hai to mat[src][dest] and mat[dest][src] dono me weight daal do, nahi to jis direction me hai usme.
- unweighted hai to boolean matrix bana ke true daal do.
- 10^3 nodes ke liye tak hi kaam karega, cuz memory limit 10^6
- for BFS, DFS to find neighbours, if you have to find for say ith node, you traverse the entire graph[i] and see which is non -1 / 0

## [Adjaceny List](https://takeuforward.org/graph/graph-representation-in-c)
- vector<vector< pair<int,int>>> banao, where vector[i] represents all the nodes jo i se connected hai.
- pair is required for storing dest, weight. if unweight, you can simply store, vector<vector<int>>>
- you can also create a struct Edge with src, dest, weight int variables.(overkill, not needed, but easy to write)
and create a vector<vector<Edge>>>

## Pixel Representation
- graph is represented using bit(1/0) or some pixel where actual graph is plotted on a grid.
- you need to traverse the whole grid and figure out whatever is given, there is no node/vertices scene ya yu kahe, every i,j is a node and every adjoining cells is connected through an edge. 

## Degree of Graph
- Degree of graph kuch nahi hota, degree of node hota hai
- undirected graph -> number of edges attacahed to node
- directed graph -> indegree  and outdegree hota hai, self understandable
- total degree of graph (directed or undirected) = 2* edges.  every edge is +1 degrees in two nodes.

## Why applying DP to graph problem is not a good idea
Graph can have cycles
- Backtracking handles this using the visited array to prevent going in circles.
- Dynamic Programming requires the problem to have Optimal Substructure and No Cycles (it must be a Directed Acyclic Graph, or DAG).

## When can you use DP
1. If the graph is DAG
    If there are no cycles, you can use Memoization. Instead of re-calculating all paths from node nbr to dest every time you visit it, you store the result:
    - memo[u] = A list of all paths from u to dest.

    - Then, paths from src = src + (all paths in memo[nbr]).

2. If you only need to COUNT the paths (ONLY for DAG, actual simple path calculation is NP-hard)
    - If you don't need to print the actual nodes but just want to know how many ways there are to get from A to B, DP is extremely efficient (O(V+E)).
    - $$TotalPaths(u) = \sum_{v \in neighbors(u)} TotalPaths(v)$$


## Hamiltonian Path
- Refers to those path in graph jisme src and dest ke beech sare vertices are covered without any vertex being repeated

## Hamiltonian Cycle
- Refers to those Hamiltonian path jinke src and dest ke beech me there is an edge.

## BiPartite Graph
- If vertices of a graph can be divided into 2 mutual exclusive (koi bhi node common nahi) and exhaustive (dono set mila ke sare node cover kar rhe hai) such that all the edges lies in opposite sets (ek hi set me dono nodes of an edge nahi hona chiye)
- All acyclic graph are bipartite( BFS chala do, alternate level alternate set me dal do nodes)
- In case of cyclic graphs
    - Even (number of nodes) cycle graph are bipartite (bfs chalaoge to alternate level pe still alag alag node aayega, imagine square cycle)
    - Odd cycle graph is always non bipartite (bfs chalaoge to at least do consecutive layer me ek node do baar ayega, but same node can't be in both sets.)
- For a graph to Bi-Partite, all component needs to be Bi-partite

## Djikstra Algorithm
- Used to find path with least cummulative weight in weighted path.
- used to find shortest path in map and stuff.
- Normal BFS, but instead of queue, use priority queue.

## MST - Minimum Spanning Tree
- Tree : Connected Acylic graph
- Spanning: Connecting all vertices
- MST: Minimum spanning tree - covers all vertices in minimum weight/edge like a tree
- Two algorithm: Prim's and Kruskal

## Prim's algorithm
- Used to find MST
- similar to Djiskta, but instead of cummulative weight in priority queue, bas edge ka weight insert hota hai. 
- so essentially a BFS in which we take out next node with minimum weight between edge of node and that neigbour node.

## Topological Sort
- only applicable in acyclic directed graph.
- find a permuation of nodes such that, if u --> v is an edge, u comes before v for all nodes.
- order of work is reverse of topological sort, i.e u-->v me
    - in topological u will come before v
    - in order of work, since u depends on v, v needs to be done first and hence, v will come before u. 
- Run DFS, post-order traversal, keep adding element to vector. Same order will be order of work, reverse will be topological sort.

## Iterative DFS
- same as BFS, use stack instead of queue.
- <b>Need:</b> stack has limited memory, stackoverflow possible due to function calls for large single connected nodes. Using iterative, we can utilise heap memory to store stack and avoid stackoverflow.

## DFS on adjacency matrix
- to find neighbours, traverse on all of graph[i] to find all the neighbours of ith node

## What to use as visited array
- when you have adjaceny list, use vector<bool>
- when you need to store some levels to it, use vector<int> and store whatever information you need
- when you have have a matrix graph (the 1,0 kind of graph), the same graph dimensions has to be visited array as well. since there is no node/edge information, you will need to have this to ensure you don't end up again at same.
- whenever you see directions you have to go manually (like up down right left) always think about visited array of same size as grid/graph.
- always take care of boundary conditions i.e. >=0 and <= max graph size and visited.

## Manhattan Distance
Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

# Resource:

## [Graph Resource](https://leetcode.com/discuss/post/1326900/graph-algorithms-problems-to-practice-by-9u6j/)



```code
int main(){
    int numVector= 6;
    cin>>numVector;
    int numEdge=8;
    cin>>numEdge;
    vector<vector<Edge>> adjacenyListGraph (numVector);
    for(int i= 0; i<numEdge; i++){
        int src,dest,weight;
        // cout<<"\n Enter edge: "<< (i+1) << " : ";
        cin>> src;
        cin>> dest;
        cin>> weight;
        adjacenyListGraph[src].push_back({src,dest,weight});
        adjacenyListGraph[dest].push_back({dest,src,weight});
    }

    // cout<< hasPath(adjacenyListGraph,4,2);
    return 0;
}
```