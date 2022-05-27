/*
Given a matrix of size M x N, there are large number of queries to find submatrix sums. Inputs to queries are left top and right bottom indexes of submatrix whose sum is to find out.
How to preprocess the matrix so that submatrix sum queries can be performed in O(1) time.
*/    

#include<bits/stdc++.h>
using namespace std;


int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
    vector<vector<int>> aux = v;
    int M = aux.size();
    int N = aux[0].size();
    int tli = sr, tlj = sc, rbi = er, rbj = ec;
    
    //Building Auxiliary Matrix - Time Complexity: O(M*N)
    //Auxiliary matrix M[i,j] represents the sum from (0,0) to (i,j)
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i==0 and j!=0)
                aux[i][j] += aux[i][j-1];
            else if(i!=0 and j==0)
                aux[i][j] += aux[i-1][j];
            else if(i!=0 and j!=0)
                aux[i][j] += aux[i-1][j] + aux[i][j-1] - aux[i-1][j-1];
        }
    }
    /*
     A O(1) time function to compute sum of submatrix
     between (tli, tlj) and (rbi, rbj) using aux[][]
     which is built by the preprocess function
    */
    
    // result is now sum of elements between (0, 0) and
    // (rbi, rbj)
    int res = aux[rbi][rbj];
    
    // Remove elements between (0, 0) and (tli-1, rbj)
    if(tli > 0)
        res -= aux[tli-1][rbj];
        
    // Remove elements between (0, 0) and (rbi, tlj-1)
    if(tlj > 0)
        res -= aux[rbi][tlj-1];
        
    // Add aux[tli-1][tlj-1] as elements between (0, 0)
    // and (tli-1, tlj-1) are subtracted twice
    if(tli > 0 and tlj > 0)
        res += aux[tli-1][tlj-1];
        
    return res;    
}

/*
Time Complexity: O((er-sr) * (ec - sc))
int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
    int sum = 0;
    for(int i=sr; i<=er; i++)
    {
        for(int j=sc; j<=ec; j++)
            sum += v[i][j];
    }
    return sum;
}
*/
