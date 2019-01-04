#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

#define MAXN 1005
#define F first
#define S second
#define pb push_back

class edge{
	public: 
	int x,y,c;
	
	edge(int x,int y,int c){
		this->x = x;
		this->y = y;
		this->c = c;
	}
};

PII padre[4][MAXN][MAXN];
int dist[4][MAXN][MAXN];
bool desco[4][MAXN][MAXN];
vector <PII> pos;

int movx[]={1,-1,0,0};
int movy[]={0,0,1,-1};

void bfs(int x){
	queue <edge> q;
	q.push(edge((int)pos[x].F,(int)pos[x].S,0));
	dist[x][pos[x].F][pos[x].S]=0;
	
	while(!q.empty()){
		edge v = q.front(); q.pop();
		
		for(int i=0;i<4;++i){
			int aux = movx[i] + v.x;
			int auy = movy[i] + v.y;
			if(aux<0 || auy<0 || aux>1000 || auy>1000) continue;
			if(dist[x][aux][auy] > v.c+1){
				dist[x][aux][auy]=v.c+1;
				padre[x][aux][auy]={v.x,v.y};
				q.push(edge(aux,auy,v.c+1));
			}
			
		}
	}
	
}

int main(){
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for(int i=0;i<3;++i){
		int x,y;
		cin>>x>>y;
		pos.push_back({x,y});
	}
	
	for(int i=0;i<3;++i){
		for(int j=0;j<MAXN;++j){
			for(int w=0;w<MAXN;++w){
				dist[i][j][w]=0x3f3f3f3f;
			}
		}
	}
	
	for(int i=0;i<3;++i){
		bfs(i);
	}

	int minimo = 0x3f3f3f3f;
	PII punto_medio;
	for(int i=0;i<=1000;++i){
		for(int j=0;j<=1000;++j){
			if(minimo > dist[0][i][j] + dist[1][i][j] + dist[2][i][j]){
				minimo = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
				punto_medio = {i,j};
			}
		}
	}
	set <PII> camino;
	for(int i=0;i<3;++i){
		PII finish = pos[i];
		PII ele = punto_medio;
		int x,y;
		x = ele.F; y=ele.S;
		
		while(ele!=finish){
			camino.insert(ele);
			ele = padre[i][ele.F][ele.S];
			
		}
		camino.insert(finish);
	}
	cout<<(int)camino.size()<<'\n';
	
	for(auto go : camino){
		cout<<go.F<<" "<<go.S<<'\n';
	}
	
	
	return 0;
}