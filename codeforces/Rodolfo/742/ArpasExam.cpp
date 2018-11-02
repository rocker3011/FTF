#include <bits/stdc++.h>

using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
long long power(long long x, unsigned long long y, long long p) 
{ 
    long long res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

int main(){
    long long n;
    cin>>n;
    cout<<(power(1378LL,n,10))<<'\n';
}