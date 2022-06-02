/*
Given a two-dimensional array, if any element within is zero, make its whole row and column zero. For example, consider the matrix below.

Example:

Input:
5 4 3 9
2 0 7 6
1 3 4 0
9 8 3 4

Output:
5 0 3 0
0 0 0 0
0 0 0 0
9 0 3 0
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    int nrow = arr.size();
    int ncol = arr[0].size();
    
    unordered_set<int> r_set, c_set;
    
    for(int i=0; i<nrow; i++)
    {
        for(int j=0; j<ncol; j++)
        {
            if(arr[i][j] == 0)
            {
                r_set.insert(i);
                c_set.insert(j);
            }
        }
    }
    for(int x : r_set)
        for(int j=0; j<ncol; j++)
            arr[x][j] = 0;
    for(int y : c_set)
        for(int i=0; i<nrow; i++)
            arr[i][y] = 0;
    return arr;
}
