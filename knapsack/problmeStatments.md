# Problem Statements - Subset Sum is the OG

## Identification
```text
Whenever there is an item (can have weight/value jaise two array, but pertains to same item) and a knapsack (fixed upper limit or exact value) boundary.
```
## Knapsack
```text
two arrays of size n, weight and value, where weight[i], value[i] represent weight and value of ith item. 
Knapsack that can hold max weight W. 

Find the max possible Value that can be stored in knapsack.
```

## Subset Sum
```text
an array of size n. 
A target value T.
Find if any of the subset in array equals T.
```

## Equal Sum Partition
```text
an array of size n.
Find if array can be divided into two subsets of euqal sum
```
### Hint
    - if total array sum is odd, it can never be partitioned into two equal sums
    - if even, simply search if sum/2 subset sume exists, so it becomes previous problem

## Count of Subset Sum with Given Sum
```text
an array of size n and a target T
Count number of subsets having sum T
``` 
### Hint
 - Instead of doing max(1,0) or do || to check subset exists, simply add the value stored at dp when you include and exclude the arrays.
 - Ensure that 0,0 is 1 or a condition to add +1 whenever target-arr[i-1] ==0

 ## Subset with minimum sum difference
```text
an array of size n 
Find minimum difference between two subset sums
``` 
### Hint
 - do a subset sum on target = sum of array
 - dp ki last line is all the possible sums that array can make for different target, chose the target closest to middle. 

### Hint 2
- always break the problem mathematically and try to find similar question and how we can reuse the pattern
- find sum, do a subset sum with target being sum/2. Last line of dp will be all the Sums, that array can achieve.
- largest sum that array can achieve will be s1, s2 will allSum-greatestFoundTarget(s1). s2-s1= allsum - s1 -s1= allSum-2*s1
- when changing from recusive to iterative dp, en

## Counting Number of Subset with given Difference
 ```text
 an array of size n
 Find number of subset combinations with difference between two subset as D.
 ```

 ### Hint
 - always treat subset problems as two equation
    - One is the given problem, in this case difference is D, so s1-s2=D
    - Other is sum of subset is always going to be sum of entire array s1+s2 = sum of array
    - adding both equations, s1= (sum of array + D)/2
 - if sum of array + D is odd, such partition is not possible otherwise it is a problem of finding target sum with s1.

### Hint 2 -WRONG
- Another approach would be, finding target sum for sum.
- in last dp line, start i=0, and j= i+diff. Keep Multiplying both the values and adding to answer
- WRONG REASON- if array is 5 2 6 4, 6 can be made by {6} as well as {4,2}, so column 6 will have 2 value, but column 8 will have 1 value {2,6}. Now, according to above equation, this will mean there are 2 ways to partition when one side sum =6 other side sum =8, but that's not possible since same elemnts are making both sides. 
- the first hint avoids this by finding the exact count of arrays summing to a value.

## Target Sum
 ```text
 an array of size n
 you can assign +- to each element, count number of ways you can reach target sum
 ```

 ### Hint
 - it is same problem as counting number of subset with given difference
 - if you find two set whose difference is D, and if your target sum is also D, you can simply add minus to one of the subsets and you will get the answer.
 - s1- s2= D = target sum. Modify s2 to have all symbols be negative. so you just have to find number of ways, s1-s2=D.
 
### Equal Sum Partition - 2
 ```text
 an array of size n.
 Find if it has two non empty subarrays such that they have equal values
 ```

### Equal Sum Partition - 3
 ```text
 an array of size n.
 Find number of pairs of two non empty subarrays such that they have equal values
 ```

### Sample  Double Array Input
```text
15
5
4 6 2 4 3
3 7 6 5 9
```

### Sample  Single Array Input
```text
15
5
4 6 2 4 3
```

### Test Code - Double Array
```code
#include<bits/stdc++.h>
#include<vector>

using namespace::std;

int knapsack(vector<int> weight, vector<int> value, int maxWeight, int n) {
    // code here
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
```
### Test Code - Single Array
```code
#include<bits/stdc++.h>
#include<vector>

using namespace::std;

//list of errors:
/**
 */

 //learnings:
 /**
  */

int subsetSum(vector<int> arr, int target, int n) {
    // code here

  
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
```