#include <bits/stdc++.h>
using namespace ::std;

class RateLimiter{
 unordered_map<string, deque<int>> userRequests; //to store userId and it's request timestamp
 const int maxRequest= 3;
 const int windowSize =10;
 
 public:
 bool shouldAllow(string userId, int timestamp){
    deque<int> &timestamps = userRequests[userId];

    while(!timestamps.empty() && timestamp- timestamps.front()>=windowSize){
        timestamps.pop_front(); 
    }

    if(timestamps.size()<maxRequest){
        timestamps.push_back(timestamp);
        return true;
    }

    return false;

 }

};

int main()
{
    return 0;
    
}