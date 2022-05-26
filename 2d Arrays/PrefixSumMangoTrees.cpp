/******************************************************************************
https://www.iarcs.org.in/inoi/online-study-material/topics/prefix-sums-ramus-mango-trees.php

Computing Prefix Sums:
                  Two dimension: Ramu's Mango Trees
Ramu's father has left a farm organized as an N × N grid. Each square in the grid either has or does not have a mango tree. He has to divide the farm with his three sisters as follows: he will draw one horizontal line and one vertical line to divide the field into four rectangles. His sisters will choose three of the four smaller fields and he gets the last one.

He wants to divide the field so that he gets the maximum number of mangos possible, assuming that his sisters will pick the best three rectangles.

For example, suppose the field looks as follows:

      . # # . . .
      # . . # # .
      . # . . . .
      . # # . . #
      # . . # # .
      . # . . . .
      
Ramu can ensure that he gets at least 3 mango trees by cutting as follows:

        . # | # . . .
        # . | . # # .
        . # | . . . .
      ------+---------
        . # | # . . #
        # . | . # # .
        . # | . . . .
      
Solution

If Ramu draws the vertical line after column x and the horizontal line after row y, we represent it by (x,y). For each cut (x,y), we need to calculate the minimum rectangle that it creates. Then, over all the cuts, we choose the one whose minimum rectangle is maximized.

The problem is to efficiently calculate how a cut divides up the mango trees in the four rectangles.

Let M[x,y] be the number of mango trees in the rectangle between (0,0) and (x,y). We can calculate M[x,y] as follows:

      M[x,y] = 1 + M[x-1,y] + M[x,y-1] - M[x-1,y-1], if tree at (x,y)
             = 0 + M[x-1,y] + M[x,y-1] - M[x-1,y-1], if no tree at (x,y)
      
Thus, M[x,y] is the number of mango trees in the top left rectangle formed by the cut. Using M[x,y], we can also calculate the number of mango trees in the top right and bottom left rectangles defined by (x,y).

Top right rectangle:

      M[N,y] - M[x,y] : Number of mangos in rectangle defined by (x,y) and (N,0)
      
Bottom left rectangle:

      M[x,N] - M[x,y] : Number of mangos in rectangle defined by (0,N) and (x,y)
      
Finally, we subtract these three quantities from total number of mango trees to get number of mangos in fourth rectangle (bottom right), defined by (x,y) and (N,N).

*******************************************************************************/

//Expected Time Complexity : O(N^2)
/* 
Because N^2 cuts are being done and each time S1, S2, S3, S4 are being calculated with the help of Auxiliary Matrix M
Therefore O(N^2 * 1) which is O(N^2).  For cuts O(N^2) and calculation O(1).
*/
/*
If we had used Brute Force approach of cutting and calculating the sum of each quadrants each time then it would have
taken O(N^2 * N^2) i.e. O(N^4) which is too huge.  For cutting O(N^2) and summing up another O(N^2).
If N is 100 then time complexity would be O(10^8).  If we assume it takes 1 sec for 10^8 instructions
and if the value of N becomes 1000 then the number of instructions will be 10^12 which will approximately
take 10^4 seconds which is so huge.  Therefore we go for Prefix Sum Method.
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

void prefixSum2dMango(char farm[][10], int n)
{
    //Let the Auxiliary Matrix be 'M'
    int M[n][n] = {0};
    int S1, S2, S3, S4;
    int maximized_minimum = INT_MIN;
    
    
    //Construction of Auxiliary Matrix
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 and j != 0)
                M[i][j] = M[i][j - 1];
            else if(i != 0 and j == 0)
                M[i][j] = M[i - 1][j];
            else if(i != 0 and j != 0)
                M[i][j] = M[i - 1][j] + M[i][j - 1] - M[i - 1] [j - 1];
            if(farm[i][j] == '#')
                M[i][j] += 1;
        }
    }
    
    //Calculation of S1, S2, S3, S4 i.e., the sum of each quadrant.
    //Ramu will get minimum trees but the minimum should be maximized i.e. if we cut at the right position then Ramu will get atleast a maximum of this many trees.
    //If we cut at other positions his number of trees will be very low.  But compared to others he will be having either equal or smaller number of trees only.
    /*
     Top-Left: S1
     Top-Right: S2
     Bottom-Left: S3
     Bottom-Right: S4
    */
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            S1 = M[i][j];
            S2 = M[i][n-1] - S1;
            S3 = M[n-1][j] - S1;
            S4 = M[n-1][n - 1] - (S1 + S2 + S3);
            maximized_minimum = max(min(min(S1, S2), min(S3, S4)), maximized_minimum);
        }
    }
    cout << "Ramu will get a maximized minimum of " << maximized_minimum <<" trees"; 
    /*
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    */
}


int main()
{
    int n = 6;
    char farm[10][10] = { "-##---",
                       "#--##-",
                       "-#----",
                       "-##--#",
                       "#--##-",
                       "-#----"
                     };
    cout << "Farm is here" << endl;
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<farm[i][j] << " ";
        cout << endl;
    }
    
    prefixSum2dMango(farm, n);    
    return 0;
}
