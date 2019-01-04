#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define f first
#define s second
#define pb push_back

using namespace std;

typedef pair <int,int> PII;

PII p[200010];

bool check(int l, int r){
	vector <int> ans;

	for(int i=0;i<n;++i){
		int nxt = -1;
		if(p[l].f == r){
			nxt= p[l].s;
		}else if(p[l].s == r){
			nxt = p[l].f;
		}else{
			return false;
		}
		ans.push_back(nxt);
		l = r;
		r = nxt;

	}

	for(auto it : ans){
		cout<<it << ' ';
	}
	cout<<'\n';
	return true;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin>>n;

	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		p[i] = {x,y};
	}

	if (!check(0,p[0].f)){
		check(0,p[0].s);
	}

	
	return 0;
}
