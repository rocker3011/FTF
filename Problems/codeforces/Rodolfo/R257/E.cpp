#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;
vector <int> tree[MAXN]; //arbol
bool mark[MAXN];
int dist[3][MAXN];
int cc[MAXN];
vector <int> c;

void addEdge(int u, int v){
	tree[u].push_back(v);
	tree[v].push_back(u);
}

void bfs(int src,int w){
	queue < pair <int,int> > q;
	q.push({src,0});
	dist[w][src]=0;
	while(!q.empty()){
		pair <int,int> v = q.front(); q.pop();
		int x = v.first;
		int c = v.second;
		for(int i=0;i<tree[x].size();++i){
			int y = tree[x][i];
			int cost = c + 1;
			if(dist[w][y] > cost){
				dist[w][y] = cost;
				q.push({y,cost});
			}
		}
	}
}

int diametro;

void dfs(int src, int cont, int &cual,int h){
	mark[src]=true;
	if(cc[src]==0){
		cc[src]=cont;
		c.push_back(src);
	}
	
	for (int i=0;i<tree[src].size();++i){
		int d = tree[src][i];
		if (mark[d]) continue;
		dfs(d,cont,cual,h+1);
	}
	if(h>=diametro){
		diametro=h;
		cual=src;
	}

}



int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		
		addEdge(x,y);
	}
	vector <pair <int,int> > res;
	vector <pair <int,int> > center;
	int cont=0;
	int x,y,z;
	memset(cc,0,sizeof(cc));
	for (int i=1;i<=n;++i){
		if(cc[i]) continue;
		//cout<<"Problema antes del DFS"<<endl;
		c.clear();
		cont++;
		memset(mark,0,sizeof(mark));
		x=y=i;
		diametro = 0;
		dfs(i,cont,x,0);
		diametro = 0;
		//cout<<"Problema despues del primer DFS"<<endl;
		memset(mark,0,sizeof(mark));
		dfs(x,cont,y,0);
		for (int j=0;j<c.size();++j){
			dist[0][c[j]]=0x3f3f3f3f;
			dist[1][c[j]]=0x3f3f3f3f;
		}

		//cout<<x<<" "<<y<<endl;
		//cout<<"Problema despues del segundo DFS"<<endl;
		bfs(x,0);
		//cout<<"Problema despues del primer BFS"<<endl;
		bfs(y,1);
		//cout<<"Problema despues del segundo BFS"<<endl;
		for(int j=0;j<c.size();++j){
			//cout<<"Problema durante los c"<<endl;
			int d = c[j];
			if ( (dist[0][d]==diametro/2 && dist[1][d]== diametro-diametro/2) || (dist[0][d]==diametro-diametro/2 && dist[1][d]==diametro/2)) {
				center.push_back({diametro,d});
				break;
			}
		}
	}
	//cout<<"Problema en la parte del ordenamiento"<<endl;
	
	
	if(center.size()>0){
		sort(center.begin(),center.end());
		x = center[center.size()-1].second;
	}
	int ss = (int)center.size();
	for (int i=0;i<ss-1;i++){
		res.push_back({x,center[i].second});
		addEdge(x,center[i].second);
	}

	memset(mark,0,sizeof(mark));
	diametro=0;
	dfs(1,cont,y,0);
	memset(mark,0,sizeof(mark));
	diametro=0;
	dfs(y,cont,z,0);

	printf("%d\n",diametro);
	for(int i=0;i<res.size();++i){

		printf("%d %d\n",res[i].first,res[i].second);
	}
	
	return 0;
}