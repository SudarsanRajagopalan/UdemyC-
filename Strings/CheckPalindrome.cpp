//Time Complexity: O(N)
/*
Given a string, write a c function to check if it is palindrome or not. 
A string is said to be palindrome if reverse of the string is same as string. For example, “abba” is palindrome, but “abbc” is not palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;
    
    while(start < end)
    {
        if(str[start++] != str[end--])
            return false;
    }
    return true;
}

/*
#define all(a) a.begin(), a.end()


bool isPalindrome(string str)
{
    bool palindrome_flag;
    string newstr;
    newstr = str;
    reverse(all(newstr));
    str.compare(newstr) == 0 ? palindrome_flag = true : palindrome_flag = false;
    return palindrome_flag;
}
*/
