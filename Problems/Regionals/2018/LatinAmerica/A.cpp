//Problem A: A Symmetrical Pizza
//Type: Math, Least Common Multiplier/ Greatest Common Divisor
//As you are cutting the pizza in the maximum number of slices of the same size, you need to cut until you find yourself
//In a previously cutted point, this cyclick point is the LCM of (angle,360)/angle (this is because we transform from degrees to numbers)
//This is the same as GCD of (angle,360)/360
//Another thing is that we need to work all of this on Integer



#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

long long lcm(long long a, long long b)  
 {  
    return (a*b)/gcd(a, b);  
 }  

int main(){
    long long x,y;
    scanf("%lld.%lld",&x,&y);
    long long z = (long long)(x*100LL+y);
    printf("%lld\n",lcm(z,36000LL)/z);

    return 0;
}