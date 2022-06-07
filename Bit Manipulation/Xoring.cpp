//We are given an array containg n numbers. All the numbers are present twice except for one number which is only present once. Find the unique number without taking any extra spaces and in linear time.
//Expected Time Complexity : O(N)
//XOR of two same elements is 0

#include<bits/stdc++.h>
using namespace std;

int xoring(vector<int> v)
{
    int ans = 0;
    
    for(auto x:v)
        ans ^= x;
    return ans;   
}
