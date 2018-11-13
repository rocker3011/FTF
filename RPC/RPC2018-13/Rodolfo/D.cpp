#include <bits/stdc++.h>

using namespace std;
long long p[2002];
long long Grundy[2002];

int calculateMex(unordered_set<long long> &Set) 
{ 
    long long Mex = 0; 
  
    while (Set.find(Mex) != Set.end()) 
        Mex++; 
    return (Mex); 
} 

long long calculateGrundy(int n)
{
	if (n == 0)
		return (0);
    if (n == 1){
        return 0;
    }
	
	if (Grundy[n] != -1)
		return (Grundy[n]);
	
	unordered_set<long long> Set; // A Hash Table
	
	for (int k=1; k<n; k++){
        long long x = n/k; //piles created of size K
        long long y = n%k; //piles created from remainder of size K
        //At this point x and y form a set of piles that we will call A
        //A is a NIM game, therefore the xor sum will give us the grundy number of the set A 
        //The set A then has a winnable state of his own that is added to calculate the Mex
        long long xsum = 0;
        if(x%2!=0) xsum^=calculateGrundy(k); //if x%2==0 then we have a case like this: {2,2,2,2} xor cancels and gives result as 0
        //if x%2!=0 then it is a case like this: {2,2,2} = 2 , instead of calculating each pile we just cancel them out right away
        xsum^=calculateGrundy(y); //now we calculate the xor sum with the remainder
        Set.insert(xsum); //we insert the elements to calculate the Mex of the current n and get his grundy_number
    }

    //Why k and not n/k? very simple, k is the size of the piles (what we need for the grundy number) , while n/k is just the number of piles of size k
    //Why n%k? because this represent the size of a leftover pile!!!
	
	// Store the result
	Grundy[n] = calculateMex (Set);
	
	return(Grundy[n]);
}

int main(){
    int n;
    scanf("%d",&n);
    Grundy[1] = 0LL;
    Grundy[0] = 0LL;
    for (int i=2;i<=2000;i++){
        Grundy[i]=-1;
    }
    for(int i=0;i<n;++i){
        cin>>p[i];
        calculateGrundy(p[i]);

    }
    long long xsum = 0LL;
    for(int i=0;i<n;++i){
        xsum = xsum ^ Grundy[p[i]]; //Xor sum of impartial games always gives the winner if no mistakes are made
        //cout<<Grundy[p[i]]<<endl;
    }

    if(xsum==0){
        puts("Second");
    }else{
        puts("First");
    }


    return 0;
}