
#include<bits/stdc++.h>
#include<vector>

using namespace::std;

//list of errors:
/**
 * in base condition, n=0, target=0 chose as 0, but it should be 1. i.e all empty subarrays are matching 0 target at least once and counted as such. 
 */

 //learnings:
 /**
 * This is required for 2nd element. As when target ==2nd element, it looks at dp[0][0] to add to sum. 
 * Alternative is add +1 separately when target-ele ==0
 * 
 * Learning for count subset for given difference
 * - always treat subset problems as two equation
    - One is the given problem, in this case difference is D, so s1-s2=D
    - Other is sum of subset is always going to be sum of entire array s1+s2 = sum of array
    - adding both equations, s1= (sum of array + D)/2
  */

int subsetSum(vector<int> arr, int target, int n) {
    // code here

    /**
     * Recursive
     * arr[n-1] choose or not choose.
     * if arr[n-1] choose, target= target-arr[n-1], so condition is arr[n-1]<=target
     * base target <0 or n==0 return 0; if target==0, increase count by 1. In memoisation, we simply add 1 to already stored value everytime we end up there;
     * if empty subset sum is allowed as 0, then for n==0 will also return 1.
     */

     vector<vector<int>> dp(n+1, vector<int>(target+1));

     for(int i=0; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(j==0) dp[i][j]=1;
            else if (i==0) dp[i][j]=0;
            else{
                dp[i][j]= dp[i-1][j];
                if(arr[i-1]<=j){
                    dp[i][j]+= dp[i-1][j-arr[i-1]];
                }
            }
        }
        
     }

     
     return dp[n][target];
}

int main(){
    int target=10;
    cin>> target;
    int n=5;
    cin>>n;
    vector<int> arr(n);
    arr ={4,6,2,4,3};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }   

    cout<<endl<< subsetSum(arr, target,n);
    return 0;
}

/*
Input: 
10
5
4 6 2 4 3

output: 3
*/