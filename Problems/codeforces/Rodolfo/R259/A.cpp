#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define first f
#define second s
#define pb push_back

using namespace std;

typedef pair <int,int> PII;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; string x;
	cin>>n; cin>>x;
	int cont=0;
	int i=2;
	while(cont<n){
		cout<<x[cont];
		cont+=i;
		i++;
	}
	
	return 0;
}
