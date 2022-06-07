//Expected Time Complexity : O(Log N)
//Given three numbers x, y and mod, compute x raised to power y modulo mod i.e.  (x^y)%mod
//Doing Fast Exponenation - O(Log N) ie.  O(Log y) in this case

#include <iostream>
using namespace std;
 
 
int power(int x, int y, int mod)
{
    int ans = 1;
    x = x % mod; //Update x if it is more than mod
    
    if(!x)
        return 0; //if x is exactly divisible by mod then x would be 0 
                  //therefore x^y will be 0.
    
    while(y > 0)
    {
        int last_bit = (y&1);
        
        if(last_bit)
            ans = (ans*x) % mod;
            
        x = (x * x) % mod; 
        y = y >> 1;
        
    }
    
    return ans;
}
