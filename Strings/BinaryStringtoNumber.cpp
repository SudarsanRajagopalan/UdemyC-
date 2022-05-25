/*
Given a binary string as input, convert into its decimal form and return it as an integer.
*/
//Expected Time Complexity : O(N)
#include <iostream>
#include <string>
#include<cmath>
using namespace std;
 
int binaryToDecimal(string s)
{
    int base = 1;
    int dec_value = 0;
    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i] == '1')
            dec_value += base;
        /*
        dec_value += (s[i] - '0') * base;
        */
        base *= 2;
    }
    return dec_value;
}
