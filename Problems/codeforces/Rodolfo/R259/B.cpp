#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define first f
#define second s
#define pb push_back

using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int n; cin>>n;
	vector <int> v;
	int maximo = 0;
	int minimo = 0x3f3f3f3f;
	int maximo2 = 0;
	int minimo2 = 0x3f3f3f3f;
	for(int i=0;i<n;++i){
		int x; cin>>x;
		if(x>=maximo){
			maximo2=maximo;
			maximo=x;
		}else if(x>=maximo2){
			maximo2=x;
		}
		if(x<=minimo){
			minimo2=minimo;
			minimo=x;
		}else if(x<=minimo2){
			minimo2=x;
		}
	}

	cout<<min(abs(maximo-minimo2),abs(maximo2-minimo))<<'\n';


	return 0;
}
