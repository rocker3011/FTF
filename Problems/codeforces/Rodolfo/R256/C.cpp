#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007LL

int main(){

	string x;
	cin>>x;
	int n = x.size();
	string cl;
	for (int i=0;i<n;++i){
		if(x[i]!='a' && x[i]!='b') continue;
		cl.push_back(x[i]);
	}

	long long sum= 0LL;
	long long mul= 1LL;
	long long c_a=0LL;
	int m = cl.size();
	for (int i=0;i<m;++i){
		if (cl[i]=='b'){
			
			if(sum>0LL){
				mul= (mul%MOD * (sum+1)%MOD)%MOD;
			}
			sum=0LL;
		}else{
			sum++;
			c_a++;
		}
	}

	if (sum>0LL){
		mul = (mul%MOD * (sum+1)%MOD)%MOD;
	}

	cout<< mul-1 <<'\n';

	return 0;
}