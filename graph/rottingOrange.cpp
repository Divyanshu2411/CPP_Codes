#include <bits/stdc++.h>
using namespace ::std;

class SolutionDFS {
public:

int n,m;

    void dfs(vector<vector<int>> const &grid, vector<vector<int>> &visited, int i, int j, int level){

        if(i<0||j<0||i>=n || j >=m || grid[i][j]==0 || visited[i][j]<=level) return;
        visited[i][j]= level;
        dfs(grid,visited, i+1, j, level+1);
        dfs(grid,visited, i-1, j, level+1);
        dfs(grid,visited, i, j+1, level+1);
        dfs(grid,visited, i, j-1, level+1);

    }

    int orangesRotting(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,INT_MAX));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    dfs(grid,visited, i, j,0);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0)
               ans= max(ans, visited[i][j]);
            }
        }

        return ans==INT_MAX?-1: ans;
    }
};

class SolutionBFS {
public:

    int addToQueue(queue<pair<int,int>> &q, vector<vector<int>> &visited,int x, int y, int &n, int &m){
        if(x<0 || y <0 || x>=n || y>=m || visited[x][y]!=1 ) return 0;

        q.push({x,y});
        visited[x][y]=2;

        return 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> visited = grid;
        int countFreshOrange=0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    countFreshOrange++;
            }
        }
        if(countFreshOrange==0)
            return 0;
        
        int minutes=0;
        while(countFreshOrange && !q.empty()){
            int size= q.size();
            while(size--){
                pair<int,int> rottenOrangeLoc= q.front();
                q.pop();
                countFreshOrange-=addToQueue(q, visited, rottenOrangeLoc.first+1,rottenOrangeLoc.second,n,m);
                countFreshOrange-=addToQueue(q, visited, rottenOrangeLoc.first-1,rottenOrangeLoc.second,n,m);
                countFreshOrange-=addToQueue(q, visited, rottenOrangeLoc.first,rottenOrangeLoc.second+1,n,m);
                countFreshOrange-=addToQueue(q, visited, rottenOrangeLoc.first,rottenOrangeLoc.second-1,n,m);

            }
            minutes++;
            //to visualise rotting
            for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<visited[i][j]<<" ";
            }cout<<endl;
            }
            cout<<"__________________________________\n";
        }

        if(countFreshOrange>0) return -1;
        return minutes;
    }
};