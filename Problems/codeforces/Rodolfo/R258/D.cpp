#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;

#define MAXN 200050 
#define F first
#define S second
#define pb push_back

int n;
double sum;


int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>n>>sum;
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int cont=0;
	for(int i=0;i<n;++i){
		if(adj[i].size()==1){
			cont++;
		}
	}

	double dv = cont;
	cout<<setprecision(15)<<cont/dv*2<<'\n';

	
	return 0;
}
