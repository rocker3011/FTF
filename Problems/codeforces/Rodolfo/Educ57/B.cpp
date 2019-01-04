#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define first f
#define second s
#define pb push_back

using namespace std;

typedef pair <int,int> PII;

map <int,int> mp;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	string x;
	cin>>x;
	int cont=0;
	for(int i=0;i<n;++i){
		mp[x[i]-'a']++;
	}

	

	

}