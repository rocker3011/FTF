//BFS 2D O(N*M) 
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

int movx[]={1,-1,0,0};
int movy[]={0,0,1,-1};
int dist[MAX_N][MAX_M];

int BFS (int x,int y,int dx,int dy,int n,int m){
    queue <node> q;
    memset(dist,0x3f3f3f3f,sizeof(dist));
    while(!q.empty()){
        node v = q.front(); q.pop();
        if (v.x==dx && v.y==dy) return v.step;
        if (dist[v.x][v.y] <= v.step) continue;
        dist[v.x][v.y]=v.step;
        for(int i=0;i<4;++i){
            int aux = movx[i] + v.x;
            int auy = movy[i] + v.y;
            if(aux<0 || aux>=n || auy<0 || auy>=m) continue;
            if (dist[aux][auy]<=v.step+1) continue;
            q.push(node(aux,auy,v.step+1));
        }
    }
}