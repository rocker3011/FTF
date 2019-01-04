//Problem H: Highway Decommission
//Type: Dijkstra
//We run Dijkstra and when 2 edges create a path of minimum weight , we take the edge of minimum cost
//This works because when you try to solve it by Dijkstra + DP you will realize you only go up one level on the Dijkstra tree

#include <bits/stdc++.h>

using namespace std;

class edge{
    public:
    int x;
    long long c,d;
    edge(int x, long long d, long long c){
        this->x = x;
        this->c = c;
        this->d = d;
    }

    bool operator < (const edge &other) const{
        return d > other.d;
    }
};

long long dist[10010];
long long cost[10010];

vector <edge> v[10010];
int n,m;

long long dijkstra(){
    dist[1]=0;
    cost[1]=0;
    priority_queue <edge> pq;
    pq.push(edge(1,0,0));
    while(!pq.empty()){
        edge a = pq.top(); pq.pop();
        if (a.d > dist[a.x]) continue;
        for(int i=0;i<(int)v[a.x].size();++i){
            int x = v[a.x][i].x;
            long long d = v[a.x][i].d + a.d;
            long long c = v[a.x][i].c;
           
            if(d > dist[x]) continue;
            if(d==dist[x]){
                cost[x] = min(cost[x],c);
                continue;
            }
            if(d<dist[x]){
                cost[x]=c;
                dist[x]=d;
                pq.push(edge(x,d,c));
            }
        }
    }

    long long res=0LL;
    for(int i=1;i<=n;++i){
        res+=cost[i];
    }
    return res;
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i){
        dist[i]= LLONG_MAX;
        cost[i]= LLONG_MAX;
    }
    for (int i=0;i<m;++i){
        int x,y;
        long long d,c;
        scanf("%d %d %lld %lld",&x,&y,&d,&c);
        v[x].push_back(edge(y,d,c));
        v[y].push_back(edge(x,d,c));
    }

    printf("%lld\n",dijkstra());

    return 0;
}