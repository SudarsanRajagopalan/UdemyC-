//Expected Time Complexity: O(Log N)
//Hint: Count  number of set bits in k
/*
The Planet Earth is under a threat from the aliens of the outer space and your task is to defeat an enemy who is N steps above you (assume yourself to be at ground level i.e. at the 0th level). You can take jumps in power of 2. In order to defeat the enemy as quickly as possible you have to reach the Nth step in minimum moves possible. 

Sample Input:
7

Sample Output:
3

Explanation:
0 -> 4 -> 6 -> 7
*/

#include<bits/stdc++.h>
using namespace std;

int earthLevel(int k)
{/*
    int res = 0;
    while(k > 0)
    {
        int last_bit = (k & 1);
        if(last_bit)
            res++;
        k >>= 1;
    }
    return res;
    */
    int res = 0;
    while(k > 0)
    {
        res++;
        k = k & (k-1);
    }
    return res;
}
