    //Problem D: Database of Clients
    //Type: Ad-hoc
    //Easy problem, clean string before @ and insert it on a set, print set's length
    #include <bits/stdc++.h>

    using namespace std;

    set <string> s;

    int main(){

        string a;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            cin>>a;
            string b="";
            bool plus = false;
            bool arroba = false;
            for(int j=0;j<a.size();++j){
                if(a[j]=='+'){
                    plus=true;
                }
                if(a[j]=='@'){
                    arroba=true;
                }
                if(plus && !arroba) continue;
                if(a[j]=='.' && !arroba) continue;
                b.push_back(a[j]);
            }
            s.insert(b);
        }

        printf("%d\n",(int)s.size());

        return 0;
    }