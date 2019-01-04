#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        long long k,a,b;
        cin>>a>>b>>k;
        if((k)%2!=0){
            cout<<(a-b)*(k/2)+a<<'\n';
        }else{
            cout<<(a-b)*(k/2)<<'\n';
        }
    }
    return 0;
}