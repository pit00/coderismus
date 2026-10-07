#include <assert.h>
// #include <stdio.h>
#include <math.h>

long long comb(int n, int k){
    // c = n! / (k! * (n - k)!)
    int d = n - k;
    long double prod = 1;
    
    // as n > k, i can cut k! from n'
    for(int i = n; i > k ; i--){ // prod of n, until n' = k
        if(d > 1){
            prod *= (long double)i / d; // n!/d!
        } else{
            prod *= i; // as d < k, some div cant happen
        }
        d--;
    }
    // if(k > d){
    // } else { // or using d, if is bigger. ignored because of squared entries
    // }
    
    // printf("%Lf\n", prod);
    
    return (long long)roundl(prod);
}

/*
long long fac(int numb){
    long long prod = 1;
    for(int i = numb; i > 0; i--){
        prod *= i;
    }
    
    return prod;
}
*/

long long lattice(int rows, int cols){
    // Combination formula:
    // right mov: rows
    // down mov: cols
    // total mov: rows + cols
    
    // pick right movs from total
    int n = rows + cols; // total
    int k = rows; // right
    // also can pick down, result are the same in this problem, but entries are square, so ignore
    
    long long path = comb(n, k);
    
    // printf("%lld\n", path);
    return path;
}

int main(void){
    assert(lattice(2, 2) == 6);
    assert(lattice(20, 20) == 137846528820);
    
    return 0;
}
