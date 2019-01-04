#include <bits/stdc++.h>

using namespace std;

pair <long long,long long> p[200010];
map <long long,int> freq;

int main(){

    int n; scanf("%d",&n);
    for (int i=0;i<n;++i){
        long long x; cin>>x;
        p[i]={x,i};
    }
    sort(p,p+n);
    


    return 0;
}