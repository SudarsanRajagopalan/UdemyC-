/* Given a sorted array and a number x, find a pair in array whose sum is closest to x. */

//Expected Time Complexity: O(N)
//Hint: Two Pointer Approach
#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    int index_1, index_2;
    int distance = INT_MAX;
    int start = 0, end = arr.size()-1;
    
    while(start < end)
    {
        if(abs(x - (arr[start] + arr[end])) < distance)
            {
                distance = abs(x - (arr[start] + arr[end]));
                index_1 = start;
                index_2 = end;
            }
        if(arr[start] + arr[end] <= x)
            start++;
        else
            end--;
    }
    return {arr[index_1], arr[index_2]};
}
/*
Time Complexity: O(N^2)
pair<int, int> closestSum(vector<int> arr, int x){
    pair<int, int> pair1 = {-1, -1};
    int distance = INT_MAX;
    int diff_x_pairsum = 0;
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=i+1; j<arr.size(); j++)
        {
            int pair_sum = arr[i] + arr[j];
            diff_x_pairsum = x - pair_sum;
            if(abs(diff_x_pairsum) < distance)
            {
                distance = diff_x_pairsum;
                pair1.first = arr[i];
                pair1.second = arr[j];
            }
        }
    }
    return pair1;
}
*/
