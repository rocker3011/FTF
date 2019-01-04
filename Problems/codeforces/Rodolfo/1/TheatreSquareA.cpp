#include <bits/stdc++.h>

using namespace std;


int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long x = ceil( (double) a/c) * ceil( (double) b/c);
    printf("%lld\n",x);
}