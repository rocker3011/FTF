#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007LL

int main(){

	int t;
	cin>>t;
	while(t--){
		int x; scanf("%d",&x);
		int sum=0;
		int dice=7;
		int tries=0;
		while(sum!=x){
			while(sum+dice>x){
				dice--;
			}
			sum+=dice;
			tries++;
		}
		printf("%d\n",tries);
	}

	return 0;
}