# Problem Statements - LCS is the OG

## Identification
```text
 Whenver there are two strings and some operation is based on that.
```

## [Longest Common Subsequnce](https://leetcode.com/problems/longest-common-subsequence/)
```text
two strings x, y. Find the lenght of longer common subsequnce
```
### Hint
 - subsequence means selected string can be dis-contiguous. substring has to be continous. 
 - nothing new, recursive function and change variables
  * why this conversion work?-
  * you first fill one cell as it is based on coversion, replacing n with i, m with j, that fills one cell
  * to fill all cells, in recusion, it goes till i==0, then i=1, i=2 and so on and fills values
  * we do the same process using for loop, filling smaller subproblems first and more later.
 - if (s1[i-1]==s2[j-1])    : dp[i][j]= 1 +dp[i-1][j-1]                 || 1 +lcs(s1,s2,n-1,m-1)
 - else                     : dp[i][j]= max(dp[i-1][j], dp[i][j-1])     || max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1))

## [Longest Common Substring](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)
```text
two strings x, y. Find the lenght of longer common substring
```
### Hint
 - subsequence means selected string can be dis-contiguous. substring has to be continous.
 - since there is no way to ensure contiguity without multiple if else, change the problem to largest contiguous substring ending at i,j where i,j are included. And find largest value after finding all such possible values. 
 - find continuous as it is, as soon as the conitnuity break, fill that as 0. (this time cell is no longer a exact subproblem but represent length of contiguous substring ending at i,j)
 - maintain a separate answer value which goes through each and check the highest value.
 - if will be same as lcs, only else dp[i][j]=0;

## [Print ALL LCS](https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1) --> Hard Question
```
Given two strings X, Y. Print all possible longest common subsequence
```
### Hint
- create LCS table and try to backtrack
- while backtracking, if(x[i-1]==y[j-1]), add it to backtrack, else follow left or up path where maximum value is
- if both has same value and x and y element are unequal, follow both path.
- use memoisation
- vector<vector<unordered_set<string>>>> is the correct memoisation string
- Reassigning a memo vector : // Initialize Memoization table: N+1 x M+1
        memo.assign(n + 1, vector<unordered_set<string>>(m + 1));

## Shortest Common Supersequence
```text
Given two string x,y, find shortest common supersequnence length.
```

### Hint
- Supersequnce of two string is such that X and Y both are valid subsequence of that string.
- Basic supersequence will be X+Y, it will have repeating characters of LCS(x,y)
- Shortest Common Supersequence: x.len + y.len - lcs(x,y)

## [Print Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/description/)
```text
Given two string x,y, find shortest common supersequnence.
```

### Hint
- Supersequnce of two string is such that X and Y both are valid subsequence of that string.
- Basic supersequence will be X+Y, it will have repeating characters of lcs =LCS(x,y)
- Shortest Common Supersequence: keep iterating x and y until both match lcs[i], then add lcs[i]. Repeat until lcs ends
- add remaining characters of x and y

## Minimum number of insertions and deletions
```text
Given two string x,y. Find minimum number of insertions and deletions needed to convert sting x into y.
```

### Hint
- find LCS. 
- number of insertion y.length- lcs.
- number of deletion x.length-lcs.

## Longest Palindrom Subsequence
```text
given string, find longest palindromic subsequence.
```

### Hint
 - reverse string, find lcs(string,rev_string);

 ## Minimum number of Deletion to make a string palindromic
 ```text
 given string, find minimum number of deletion to make string palindromic.
 ```

 ### Hint
  - find longest palindromic subsequence (LPS).
  - answere = s.length - lps(s).length