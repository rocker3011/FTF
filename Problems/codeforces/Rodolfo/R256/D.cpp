#include <bits/stdc++.h>

using namespace std;

class edge{
	public:
		int x;
		long long c;
		edge(int x, long long c){
			this->x = x;
			this->c = c;
		}
};

vector <edge> adj[300050];
int n;
long long arr[300050];

long long tot = 0LL;

long long dfs(int x, int p){
	long long max1=0LL;
	long long max2=0LL;
	int cont=0;
	for (int i=0;i<adj[x].size();++i){
		int d = adj[x][i].x;
		long long c = adj[x][i].c;
		if(d==p) continue;
		long long res = dfs(d,x)-c;
		if (res>=max1){
			max2=max1;
			max1=res;
		}else if(res>=max2){
			max2=res;
		}
	}
	tot = max(tot,max1+max2+arr[x]);
	return max1+arr[x];
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin>>n;
	for (int i=0;i<n;++i){
		cin>>arr[i];
	}

	for (int i=0;i<n-1;++i){
		int x,y;
		long long c;
		cin>>x>>y>>c;
		adj[x-1].push_back(edge(y-1,c));
		adj[y-1].push_back(edge(x-1,c));
	}

	dfs(0,-1);

	cout<<tot<<'\n';

	return 0;
}