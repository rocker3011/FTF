#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;
vector <int> tree[MAXN]; //arbol
long long sum[MAXN];
long long a[MAXN];

void addEdge(int u, int v){
	tree[u].push_back(v);
	tree[v].push_back(u);
}

long long res = 0LL;

void dfs(int src, int p=-1,long long h=0){
	sum[src] = a[src];
	res = res + h*a[src];

	for (int i=0;i<tree[src].size();++i){
		int d = tree[src][i];
		if(d!=p){
			dfs(d,src,h+1);
			sum[src]+=sum[d];
		}
	}
}

long long ans = 0LL;

void dfsg(int src, int p=-1){
	ans = max(ans,res);

	for(int i=0;i<tree[src].size();++i){
		int d = tree[src][i];
		if(d!=p){
			res-=sum[d];
			sum[src]-=sum[d];
			res+=sum[src];
			sum[d]+=sum[src];

			dfsg(d,src);

			sum[d]-=sum[src];
			res-=sum[src];
			sum[src]+=sum[d];
			res+=sum[d];
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>a[i];
	}
	for (int i=0;i<n-1;++i){
		int x,y;
		cin>>x>>y;
		x--; y--;
		addEdge(x,y);
	}

	dfs(0);
	dfsg(0);
	cout<<ans<<'\n';
	
	return 0;
}