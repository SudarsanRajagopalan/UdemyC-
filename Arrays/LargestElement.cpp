//Implement a function that takes array of integers as input and return the largest element.

//Expected Time Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> arr) {
    int largest_ele = INT_MIN;
    
    for(int i=0; i <arr.size(); i++)
        largest_ele = max(largest_ele, arr[i]);
    
    return largest_ele;
     
}
