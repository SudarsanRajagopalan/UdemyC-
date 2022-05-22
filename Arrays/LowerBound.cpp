/* Given an array of integers A (sorted) and a integer Val.
   Implement a function that takes A and Val as input and returns the lower bound of Val.
   Note: If Val is not present in array then Lower bound of a given integer means integer which is just smaller than given integer.
   Otherwise Val itself is the answer.
   If Val is less than smallest element of array A then return -1 in that case */
//Expected Time Complexity: O(logN)
//Hint: Binary Search

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> A, int Val) {
    int result = -1;
    int start = 0;
    int end = A.size()-1;
    
    while(start<=end)
    {
        int mid = (start + end)/2;
        if(A[mid] > Val)
            end = mid - 1;
        else
        {
            result = A[mid];
            start = mid + 1;
        }
    }
    return result;
}

/* Time Complexity: O(N)
int lowerBound(vector<int> A, int Val) {
    if(Val < A[0])
        return -1;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] > Val)
            return A[i-1];
        else if(A[i] == Val)
            return A[i];
    }
    return A[A.size()-1];
}
*/
