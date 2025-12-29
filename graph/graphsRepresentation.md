# Graph Represenation

## Adjacency Matrix
- n X n matrix banaao, where n is number of nodes(vetices).
- agar undriected hai to mat[src][dest] and mat[dest][src] dono me weight daal do, nahi to jis direction me hai usme.
- unweighted hai to boolean matrix bana ke true daal do.
- 10^3 nodes ke liye tak hi kaam karega, cuz memory limit 10^6

## Adjaceny List
- vector<vector< pair<int,int>>> banao, where vector[i] represents all the nodes jo i se connected hai.
- pair is required for storing dest, weight. if unweight, you can simply store, vector<vector<int>>>
- you can also create a struct Edge with src, dest, weight int variables.(overkill, not needed, but easy to write)
and create a vector<vector<Edge>>>

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