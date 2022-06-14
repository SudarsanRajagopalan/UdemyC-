/*
You are given an integer array of size N. Your aim is to find all the occurrences (indices) of a given element.
*/
//Expected Time Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> res;

void helper(int k, vector<int> v, int i)
{
    if(i == v.size())
        return;
    if(v[i] == k)
        res.push_back(i);
    helper(k, v, i + 1);
    return;
}

vector<int> findAllOccurences(int k, vector<int> v){
    res.clear();
    helper(k, v, 0);
    return res;
}
