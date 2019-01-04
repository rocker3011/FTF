#include <bits/stdc++.h>

using namespace std;

int path[7][100010];
bool memo[7][100010];
bool mark[7][100010];
int arr[100010];
int n;

bool DP(int ant, int idx){
    if (idx==n){
        return true;
    }

    bool &best = memo[ant][idx];

    if (mark[ant][idx]) return best;
    mark[ant][idx] = true;
    best = false;
    for (int i=1;i<=5;++i){
        if(arr[idx-1] > arr[idx]){
            if(i < ant){
                best = DP(i,idx+1);
                if(best){
                    path[ant][idx] = i;
                }
            }
        }
        if(best) return best;
        if(arr[idx-1] < arr[idx]){
            if(i > ant){
                best=DP(i,idx+1);
                if(best){
                    path[ant][idx]=i;
                }
            }
        }
        if(best)return best;
        if(arr[idx-1]==arr[idx]){
            if(i!=ant){
                best=DP(i,idx+1);
                if(best){
                    path[ant][idx]=i;
                }
            }
        }
        if(best) return best;
    }
    return best;
}

void print_path(int ant,int idx){
    if(idx==n) return;
    
    printf("%d ",path[ant][idx]);
    print_path(path[ant][idx],idx+1);
}

int main(){
    //FAST INPUT y OUTPUT
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin>>n;
    int cur = 0;
    for(int i=0;i<n;++i){
        cin>>arr[i];  
    }
    path[0][0]=-1;
    for(int i=1;i<=5;++i){
        if(DP(i,1)){
            path[0][0] = i;
            break;
        }
    }

    if (path[0][0]==-1){
        printf("-1\n");
    }else{
        print_path(0,0);
        printf("\n");
    }
    return 0;
}