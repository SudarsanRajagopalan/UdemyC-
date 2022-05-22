//Implement a function that takes an array as input and returns the maximum subarray sum.

//Expected Time Complexity: O(N)
//Hint: Kadane's Algorithm
#include<bits/stdc++.h>
using namespace std;

//Kaden's Algorithm
int maxSumSubarray(vector<int> A) {
    int largest_sum = A[0];
    int curr_sum = 0;
    int positive_flag = 0;
    for(int i=0; i<A.size(); i++)
    {   
        if (A[i] >= 0)
            positive_flag = 1;
        if(positive_flag == 1)
        {
          curr_sum = curr_sum + A[i] < 0 ? 0 : curr_sum + A[i];
          largest_sum = max(curr_sum, largest_sum);
        }
        else
          largest_sum = max(largest_sum, A[i]); 
    }
    return largest_sum;
}
