/*
  In simple bubble sort algorithm, the time complexity will remain O(n^2) every time, even if the given array is already sorted.
  Your task is to optimized the bubble sort such that its best case time complexity becomes O(n).
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> v){
    auto n = v.size();
    for(int times=1; times<=n-1; times++)
    {
        bool swapped = false;
        for(int j=0; j<=n-1-times; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
    return v;
}
