# Graphs

## hasPath
```text
Given a graph, tell if there is a path from a given src vertex to a given destination vertex
```

### Hint
- create a visited array to mark a node as soon as you visit
- ask all the neighbour nodes if they can reach the destination using rec. 
- if src is dest, stop recursion.

## allPath
```text
Given a graph, find all path from src to dest
```
### Hint
- same as hasPath, but instead of returning as soon as destination found, add the path to an array
- once a path has been fully explored, make sure you mark that node as unvisited at end so that other paths can use it. 10-15 nodes tak works, O(n!)/ O(n)
- you can technically use bit-masking (only to find count) where you represent each bit as a node. You & with current path number and if it's 1, that means abhi tak ke sare path same hai so you can simply use memoised data.
(doen't matter if you don't know this or forget, not important). Complexity thodi better hai, 20 nodes tak chalta hai.

## Get Connected Components
```text
Given a graph, find all connected components
```

### Hint
- same as allPath, ek visited array maintain karo. 
- start your traversal from visited array and travel and keep flipping to true.
- once one component is done, keep traversing the visited array until you find a false and repeat until visited array finishes.
- count number a loop starts

## Is Graph Connected
```text
Given a graph, find if it's connected
```

### Hint
- start traversal from visited and look for all the paths, if all the nodes visited, you good.

## [Number of Island](https://leetcode.com/problems/number-of-islands/description/)
```text
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
```
### Hint
- look at the data type first, if it's char type, don't use !grid[i][j] to check if '1' is there or not, but do explicit compare grid[i][j]=='1'.
- a little different since graph is visually represented, but simple, create a visited array of same size as grid
- traverse on grid and whenever you come across unvisited land, run a recursive function that marks all the connected land of that island. Every time you have to do this, that is the amount of island.
- for marking, traverse in all four direction +-1 for i and j, and write base cases (out of bound, water reached, already visited)

### Hint 2-> if modification is allowed
- sink the land (change '1' to '0') you have touched once and you won't need visited array. 

## Perfect Friends
```text
You are given total number of friends n and k lines pair of integer denoting connection between two friends. Conenction se matlab ek grp me hai/club me hai.  Find total possible pair of two friends which can be made taking two people, each from differenct clubs
eg:
3 -> 3 friends
1 -> 1 connection
1 2 -> 1 and 2 are connected. 

```

### Hint
- first find components i.e. clubs (array of array, arr[i] = ith club)
- since each club ka pair banana hai, run a nested loop (i=0; i<arr.size()) ->( j=i+1; j<arr.size()), taki sare possible club groups aa jaye.
- multiple dono components ke size and keep adding to answer. so, ans += arr[i].size()*arr[j].size();

## Is Graph Cyclic
```text
Given graph, find if there is any cycle.
```

### Hint
- there can be multiple component, so for each component, run DFS/BFS all path wala.
- if we come across any visited which has already been visited, that means cycle is there
- kuki ek hi node pe pauchne ke ek component me do raste tab hi honge agar cycle hoga.
- NOTE: A cycle exists if you encounter a visited node that is not the direct parent of the current node

## Is Graph Bipartite
```text
Given graph, find if the graph is Bipartite
```

### Hint
- for each component do following, if any of it reutrn false, return false as all components need to be bipartite. Refer <b>Is Graph Connected</b>
- run a bfs, instead of boolean visited, maintain an array that tells at which level it was visited. default -1.
- if you never come across same visited element again, great, non cyclic, it's a bipartite.
- if you come across a visited element again, check if level is same as prior visit. 
    - If it is, it's an even cycle. (since level order, and one origin, that leave odd number of nodes to explore, middle node pe sath me milenge. 4 ka cycle, start at 0, goes to 1, 3 and reach 2 sath me.)
    - If it is not, it's an odd cycle (1,2,3 ka cycle, starts with 1, goes to 2 and 3. now 2 ka goes to 3 and 3 goes to 2 but at different levels.)

## Djikstra Algorithm
```text
Given a weighted graph, find path with smallest cummulative weight from src node to dest node.
```

- start with src node, run BFS, but instead of queue, use priority queue (priority on weight). 
- After each eviction, add it's unvisited neighbor (while adding, also add the weight between that neigbor and the current node).
- priority queue will automatically make least cummulative weight as top.
- while evictinga node, if you see it has already been visited, simply discard it as a better path has already been discovered. move to next node simply.