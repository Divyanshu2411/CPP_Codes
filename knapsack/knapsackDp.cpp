#include<bits/stdc++.h>
#include<vector>

using namespace::std;

//list of errors:
/**
 * item vetcor (value/weight) has n elements only, not n+1, so use -1 with them
 */

 //learnings:
 /**
  * keep track of size of original argument arrays.
  * write recursive function, replace function with dp with number of changing variables
  * mark one of the function as i, other as j if 2D, and fill the base case
  * in this case, we had this
  * //knapsack (value, weight, maxWeight, n-1)
    //knapsack(value, weight, maxWeight-weight[n-1], n-1) +value[n-1]
  * We replaced knapsack with dp, value and weight are constant so ingore, n with i and maxWeight with j
    //dp[i-1][j]
    //dp[i-1][j-weight[i-1]]+value[i-1] 
  */
int knapsack(vector<int> weight, vector<int> value, int maxWeight, int n) {
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1));

    for(int i=0; i<n+1; i++){
        for(int j=0; j<maxWeight+1;j++){
            if(i==0||j==0) dp[i][j]=0;
            else{
                dp[i][j]= dp[i-1][j];
                if(j-weight[i-1]>=0)
                    dp[i][j]= max(dp[i-1][j-weight[i-1]] + value[i-1],dp[i][j]);

            }
        }
    }

    return dp[n][maxWeight];
}

//knapsack (value, weight, maxWeight, n-1)
//knapsack(value, weight, maxWeight-weight[n-1], n-1) +value[n-1]

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