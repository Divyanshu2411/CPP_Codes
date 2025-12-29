#include<bits/stdc++.h>
using namespace :: std;

struct Edge{
    int src;
    int dest;
    int weight;
};

bool hasPathHelper(vector<vector<Edge>> const &graph, int src, int const &dest, vector<bool> &visited){
    if(src ==dest) return true;

    visited[src]= true;

    for(auto i: graph[src]){
        if(!visited[i.dest]){
           bool path= hasPathHelper(graph, i.dest, dest, visited);
           if(path) return true;
        }
    }

    return false;


}

bool hasPath(vector<vector<Edge>> graph, int src, int dest){

    vector<bool> visited (graph.size(), false);
    return hasPathHelper(graph, src, dest, visited);

}

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