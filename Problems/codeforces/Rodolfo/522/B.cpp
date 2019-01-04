#include <bits/stdc++.h>

using namespace std;

char matrix[110][110];
int n,m;
string a;
int tam;



bool check(int r){

    for(int c=1;c<=20;++c){
        int cont=0;
        int diff = tam-(c*r);
        if (diff>0) continue;
        diff = abs(diff);
        int colocar = diff%c;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(colocar+j==c && diff){
                    matrix[i][j]='*';
                    diff--;
                }else
                    matrix[i][j]=a[cont++];
            }
        }
        if(diff>0) return false;

        printf("%d %d\n",r,c);
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j)
                cout<<matrix[i][j];
            cout<<'\n';
        }
        return true;
    }

    return false;
}

int main(){
    //FAST INPUT y OUTPUT
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>a;
    tam = (int)a.size();
    for(int i=0;i<100;++i){
        for(int j=0;j<100;++j){
            matrix[i][j]='-';
        }
    }
    for (int i=1;i<=5;++i){
        if(check(i)){
            break;
        }
    }

    return 0;
}