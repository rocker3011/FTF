#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    scanf("%d",&x);
    vector <int> months;
    for (int i=0;i<12;++i){
        int y; scanf("%d",&y);
        months.push_back(y);
    }

    int minimo=0x3f3f3f3f;
    for (int i=0;i<(1<<12);++i){
        int tam=0;
        int cont=0;
        for (int j=0;j<12;++j){
            if (i & (1<<j)){
                
                tam+=months[j];
                cont++;
            }
        }
        if(tam>=x){
            minimo=min(minimo,cont);
        }
    }
    
    if(minimo == 0x3f3f3f3f){
        puts("-1");
    }else{
        printf("%d\n",minimo);
    }
}