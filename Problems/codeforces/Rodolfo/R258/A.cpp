#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define first f
#define second s

using namespace std;

typedef pair <int,int> PII;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string x;
	cin>>x;
	if(x.size()==1){ cout<<x<<'\n';}
	else{
		int which = ((int)x.size())/2;
		if(x.size()%2==0) which--;
		int contl = which;
		int contr = contl+1;
		for (int i=0;i<x.size();++i){
			if(i%2==0){
				cout<<x[contl];
				contl--;
			}else{
				cout<<x[contr];
				contr++;
			}
		}
		cout<<'\n';
	}
	return 0;
}
