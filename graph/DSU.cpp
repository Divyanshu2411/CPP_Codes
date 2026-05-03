#include<bits/stdc++.h>
using namespace std;


class DSU{

    vector<int> size, rank, parent;
    // we generally use only size or rank
    //two operation, by get parent, join (by size/rank);
    public:
    DSU(int n){
        size.resize(n,1); // everyon has size of
        rank.resize(n,0);// nothing below at start, no depth
        parent.resize(n);// 
        iota(parent.begin(), parent.end(), 0); // fills value from 0 to end in sequence, each element is its own parent 
    }

    int getParent(int child){
        if(child == parent[child]){
            return child;
        }
        return parent[child]= getParent(parent[child]); // if we don't update parent, 
        //tree will be a little longer, this is called path compression, this distorts the rank (but we don't modify actual rank phir bhi)
        // we do this taki root element tak jana is O(1) for subsequent calls and O(1) me ho cheeze na ki O(logN) which tree will be).
    }

    /**
     * JOIN has two work:
     * Check if elements are part of same group, if yes, simply return. Use is parent in driver code to figure out if they are part of same group if code requires. 
     * If no, rule of thumb, merge smaller group to bigger (rank me it increase by 1, size me add size of smaller group to bigger group)
     * These additions happen only to parent (root element, ultimate parent, whatever you call)
     */

    void joinByRank(int a, int b){
        //maintain rank, everything is 0, while merging we merge the one with lower rank to higher
        // if same, merge anything with anyone, just increase the rank of the final parent by 1.
      
    }
    

    void joinBySize(int a, int b){
        // each element starts with size of 1 (itself), while merging, you add smaller sized group to bigger and add to the size
        if(getParent(a)==getParent(b)){ // part of same set, nothing to join
            return;
        }

        if(size[getParent(a)]>=size[getParent(b)]){
            size[getParent(a)]+=size[getParent(b)]; // first add size, then update parent
            parent[getParent(b)]= getParent(a); // since parent of a is bigger than b, 
        }

        // now recommended way is to call these function once, and store in a variable and use them 



    }

};