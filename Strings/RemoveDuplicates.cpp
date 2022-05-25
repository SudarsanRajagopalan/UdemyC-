/*
Given a string, the task is to remove all the duplicates from the given string and return the updated string in sorted order.
*/
//Expected Time Complexity : O(N)
#include <bits/stdc++.h>
using namespace std;


string removeDuplicate(string s){
    // your code goes here
    set<char> ss(s.begin(), s.end());
    string str;
    for(char x : ss) //for(auto x : ss)
        str.push_back(x);
    return str;
}

/*
#define all(v) v.begin(), v.end()
#define erase(v,index, count) v.erase(index, count)

string removeDuplicate(string s){
    // your code goes here
    sort(all(s));
    int i = 0, j, count;
    while(s[i])
    {
        j = i;
        count = 0;
        while(s[j] == s[j+1])
        {
            count++;
            j++;
        }
        if(count != 0)
            erase(s, i+1, count);
        i++;
    }
    return s;
}
*/
