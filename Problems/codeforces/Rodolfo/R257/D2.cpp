#include <bits/stdc++.h>

using namespace std;
int p[200010];
int main(){
	 //ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	 int n;
	 cin>>n;
	 for (int i=0;i<n;++i){
	   cin>>p[i];
	 }
	 int maximo = *max_element(p,p+n);
	 stack <int> st;

	 for (int i=0;i<n;++i){
	 	if(st.empty()){
	 		st.push(p[i]);
	 	}else{
	 		if(st.top() == p[i]){
	 			st.pop();
	 		}else if(st.top()<p[i]){
	 			st.push(1); st.push(1);
	 			break;
	 		}else{
	 			st.push(p[i]);
	 		}
	 	}
	 }
	 if(st.empty()){
	 	printf("YES\n");
	 }else if(st.size()<=1){
	 	if(st.top()==maximo)
	 		printf("YES\n");
	 	else
	 		printf("NO\n");
	 }else{
	 	printf("NO\n");
	 }
 

 return 0;
}