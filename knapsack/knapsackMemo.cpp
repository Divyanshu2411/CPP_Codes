#include<bits/stdc++.h>
#include<vector>

using namespace::std;

//list of errors:
/**
 * wasn't able to declare array with all values being -1 correctly
 * wrote either take or not take, but didn't add the action (value) in add
 * didn't check if weight is going negative before taking (i.e. boundary conditions are matching before taking)
 */

 //learnings:
 /**
  * learn memset, how to declare globall and set size locally
  * active decision - decision jisme you select kuch or the status quo is changing
  * passive decision - decision jisme only the array is being reduced/increased but kuch action nahi ho rha
  * for active decisions, always remember to include action as value
  * Before taking action, verify if the action is allowed within the constraints.
  */

vector<vector<int>> store (1000, vector<int>(1000,-1));
//look for how to declare globally but set size locally in main function
int knapsack(vector<int> weight, vector<int> value, int maxWeight, int n) {
    if(n<1)
        return 0;
    
    if(store[maxWeight][n]!=-1){
        return store[maxWeight][n];
    }    

    int ans=knapsack(weight, value, maxWeight, n-1);
    if(maxWeight-weight[n-1]>=0){
        ans= max(knapsack(weight, value, maxWeight-weight[n-1], n-1) + value[n-1],ans);
    }
    return store[maxWeight][n]=ans;
}

int main(){
    int maxWeight;
    cin>> maxWeight;
    int n;
    cin>>n;
    vector<int> weight(n);
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }

    vector<int> value(n);
    for(int i=0; i<n; i++){
        cin>>value[i];
    }

    cout<<endl<< knapsack(weight, value, maxWeight,n);
    return 0;
}

/**
Input
15
5
4 6 2 4 3
3 7 6 5 9

Output: 
27
 */