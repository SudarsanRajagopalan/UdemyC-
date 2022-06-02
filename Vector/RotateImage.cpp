/*
  You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
  
  You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
  
  Example:
  
  Input:
  1 2 3
  4 5 6
  7 8 9
  
  Output:
  7 4 1
  8 5 2
  9 6 3 
*/

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      for(int i=0; i<n; i++)
      {
          for(int j=0; j<n; j++)
          {
              if(i != j and i < j)
                  swap(matrix[i][j], matrix[j][i]);
            
          }
      }
      
      //Also can reverse each vector of the matrix or use the below code to reverse
      //for(int col=0, endcol=n-1; col<=(n/2)-1; col++, endcol--)
      for(int col=0, endcol=n-1; col<endcol; col++, endcol--)
      {
          for(int row=0; row<n; row++)
              swap(matrix[row][col], matrix[row][endcol]);
      }
}
