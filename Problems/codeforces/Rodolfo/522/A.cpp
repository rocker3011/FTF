#include <bits/stdc++.h>

using namespace std;

map <int,int> m;

set <int> s;
vector <int> v;
int main(){
    //FAST INPUT y OUTPUT
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n,k;
    cin>>n>>k;
    int maximo = 0;
    for (int i=0;i<n;++i){
        int x; cin>>x;
        m[x]++;
        if (!s.count(x)){
            v.push_back(x);
            s.insert(x);
        }
        maximo = max(m[x],maximo);
    }

    while(maximo%k!=0){
        maximo++;
    }
    maximo = maximo*(int)v.size();

    for (int i=0;i<(int)v.size();++i){
        maximo-=m[v[i]];    
    }

    printf("%d\n",maximo);

    return 0;
}