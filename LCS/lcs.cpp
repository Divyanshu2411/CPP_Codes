#include<bits/stdc++.h>
using namespace::std;
//list of errors:
/**
 *  no error
 */

 //learnings:
 /**
  * nothing new, recursive function and change variables
  * why this conversion work?-
  * you first fill one cell as it is based on coversion, replacing n with i, m with j, that fills one cell
  * to fill all cells, in recusion, it goes till i==0, then i=1, i=2 and so on and fills values
  * we do the same process using for loop, filling smaller subproblems first and more later.
  * 
  */

    int longestCommonSubsequence(string text1, string text2,int n, int m) {
        
        //recursive function
        /**
         if(n==0 || m==0) return 0;
         if(text1[n-1]==text2[m-1]) return 1+lcs(text1, text2,n-1,m-1);
         else return max(lcs(text1,text2,n-1,m), lcs(text1, text2,n,m-1));
         */

         vector<vector<int>> dp(n+1, vector<int>(m+1));
         for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0||j==0) dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=1 + dp[i-1][j-1];
                else {
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
         }

         return dp[n][m];
    }
  
  int main(){
    string s1, s2;
    cin>>s1>>s2;

    cout<<endl<< longestCommonSubsequence(s1, s2, s1.length(), s2.length());
    return 0;

  }