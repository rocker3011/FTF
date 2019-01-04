#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n,x,k;
	cin>>n>>k;
	long long minimo = LLONG_MAX;

	for (long long i=1LL;i<k;++i){
		if(n%i==0){
			long long res = n/i * k + i; 
			minimo = min(minimo,res);
		}
		
	}

	cout<<minimo<<'\n';

	return 0;
}
