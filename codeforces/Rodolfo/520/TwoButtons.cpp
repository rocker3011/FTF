//Can be solved O(log(n)) if reversed, instead of n-1 or n*2 doing m+1 or m/2
//that way you can do this problem in O(log(n)) sufficing for even 10^9 input!!!

#include <bits/stdc++.h>

using namespace std;

bool mark[20005];

int bfs(int n,int m){
    if(n==m){
        return 0;
    }

    queue <int> q;
    queue <int> p;
    q.push(n);
    p.push(0);
    while(!q.empty()){
        int x = q.front();
        int y = p.front();
        q.pop(); p.pop();
        if(mark[x]) continue;
        mark[x]=true;
        if(x==m) return y;
        if(x*2<=20000){
            q.push(x*2);
            p.push(y+1);
        }
        if (x-1 >= 0){
            q.push(x-1);
            p.push(y+1);
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d\n",bfs(n,m));
}