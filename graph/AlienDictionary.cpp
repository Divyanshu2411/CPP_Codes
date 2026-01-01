#include<bits/stdc++.h>
using namespace:: std;

class Solution {
  public:
  
    bool addEdge(string const &a, string const &b, vector<vector<char>> &graph){
        int size= min(a.size(), b.size());
        int i=0;
        while(i<size){
            if(a[i]!=b[i]) {
                graph[a[i]-'a'].push_back(b[i]);
                return true;
            }
            i++;
        }
        
        if(a.size()>b.size()) return false;
        return true;
        
    }
    
    vector<bool> validCharacters(vector<string> &words){
        vector<bool> charExist(26,0);
        for(int i=0; i<words.size();i++)
            for(int j=0; j<words[i].size(); j++){
                charExist[words[i][j]-'a']=true;
            }
        return charExist;
    }
  
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<char>> graph(26);
        
        //construct graph of order of priority
        // find and maintain all valid characters and only process those
        // detect any cycle in directed graph (dfs - 3 color, BFS - kahn's), only for valid characters
        
        // if dictionary me two prefixes have no difference, the one with longer comes later. eg(ab, abc), so if there is no mismatch in first and second word, but second word is smaller, invlaid.
        
        
        for(int i=0; i<words.size()-1; i++){
            if(!addEdge(words[i],words[i+1], graph)) return "";
        }
        vector<int> indeg(26,0);
        queue<int> q;
        vector<bool> charExist(26,0);
        
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                indeg[graph[i][j]-'a']++;
            }
        }
        
        vector<bool> validChar= validCharacters(words);
        int countChar=0;
        for(bool i : validChar ) if(i) countChar++;
        
        for(int i=0; i<indeg.size(); i++){
            if(validChar[i]&&indeg[i]==0) {
                q.push(i);
            }
        }
        string ans="";
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans+=curr+'a';
            
            for(int i=0; i<graph[curr].size(); i++){
                int nbr= graph[curr][i]-'a';
                indeg[nbr]--;
                if(validChar[nbr]&&indeg[nbr]==0)
                    q.push(nbr);
            }
        }
        
        if(ans.size()==countChar) return ans;
        return "";
        
    }
};