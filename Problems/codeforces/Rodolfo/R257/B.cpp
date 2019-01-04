#include <bits/stdc++.h>

using namespace std;
int p[200];
bool mark[200];
int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n; 
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>p[i];
	}
	sort(p,p+n);
	int sum=0;
	for (int i=0;i<n;++i){
		int minimo=0x3f3f3f3f;
		int ele=-1;
		if(mark[i]) continue;
		mark[i]=true;
		for (int j=0;j<n;++j){
			if(mark[j]) continue;
			int diff = abs(p[i]-p[j]);
			if(diff<minimo){
				minimo=diff;
				ele=j;
			}
		}
		mark[ele]=true;
		sum+=minimo;
	}

	cout<<sum<<'\n';

	return 0;
}
