
#include<bits/stdc++.h>
#include<vector>

using namespace::std;

//list of errors:
/**
 * while checking for edge conditionm, checked if arr[i-1]<=target instead of arr[i-1]<=j
 */

 //learnings:
 /**
 * when changing from recusive to iterative dp, ensure that you are always changing all the variable at all times.
 * If you treat it like boolean, use || instead of max condition
 * in case of subsets, always ask what empty subset will mean. Will it be included in result or ignroed
  */

int subsetSum(vector<int> arr, int target, int n) {
    // code here

    /**
     * Recursive
     * arr[n-1] choose or not choose.
     * if arr[n-1] choose, target= target-arr[n-1], so condition is arr[n-1]<=target
     * base target <0 or n==0 return 0; if target==0, return 1;
     * if empty subset sum is allowed as 0, then for n==0 will also return 1.
     
     susetSum(arr, target-arr[n-1],n-1);  max of both (since result can be 0 or 1 and we only want to see if such a subarray is possible)
     subsetSum(arr, target, n-1);
     */

     vector<vector<int>> dp(n+1, vector<int>(target+1));

     for(int i=0; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(i==0) dp[i][j]=0;
            else if (j==0) dp[i][j]=1;
            else{
                dp[i][j]= dp[i-1][j];
                if(arr[i-1]<=j){
                    dp[i][j]= max(dp[i][j], dp[i-1][j-arr[i-1]]);
                }
            }
        }
     }

     return dp[n][target];
}

int main(){
    int target;
    cin>> target;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    

    cout<<endl<< subsetSum(arr, target,n);
    return 0;
}

/*
Input: 
15
5
4 6 2 4 3

output: 1

15
5
4 6 2 4 2
output: 0
*/