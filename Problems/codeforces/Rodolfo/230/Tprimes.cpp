#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000000000LL
int p[1000050];

void criba(){
    memset(p,0LL,sizeof(p));
    for (long long i=4;i*i<MAXN;i+=2) p[i] = 2;

    for (long long i=3;i*i<MAXN;i+=2){
        if (!p[i]){
            for (long long j=i*i; j<1000050; j+=2*i){
                p[j]=i;
            }
        }
    }   
}

int main(){
    int n;
    scanf("%d",&n);
    criba();
    while(n--){
        double x;
        cin>>x;
        if (x==1){
            puts("NO");
        }else if (sqrt(x) == (floor(sqrt(x)))){
            long long y = (long long) sqrt(x);
            long long z = (long long) x;
            if (!p[y]){
                if (z==4 || z%2==1)
                    puts("YES");
                else
                    puts("NO");
            }else{
                puts("NO");
            }
        }else{
            puts("NO");
        }
    }
}