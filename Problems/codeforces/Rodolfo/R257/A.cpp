#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string str = "";
		int cont=0;
		for(int i=0;i<n;++i){
			str.push_back(cont+'a');
			cont++;
			cont = cont%k;
			
		}
	
		cout<<str<<'\n';

	}
	return 0;
}
