#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define first f
#define second s
#define pb push_back

using namespace std;

typedef pair<int,int> PII;

class edge{
	public:
	int x,y;
	long long c;
	edge(int x,int y,long long c){
		this->x = x;
		this->y = y;
		this->c = c;
	}

	bool operator < (const edge& other) const{
		return c < other.c;
	}
};

long long cost[200010];
bool mark[200010];
int p[200010];
vector <edge> v;

int Find(int x){
	if(x==p[x]) return x;

	return p[x] = Find(p[x]);
}

void Union(int x,int y){
	x = Find(x);
	y = Find(y);

	p[y] = x;

}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long minimo = LLONG_MAX;
	int imin = -1;
	for(int i=1;i<=n;++i){
		p[i]=i;
		cin>>cost[i];
		if(cost[i]<minimo){
			imin=i;
			minimo = cost[i];
		}
	}

	for(int i=0;i<m;++i){
		int x,y;
		long long c;
		cin>>x>>y>>c;
		v.push_back(edge(x,y,c));
	}
	for(int i=1;i<=n;++i){
		if(i==imin) continue;
		v.push_back(edge(i,imin,cost[i]+minimo));
	}
	sort(v.begin(),v.end());

	long long res = 0LL;

	for(int i=0;i<(int)v.size();++i){
		int x = v[i].x;
		int y = v[i].y;
		long long c = v[i].c;

		if(Find(x) == Find(y)) continue;

		Union(x,y);
		res+=c;

	}
	cout<<res<<'\n';

	return 0;
}