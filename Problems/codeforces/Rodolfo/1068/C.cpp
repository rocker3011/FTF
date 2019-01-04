#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        double b1,b2,d;
        cin >> d;
        b1 = (-d + sqrt(d*d - ((-4)*(-d))))/(-2);
        b2 = (-d - sqrt(d*d - ((-4)*(-d))))/(-2);
        double a1,a2;
        a1 = d - b1;
        a2 = d - b2;
        if(d==0){
            puts("Y 0.000000000 0.000000000");
            continue;
        }
        cout<<fixed;
        if (a1>-1e9 && b1>-1e9 && fabs((a1+b1)-(a1*b1)) <= 1e6 && fabs((a1+b1)-d)<= 1e6){
            cout<<"Y ";
            cout<<setprecision(9)<<a1;
            cout<<" ";
            cout<<setprecision(9)<<b1;
            cout<<'\n'; 
            
        }else if(a2>-1e9 && b2>-1e9 && fabs((a2+b2)-(a2*b2)) <= 1e6 && fabs((a2+b2)-d)<= 1e6){
            cout<<"Y ";
            cout<<setprecision(9)<<a2;
            cout<<" ";
            cout<<setprecision(9)<<b2;
            cout<<'\n'; 
        }else{
            puts("N");
        }
    }
    return 0;
}