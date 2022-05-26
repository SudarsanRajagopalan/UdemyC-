/*
 Pascal's triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n 
 as input and returns 2D array with first n lines of the Pascal’s triangle.
 
 Following are the first 5 rows of Pascal’s Triangle.
 1
 1 1
 1 2 1
 1 3 3 1
 1 4 6 4 1
 
 https://www.tutorialcup.com/leetcode-solutions/pascals-triangle-ii-leetcode-solution.htm#:~:text=Maths-,Approach%201%20(Brute%20Force%20Recursion),and%20return%20the%20formed%20list.
 */
#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(N^2)
vector<vector<int>> printPascal(int n)
{
    // your code goes here
    vector<vector<int>> pascal_triangle;
    for(int line = 0; line < n; line++)
    {
        vector<int> v;
        for(int i = 0; i <= line ; i++)
        {
            if(line == i or i == 0)
                v.push_back(1);
            else
                v.push_back((int) ((long long) v.back() * (line - i + 1) / i));  //Factor multiple of Binomial theorem nCr
        }
        pascal_triangle.push_back(v);
    }
    return pascal_triangle;
}

 



