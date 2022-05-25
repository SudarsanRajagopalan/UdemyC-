/*
Given two strings A and B. Check if one string is permutation of the other.
A Permutation of a string is another string that contains same characters, only the order of characters can be different. 
For example, “abcd” and “dabc” are Permutation of each other.
*/

//Expected Time Complexity= O(N log N)
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
 
bool arePermutation(string A, string B)
{
    if(A.length() != B.length())
        return false;
    sort(all(A));
    sort(all(B));
    
    for(int i=0; i<A.size(); i++)
        if(A[i] != B[i])
            return false;
    return true;
    /*
    int a_sum = 0, b_sum = 0;
    for(int i=0; i<A.length(); i++)
    {   
        a_sum += (int)A[i];
        b_sum += (int)B[i];
    }
    if(a_sum == b_sum)
        return true;
    return false;
    */
}

