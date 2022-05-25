/*
Given a string consisting of lowercase English alphabets, return a string containing all the vowels present in S in serial order.
*/


//Expected Time Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
//#define all(s) s.begin(), s.end()

string vowel(string S){
    // your code goes here
    string str;
    for(auto x : S)
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u')
            str.push_back(x);
    //sort(all(str)); 
    /* No  need to sort as the question asked in serial order and not sorted
       order */
    return str;
} 
