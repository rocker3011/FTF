//Criba de Eratostenes O(N)
#define MAXN 1000050
int p[MAXN];

void criba(){
    memset(p,0,sizeof(p));
    for (int i=4;i<MAXN;i+=2) p[i] = 2;
    
    for (int i=3;i*i<MAXN;i+=2){
        if (!p[i]){ 
            for (int j=i*i; j<MAXN; j+=2*i){ 
                p[j]=i;
            }
        }
    }   
}

//Factorizacion usando la criba de eratostenes (factores primos, divisores) O(log(n))

int fact(int x, vector <int> &f){
    int F =0;
    while (p[x]){
        f.push_back(p[x]);
        F++;
        x/=p[x];
    }
    f.push_back(x); //en f se guardan los factores primos
    F++; // en F se guarda el numero de factores primos
    return F; //Esto no incluye el 1 
}