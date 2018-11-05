#include <bits/stdc++.h>

using namespace std;

#define MAX_N 5050
#define MAX_M 5050
class node{
    public:
    int x,y,step;
    node(int x,int y,int step){
        this->x = x;
        this->y = y;
        this->step = step;
    }
};

int movx[]={1,-1,1,-1,0,0,1,-1};
int movy[]={0,0,1,-1,1,-1,-1,1};
int dist[MAX_N][MAX_M];

void BFS (int n,int m,vector <pair <int,int> > g){
    queue <node> q;
    memset(dist,0x3f3f3f3f,sizeof(dist));
    for (int i=0;i<(int)g.size();++i){
        q.push(node(g[i].first,g[i].second,0));
    }

    while(!q.empty()){
        node v = q.front(); q.pop();
        
        if (dist[v.x][v.y]<=v.step) continue;
        dist[v.x][v.y] = v.step;
        
        for(int i=0;i<8;++i){
            int aux = movx[i] + v.x;
            int auy = movy[i] + v.y;
            if(aux<0 || aux>=n || auy<0 || auy>=m) continue;
            if (dist[aux][auy]<=v.step+1) continue;
            q.push(node(aux,auy,v.step+1));
        }
    }
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    vector < pair<int,int> > g;
    for (int i=0;i<n;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        g.push_back(make_pair(x,y));
    }
    BFS(5000,5000,g);
    for(int i=0;i<q;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",dist[x][y]);
    }

    return 0;
}
