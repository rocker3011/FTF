#include <bits/stdc++.h>

using namespace std;

int main(){

    vector <int> v;
    for (int i=0;i<5;++i){
        int x; scanf("%d",&x);
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    int streak = 1;
    int cur = v[4];
    int sum_streak = cur;
    int maximo =0;
    int sum = cur;

    for (int i=3;i>=0;--i){
        sum+=v[i];
        if(cur == v[i]){
            streak++;
            if (streak<4){
                if(sum_streak+cur > maximo && streak>=2){
                    maximo = sum_streak+cur;
                }
                sum_streak+=cur;
            }else{
                streak=0;
                sum_streak=0;
            }
        }else{
            cur=v[i];
            streak=1;
            sum_streak=cur;
        }
    }
    printf("%d\n",sum-maximo);

    return 0;
}