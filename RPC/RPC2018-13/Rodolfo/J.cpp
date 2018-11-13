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

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

int movx[]={1,-1,1,-1,0,0,1,-1};
int movy[]={0,0,1,-1,1,-1,-1,1};
int dist[MAX_N][MAX_M];
int g[3][400000];

void BFS (int n,int m,int tam){
    queue <node> q;
    memset(dist,0x3f3f3f3f,sizeof(dist));
    for (int i=0;i<tam;++i){
        q.push(node(g[0][i],g[1][i],0));
        dist[g[0][i]][g[1][i]] = 0;        
    }

    while(!q.empty()){
        node v = q.front(); q.pop();
        //if (dist[v.x][v.y]<=v.step) continue;
        
        for(int i=0;i<8;++i){
            int aux = movx[i] + v.x;
            int auy = movy[i] + v.y;
            if(aux<0 || aux>n || auy<0 || auy>m) continue;
            if (dist[aux][auy]<=v.step+1) continue;
            dist[aux][auy]=v.step+1;
            q.push(node(aux,auy,v.step+1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    fastscan(n);
    fastscan(q);
    for (int i=0;i<n;++i){
        int x,y;
        fastscan(x);
        fastscan(y);
        g[0][i]=x;
        g[1][i]=y;
    }
    BFS(5000,5000,n);
    for(int i=0;i<q;++i){
        int x,y;
        fastscan(x);
        fastscan(y);
        printf("%d\n",dist[x][y]);
    }

    return 0;
}
