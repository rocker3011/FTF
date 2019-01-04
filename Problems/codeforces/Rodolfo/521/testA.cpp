#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cnt=0;
    vector<int>v;
    scanf("%d",&n);
    int x[n];
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<n-1;i++)
    {
        if(x[i]==0&&x[i-1]==1&&x[i+1]==1)
            v.push_back(i);
    }
    int c=v.size();
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[i-1]<3)
        {
            v.erase(v.begin()+i);
            cnt++;
        }

    }
    cout<<c-cnt;
    return 0;
}