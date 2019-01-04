#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
string a;
long long memo[3][1001][1001];
bool mark[3][1001][1001];

long long DP(int car,int i,int k){
    if(car==1 && i<0 && k==1) return 1LL;
    if (car==1 && i<0 && k!=1) return 0LL;
    if(k<0) return 0LL;
    if(i<0 && k==0) return 1LL;
    if(i<0) return 0LL;

    long long &best = memo[car][i][k];

    if(mark[car][i][k])
        return best;
    long long one,zero;
    mark[car][i][k]=true;
    
    int res = a[i]-'0';
    if (car==1 && res==1){
        one = DP(1,i-1,k-1)%MOD;
        zero = DP(1,i-1,k)%MOD;
    }else if (car==1 && res==0){
        one = DP(1,i-1,k)%MOD;
        zero = DP(0,i-1,k-1)%MOD;
    }else if (car==0 && res==1){
        one = DP(1,i-1,k)%MOD;
        zero = DP(0,i-1,k-1)%MOD;
    }else if (car==0 && res==0){
        one = DP(0,i-1,k-1)%MOD;
        zero = DP(0,i-1,k)%MOD;
    }

    best = (one%MOD + zero%MOD)%MOD;
    return best;

}

int main(){
    int n,k;

    scanf("%d %d",&n,&k);
    cin>>a;
    cout<<DP(0,n-1,k)<<'\n';

    return 0;
}