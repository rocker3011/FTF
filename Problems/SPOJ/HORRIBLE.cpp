//PROBLEM HORRIBLE, Horrible Queries
//Type Segment Tree + Lazy Propagation
//Excelent problem to understand how lazy propagation works on segment trees, solve the problem without lazy updates
//and then solve it with them to see how segment trees work.

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 300100

long long st[MAX_N];
long long lazy[MAX_N];

void lazy_update(int node, int i, int j, int li, int ls){
    st[node]+=(long long)(j-i+1)*lazy[node];
    if(i!=j){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0LL;
}

void update(int node, int i,int j, int li, int ls, long long v){
    if(lazy[node]) lazy_update(node,i,j,li,ls);
    if(i>ls || j<li) return;
    if(i>=li && j<=ls){
        st[node]+=(long long) (j-i+1)*v;
        if(i!=j){ //without lazy, it is i==j st[node]+=v
            lazy[node*2]+=v;
            lazy[node*2+1]+=v;
        }
        return;
    }
    int mid = (i+j)/2;
    update(2*node,i,mid,li,ls,v);
    update(2*node+1,mid+1,j,li,ls,v);
    st[node]= st[node*2] + st[node*2+1];
}

long long query(int node, int i, int j, int li, int ls){
    if(lazy[node]) lazy_update(node,i,j,li,ls);
    if(i>ls || j<li) return 0LL;
    if(i>=li && j<=ls){
        return st[node];
    }
    int mid = (i+j)/2;
    long long l = query(2*node,i,mid,li,ls);
    long long r = query(2*node+1,mid+1,j,li,ls);
    return l+r;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(st,0LL,sizeof(st));
        memset(lazy,0LL,sizeof(lazy));
        int n,c;
        scanf("%d %d",&n,&c);
        for(int i=0;i<c;++i){
            int q,li,ls;
            long long v;
            scanf("%d %d %d",&q,&li,&ls);
            if(q==0){
                scanf("%lld",&v);
                update(1,0,n-1,li-1,ls-1,v);
            }else{
                printf("%lld\n",query(1,0,n-1,li-1,ls-1));
            }
        }
    }
    return 0;
}