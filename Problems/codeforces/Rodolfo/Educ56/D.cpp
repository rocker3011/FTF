#include <bits/stdc++.h>

using namespace std;
#define MOD 998244353LL

vector <int> adj[300005];
int color[300005];
long long c[5];

int n,m;

int bfs(int y){
	queue <int> q;
	color[y]=1;
	c[color[y]]++;
	int tam=1;
	q.push(y);
	while(!q.empty()){
		int x = q.front(); q.pop();

		for (int i=0;i<adj[x].size();++i){
			int d = adj[x][i];
			if(color[d]==color[x]) return -1;
			if(color[d]) continue;
			color[d]=(color[x])%2+1;
			c[color[d]]++;
			tam++;
			q.push(d);
		}
	}
	if (tam==1) return 0;
	return 1;
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;++i){
			adj[i].clear();
			color[i]=0;
		}
		for (int i=0;i<m;++i){
			int x,y;
			cin>>x>>y;
			x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		long long sum = 1LL;
		for (int i=0;i<n;++i){
			if (color[i]) continue;
			c[1] = c[2] = 0;
			long long res = bfs(i);

			if(res==-1){
				sum=0LL;
				break;
			}else if(res==0){
				sum= (sum%MOD * 3LL%MOD)%MOD;
			}else{
				long long ans1,ans2;
				ans1=ans2=1LL;
				for(int i=0;i<c[1];++i) ans1= (ans1%MOD * 2LL%MOD)%MOD;
				for(int i=0;i<c[2];++i) ans2= (ans2%MOD * 2LL%MOD)%MOD;
				sum= (sum%MOD * ((ans1%MOD+ans2%MOD)%MOD)%MOD)%MOD;
			}

		}
		
		cout<<sum<<endl;
	}

	return 0;
}