#include <bits/stdc++.h>

using namespace std;

int arr[111];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
    int cont=0;
    for (int i=2;i<n;++i){
        if(arr[i]==0 && arr[i-1]==1 && arr[i+1]==1){
            arr[i+1]=0;
            cont++;
        }
    }
    printf("%d\n",cont);
    return 0;
}