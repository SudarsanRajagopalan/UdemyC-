//Expected Time Complexity: O(N)
/*
  Given an array of characters chars, compress it using the following algorithm:
  Begin with an empty string s. For each group of consecutive repeating characters in chars:
    (i)  if the group's length is 1, append the character to s.
    (ii) Otherwise, append the character followed by the group's length.
  The compressed string s should not be returned separately, but instead be stored in the input character array chars.
  . Note that group lengths that are 10 or longer will be split into multiple characters in chars.
  
  After you are done modifying the input array, return the new length of the array.
  You must write an algorithm that uses only constant extra space.
*/

#include<bits/stdc++.h>
using namespace std;


int compress(vector<char>& chars) {
    // your code goes here
    string s;
    int count, i=0;
    while(chars[i])
    {
        count = 0;   
        while(chars[i] == chars[i+1])
        {
            count++;
            i++;
        }
        //s.append(1,chars[i]);
        s += chars[i];
        if(count >= 1)
            s.append(to_string(count+1));
        i++;
    }
    /*
    for(int i =0; i<s.length(); i++)
        chars[i] = s[i];
    return s.length();   
    */
    chars.clear();
    for(int i =0; i<s.size(); i++)
        chars.push_back(s[i]);
    return chars.size();
}
