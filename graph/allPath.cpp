#include<bits/stdc++.h>
using namespace :: std;

struct Edge{
    int src;
    int nbr;// neigbour
    int weight;
};
void printVector(vector<int> const &a){
    for(const int &num: a){
        cout<<num<<" ";
    }
    cout<<endl;
}
void pritnAllPathHelper(vector<vector<Edge>>const &graph, int src, int &dest, vector<bool> &visited, vector<int> path, vector<vector<int>> &paths){
        
    path.push_back(src);
    if(src==dest){
        paths.push_back(path);
        return;
    }
    /*
    2 - 3 - 5
    |   | \ |
    0 - 1 - 4
    */
    visited[src]=true;
    //for lexicographical printing, make an array of nbr nodes, sort it and then call printAllPathHelper
    for(auto i : graph[src]){
        if(!visited[i.nbr]){
            pritnAllPathHelper(graph, i.nbr,dest,visited,path,paths);
        }
    }
    visited[src]= false;
}

void printAllPath(vector<vector<Edge>> graph, int src, int dest){
    vector<bool> visited (graph.size(), false);
    vector<vector<int>> paths;
    pritnAllPathHelper(graph,src,dest,visited,{},paths);
    for(auto &path: paths){
        printVector(path);
    }
}

int main(){
    int numVector= 6;
    // cin>>numVector;
    int numEdge=8;
    // cin>>numEdge;
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

    printAllPath(adjacenyListGraph,4,2);
    return 0;
}

/**
 * 
 0 1 5
 0 2 7
 2 3 5
 3 1 4
 3 5 8
 5 4 2
 3 4 1
 1 4 7


2 - 3 - 5
|   | \ |
0 - 1 - 4


 0 1 5
 0 3 7
 1 5 5
 3 1 4
 3 5 8
 5 4 2
 3 4 1
 1 4 7


2   3 - 5
  / | X |
0 - 1 - 4

 * 
 */