#include <bits/stdc++.h>

using namespace std;

pair <long long,int> p[200010];

long long acum[200010];

int main(){
    int n;
    scanf("%d",&n);
    vector <int> res;
    for (int i=0;i<n;++i){
        long long x;
        cin>>x;
        p[i]={x,i};
    }
    if(n<=2){
        puts("0");
    }else{
        sort(p,p+n);
        acum[0]=p[0].first;
        for (int i=1;i<n;++i){
            acum[i]+=acum[i-1]+p[i].first;
        }
        long long x = p[n-1].first;
        long long acx = acum[n-2];

        for (int i=n-2;i>=0;--i){
            if(acx - p[i].first == x){
                res.push_back(p[i].second+1);
            }
        }

        x = p[n-2].first;
        acx = acum[n-3];
        if(x == acx){
            res.push_back(p[n-1].second+1);
        }

        printf("%d\n",(int)res.size());
        for(int i=0;i<(int)res.size();++i){
            printf("%d ",res[i]);
        }
        puts("");
    }
    return 0;
}