#include <bits/stdc++.h>

using namespace std;

int m[4][4];

int main(){
    string a[4];
    int cont=0;
    for (int i=0;i<3;++i){
        cin>>a[i];
        for (int j=0;j<3;++j){
            cont+= (a[i][j]=='o') ? 1 : 0;
            m[i][j] = (a[i][j]=='o') ? 1 : 0;
        }
    }

    if (cont <=0 || cont>=7){
        puts("unknown");
    }else{
        if(cont==1){
            if(m[1][1])
                puts("1");
            else
                puts("unknown");
        }else if(cont==2){
            if( (m[0][0] && m[2][2]) || (m[0][2] && m[2][0])){
                puts("2");
            }else{
                puts("unknown");
            }
        }else if(cont==3){
            if( (m[0][0] && m[2][2] && m[1][1]) || (m[0][2] && m[2][0] && m[1][1])){
                puts("3");
            }else{
                puts("unknown");
            }
        }else if(cont==4){
            if( (m[0][0] && m[2][2]) && (m[0][2] && m[2][0])){
                puts("4");
            }else{
                puts("unknown");
            }
        }else if(cont==5){
            if( (m[0][0] && m[2][2]) && m[1][1] && (m[0][2] && m[2][0])){
                puts("5");
            }else{
                puts("unknown");
            }
        }else if (cont==6){
            if( (m[0][0] && m[0][1] && m[0][2] && m[2][0] && m[2][1] && m[2][2]) || (m[0][0] && m[1][0] && m[2][0] && m[0][2] && m[1][2] && m[2][2]) ){
                puts("6");
            }else{
                puts("unknown");
            }
        }
    }

    

    return 0;
}