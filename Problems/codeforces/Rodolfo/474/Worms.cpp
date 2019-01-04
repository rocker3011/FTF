// Worms , given n piles of elements each indexed from 1 to n[i] and then n[i]+1 to n[i+1] and so on, determine
// Which pile has a given index

//Solution to think : DP + Binary_Search , accumulate all the piles into a "sum" array and proceed to do a controlled binary_search
// "controlled" means it behaves like upper_bound but there are special cases that can only be checked on a manual search.


#include <bits/stdc++.h>

using namespace std;

int sum[100010];
int ele[100010];


int bs(int lo, int hi,int idx){
    while (lo < hi){ 
        int mid = lo + (hi-lo+1)/2;

        if (sum[mid] > idx){ //if function is true or false we move the high , if we want to maximize we look for false, else we look for true
            hi = mid-1;
        }else{
            lo = mid;
        }
    }
    if (idx > sum[lo]){
        return lo+1;
    }else{
        return lo;         // lo is the greatest x for which p(x) is false
    }
}

int main(){

    int n,q;
    memset(sum,0,sizeof(sum));
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",ele+i);
        sum[i] = sum[i]+sum[i-1]+ele[i];
    }
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        int idx;
        scanf("%d",&idx);
        printf("%d\n",bs(1,n,idx));
    }

    return 0;
}
