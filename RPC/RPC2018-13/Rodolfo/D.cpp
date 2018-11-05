#include <bits/stdc++.h>

using namespace std;
int p[2002];
int main(){
    int n;
    scanf("%d",&n);
    int cont=0;
    for(int i=0;i<n;++i){
        scanf("%d",&p[i]);
        cont+=p[i];
    }
    if (n%2==0)
        printf("%s\n",(cont%2!=0) ? "First" : "Second");
    else
        printf("%s\n",(cont%2!=0) ? "Second" : "First");

    return 0;
}