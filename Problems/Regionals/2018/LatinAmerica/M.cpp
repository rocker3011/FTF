//Problem M: Mount Marathon
//Type: Ad-hoc
//Easy problem 

#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> v;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    int cont=1;
    for(int i=1;i<n;++i){
        if(v[i-1]<v[i]){
            cont++;
        }
    }
    printf("%d\n",cont);
    return 0;
}