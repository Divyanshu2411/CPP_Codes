
#include<bits/stdc++.h>
#include<vector>

using namespace::std;

//list of errors:
/**
 * thinking of recursion in wrong way, trying to create a left  right partition without any way to check for difference
 * mistake at end to return allSum-2*target instead of 2*i
 */

 //learnings:
 /**
  * always break the problem mathematically and try to find similar question and how we can reuse the pattern
  * find sum, do a subset sum with target being sum/2. Last line of dp will be all the Sums, that array can achieve.
  * largest sum that array can achieve will be s1, s2 will allSum-greatestFoundTarget(s1). s2-s1= allsum - s1 -s1= allSum-2*s1
 * when changing from recusive to iterative dp, ensure that you are always changing all the variable at all times.
 * If you treat it like boolean, use || instead of max condition
 * in case of subsets, always ask what empty subset will mean. Will it be included in result or ignroed
  */

int minDiffSubsetSum(vector<int> arr, int n) {
    // code here
    int target=0;
    for(int i: arr) target+=i;
    int allSum=target;
    target/=2; // because we need s1-s2 ka minimum. Finding largest target which is <=allSum/2 will be sufficient as then s2 will simply be allSum-target.
    // this reduces the space that is needed by half and by that virtue, space as well.

    vector<vector<bool>> dp (n+1, vector<bool>(target+1));

    for(int i=0; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(j==0) dp[i][j]=true;
            else if(i==0) dp[i][j]=false;
            else{
                dp[i][j]=dp[i-1][j];
                if(j>=arr[i-1]){
                    dp[i][j]= (dp[i][j] || dp[i-1][j-arr[i-1]]);
                }
            }
            
        }
    }

    for(int i=target; i>=0; i--){
        if(dp[n][i]) return allSum- 2*i; 
        //largest sum that array can achieve will be s1, s2 will allSum-greatestFoundTarget(s1). Min diff=s2-s1=> allsum - s1 -s1=> allSum-2*s1
    }

    

    return 0;
     
}

int main(){
    int n=4;
    // cin>>n;
    vector<int> arr(n);
    arr ={15,25,45,65};
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }   

    

    cout<<endl<< minDiffSubsetSum(arr,n);
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