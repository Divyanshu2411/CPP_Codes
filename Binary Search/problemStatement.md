
# Binary Search

## Format to use

## Identifications

## STL

### binary search

### lower_bound
First element greater than OR EQUAL to given number. -> returns an iterator, if not present, return nums.end()
```code
 lower_bound(nums.begin(), nums.end(), 0); 
```
will find first occurence of 0, and if 0 is not present, finds smallest element greater than 0.


### upper_bound
First element STRICTLY greater to given number. -> returns an iterator, if not present, return nums.end()
```code
 upper_bound(nums.begin(), nums.end(), 0); 
```
even if array has 0, it will give me iterator of element just greater than 0. 


## Good Problem to Work with upper bound and lower

### [Squares of sorted array](https://leetcode.com/problems/squares-of-a-sorted-array/?envType=company&envId=uber&favoriteSlug=uber-thirty-days)
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order. Do it O(n).

### [Time MAP](https://leetcode.com/problems/time-based-key-value-store/submissions/1995630372/?envType=company&envId=uber&favoriteSlug=uber-thirty-days)

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

- TimeMap() Initializes the object of the data structure.
- void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
- String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

### HINT
- do NOT try to re-implement the hashmap, hashing collision etc, that is automatically taken care of
- use this 
    ```code
    unordered_map<string, vector<pair<int, string>>> keyTimeMap;
    ```
-  key -> list of {timestamp, value}
- timestamp will be binary search, so do a upper bound search on timestamp and then it-- (if it is not start of vector, else return "").
- return value as it->second (notice no *, as it is already a pointer)