#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;

int main(){
    ll N;cin>>N;
    vector<ll> a(N);
    for(int j=0; j<N; ++j){
        cin>>a[j];
    }
    ll M=2002;
    vector<ll> d(M);
    for(int j=0; j<M; ++j){
        set<ll> s;
        for(int k=1; k<j; ++k){
            ll divr=j/k;
            ll rest=j%k;
            ll x=0;
            if(divr%2!=0) x^=d[k];
            x^=d[rest];
            s.insert(x);
        }
        ll val=0;
        while(s.count(val)){
            ++val;
        }
        d[j]=val;
    }
    ll x=0;
    for(int j=0; j<N; ++j){
        x^=d[a[j]];
        cout<<d[a[j]]<<endl;
    }

    cout<<(x?"First":"Second")<<endl;
    
    return 0;
}

