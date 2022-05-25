/*
Given a matrix, print it in Reverse Wave Form.

Input:
Given integer m (number of rows), integer n (number of columns) and 2d vector.

Output:
Return a linear vector of integers in the required order.
*/
//Expected Time Complexity: O(m*n)
#include<bits/stdc++.h>
using namespace std;
 
 vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    vector<int> wavearr;
    int col = n-1;
    while(col >= 0)
    {
        for(int row=0; row<m; row++)
            wavearr.push_back(arr[row][col]);
        col--;
        if(col < 0)
            break;
        for(int row=m-1; row>=0; row--)
            wavearr.push_back(arr[row][col]);
        col--;
    }
    return wavearr;
}
