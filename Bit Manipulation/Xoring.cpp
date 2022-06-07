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
