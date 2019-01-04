#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define first f
#define second s
#define pb push_back

using namespace std;

typedef pair <int,int> PII;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int y,b,r;
	cin>>y>>b>>r;

	set <PII> S;
	S.insert({y,0});
	S.insert({b,1});
	S.insert({r,2});

	set <PII> :: iterator it;

	for(it=S.begin();it!=S.end();it++){
		
	}

	
	return 0;
}
