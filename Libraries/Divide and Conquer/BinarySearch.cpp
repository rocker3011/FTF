//Binary search on integer numbers

int bs(int lo, int hi){
    while (lo < hi){ 
        int mid = lo + (hi-lo+1)/2;

        if (f(mid) == true){ //if function is true or false we move the high , if we want to maximize we look for false, else we look for true
            hi = mid-1;
        }else{
            lo = mid;
        }
    }
    
    return lo;         // lo is the greatest x for which p(x) is false
}

//on Floating numbers

int bs_doubles(double lo, double hi){
    for (int i=0;i<log2(MAX_SPACE)+20;++i){
        double mid = lo + (hi-lo+1)/2;
        
        if (f(mid) == true){ //if function is true or false we move the high , if we want to maximize we look for false, else we look for true
            hi = mid-1;
        }else{
            lo = mid;
        }
    }
    return lo;
}