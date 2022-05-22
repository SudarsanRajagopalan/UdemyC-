/* Given an integer vector and a value k, your task is to rotate the array k times clockwise */

//Expected Time Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k){
    vector<int> b;
    int n = a.size();
    k = k%n; 
    /*This is for if k is more than n.  for example
    if k=6 and n=5 then 6 number of rotations is equivalent to doing 1 rotation */
    for(int i=0; i<n; i++)
    {
        if(i < k)
            b.push_back(a[n+i-k]);
        else
            b.push_back(a[i-k]);
    }
    return b;
}

/*
vector<int> kRotate(vector<int> a, int k){
    vector<int> b(a.size(), 0);
    int b_arr_counter = 0;
    for(int i=a.size()-k; i<a.size(); i++)
        b[b_arr_counter++] = a[i];
    for(int j=0; j<a.size()-k; j++)
        b[b_arr_counter++] = a[j];
    return b;
}
*/
