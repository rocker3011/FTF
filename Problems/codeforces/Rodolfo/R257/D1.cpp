#include <bits/stdc++.h>

using namespace std;
int p[200010];
int main(){
 ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 int n;
 cin>>n;
 stack <int> st;
 for (int i=0;i<n;++i){
   cin>>p[i];
   p[i]%=2;
 }
 bool posible=false;
 for (int i=0;i<n;++i){
 	if(!st.empty() && p[i]==st.top()){
 		st.pop();
 	}else{
 		st.push(p[i]);
 	}
 }
 
 if(st.size()<=1){
   puts("YES");
  }else{
   puts("NO");
  }

 

 return 0;
}