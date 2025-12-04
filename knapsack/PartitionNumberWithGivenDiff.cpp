#include<bits/stdc++.h>
#include<vector>

using namespace::std;

//list of errors:
/**
 */

 //learnings:
 /**
  */

int partitionNumGivenDiff(vector<int> arr, int diff) {
    // code here
    int target=0;
        for(int num: arr){
            target+=num;
        }
        
        if((target+diff) %2) return 0;
        target= (target+diff)/2;
        int n= arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<target+1; j++){
                if(i==0 && j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else{
                    dp[i][j]+=dp[i-1][j];
                    if(j-arr[i-1]>=0){
                        dp[i][j]+=dp[i-1][j-arr[i-1]];
                    }
                }
            }
        }
        for(int i=0; i<n+1; i++){
            for(int j=0; j<target+1; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
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

    

    cout<<endl<< partitionNumGivenDiff(arr, target);
    return 0;
}