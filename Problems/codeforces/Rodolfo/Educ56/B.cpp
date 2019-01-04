#include <bits/stdc++.h>

using namespace std;

int arr[28];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(arr,0,sizeof(arr));
		string x;
		cin>>x;
		int cant=0;
		for(int i=0;i<x.size();++i){
			if(arr[x[i]-'a']==0)
				cant++;
			arr[x[i]-'a']++;
		}
		
		if(cant==1){
			printf("-1\n");
		}else{
			for (char i=0;i<=26;i++){
				for(int j=0;j<arr[i];++j){
					cout<<(char)(i+'a');
				}
			}
			printf("\n");

		}
	}
	return 0;
}