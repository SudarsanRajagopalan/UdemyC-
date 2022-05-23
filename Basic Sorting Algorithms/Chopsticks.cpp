/*
  Given N sticks and an array length where each length[i] represents length of each stick.
  Your task is to make maximum number of pairs of these sticks such that the difference between the length of two sticks is at most D.
  A stick can't be part of more than one pair of sticks.
*/
//Expected Time Complexity :O(N log N)

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    int n = length.size();
    int pair_count = 0;
    sort(length.begin(), length.end());
    for(int i = 0; i<n-1; i++)
    {
        if(abs(length[i] - length[i+1]) <= D) //also can be written without abs() "if(abs(length[i + 1] - length[i]) <= D)"
        {
            pair_count++;
            i++;
        }
    }
    return pair_count;
}
