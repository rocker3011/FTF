//273B
//Category: Math and Combinatorics
//Solution: Since limits are very high (10^9) we need some observations, use them as tips:

/*  1- the maximum amount of pairs is fill with 1's all teams and then give all the rest of members to 1 team 
    on example (3 6) would be (1 1 4)
    2- the minimum amount of pairs is filling as a sweep until no more members can be added
    on example (3 6) would be (2 2 2)
    3- For the minimum we need to take into account what happens when n is not divisible by m
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    long long tl  = m - n%m ; // teams with 1 less member
    long long tm  = n%m;      // teams with 1 more member

    long long max_me = (n - (m-1) ) * ( (n - (m-1) ) - 1 )/2 ; //since all teams with 1 member have 0 pairs, we just take them out and calculate the pairs on 1 team
    
    long long min_me = ((n/m)*(n/m-1)/2) * tl + ((n/m +1)*(n/m)/2) * tm; // since there are 2 different sizes to calculate for the minimum we calculate the pairs for one group, and the pairs for the other

    cout<<  min_me << " " << max_me << '\n'; //printing in cout isn't good, however for O(1) long long formulas on codeforces it might be a good idea
    return 0;
}