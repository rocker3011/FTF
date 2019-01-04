//Problem C: Cheap Trips
//Type: DP
//We try from minute 0 to minute 120 to see which time is more suitable to start
//We dont try from more than 120 because it is cyclic , if you start from 121 it is the same result if you started from 1
//As you can wait between trips, you must do a recursive backtracking, this can be amortized using DP

#include <bits/stdc++.h>

using namespace std;

float memo[122][10010];
bool mark[122][10010];
pair <int,float> v[10010];
int n;

float DP(int i,int x,int cont){
    if(x==n) return 0.0;
    
    float &best = memo[i][x];
    
    if(mark[i][x]) return best;
    mark[i][x]=true;
    float cost = 0.0;
    best = 0x3f3f3f3f;
    if (cont==0 || cont>=6){
        cost+=v[x].second;
        cont++;
    }else if(cont==1){
        cost+=(v[x].second*0.5);
        cont++;
    }else if(cont>=2 && cont<=5){
        cost+=(v[x].second*0.25);
        cont++;
    }
    int travel = i+v[x].first;

    for(int j=0;j<120;++j){
        if (travel+j>=120){
            travel=(travel+j)%120;
            cont=0;
        }
        best = min(best,DP(travel,x+1,cont)+cost);
    }
    return best;
}

int main(){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            int x; float y;
            scanf("%d %f",&x,&y);
            v[i]={x,y};
        }
        float minimo = 0x3f3f3f3f;
        for (int i=0;i<120;++i){
            minimo = min(minimo,DP(i,0,0));
        }
        printf("%.2f\n",minimo);

    return 0;
}