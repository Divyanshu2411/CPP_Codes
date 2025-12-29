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

## [Connected Components in an Undirected Graph](https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1)
```text
given graph, return a 2d vector, where each individual vector has a connected component ke all nodes
```
### Hint
- with the help of edges, create an adjacency list. Always create an adjacency list.
- similar to get connected components, but instead of enhancing count, you store nodes visited till now in this path and add it in each loop as component.

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
### Hint
- start with src node, run BFS, but instead of queue, use priority queue (priority on weight). 
- After each eviction, add it's unvisited neighbor (while adding, also add the weight between that neigbor and the current node).
- priority queue will automatically make least cummulative weight as top.
- while evictinga node, if you see it has already been visited, simply discard it as a better path has already been discovered. move to next node simply.

## Prim's Algorithm
```text
Given a weighted graph, find it's MST. (computer netwrok me minimum lan).
```
### Hint
- start with src node, run BFS, but instead of queue, use priority queue (priority on weight)
- after each eviction, add it's unvisited neighbour (add only edge node weight, in djisktra, we added cummulative weight adding current weight in weight till now. )
- priority queue will automatically make path of least weight as top.
- while evictinga node, if you see it has already been visited, simply discard it as a better path has already been discovered. move to next node simply.

## Topological Sort
```text
Given an acylcic directed graph, find it's topological order (Remember, topological order is reverse of Order of work )
```
### Hint
- Run DFS in post order traversal manner (basically when all recursive calls have been returned)
- Action of post order is to add element to a vector.
- vector as it is is order of work (since the dependencies are processed first and hence added first), reverse of the vector is topological sort.
- Note: people use stack and just empty it to show topological sort, I personally find vector more useful for further processing. 

## Iterative DFS
```text
Do iterative DFS.
```
### Hint
- BFS but use stack instead of queue.

## [Rotting Orange](https://leetcode.com/problems/rotting-oranges/description/)
```
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
```

### Hint
- DFS approach: (faster than 100%)
    - visited array as big as grid filled with INT_MAX (to denote not reached)
    - every time you see rotten fruit, run a dfs on it.
    - dfs base condition if(i<0||j<0||i>=n || j >=m || grid[i][j]==0 || visited[i][j]<=level) return; the visited <= level ensure that if through some other path, orange can get spoilt faster, we don't block it
    - we update the visited with level. dfs(grid, visited, i, j, level) is our function, every time we move in a direction, we do level +1
    - once the whole grid is traversed, we traverse visited grid and see which fruit took longest to spoil.
    - we need to ensure we don't check empty grid, so we check if grid[i][j]!=0 while traversing visited.
    - if our ans is INT_MAX, it means some fruit could not be spoilt, return -1 else return fruit.
    - Initialise ans with 0, as there can be condition of an empty grid in which case answer is 0. 


- BFS approach (actual recommend approach)
    - Traverse the grid first and push all the i,j pairs to queue wherever there is a rotten orange. These will serve as the starting points of spoilage.
    - Also maintain a count of total number of freshOranges to confirmm if all of them got spoiled without a need to traverse again.
    - Run a bfs using the queue.
    - While original queue is not empty
        - Find size of queue, and run loop size number of time - following will simulate spoilage from all sources
            - pop the queue front, look at it's four direction and see if any fresh orange is there.
            - decrese freshOrange count, mark it as 2 i.e. spoiled and insert it's i,j to queue. (as this will act as spoilage node now).
        - increase minute by 1. (so basically you see how much spoilage happened every minute and update that).