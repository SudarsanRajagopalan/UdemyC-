/*
Given an integer N. Your task is to return an integer vector containing numbers from 1 to N in increasing order.
*/
//Expected Time Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;
vector<int> vec;

void helper(int N)
{
    if (N == 0)
        return;
    helper(N-1);
    vec.push_back(N);
}

vector<int> increasingNumbers(int N) {
    vec.clear();
    helper(N);
    return vec;
}
