#include <bits/stdc++.h>

using namespace std;

int arr[200010];
int freq[200010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;++i){
        scanf("%d",&arr[i]);
        freq[arr[i]]++;
    }


    return 0;
}