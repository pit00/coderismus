#include <assert.h>
#include <math.h>
#include <stdio.h>

bool pali_test(int value, int size){
    char pali[size];
    sprintf(pali, "%d", value);
    
    int f = size - 1;
    for(int i = 0; i < size; i++){
        while(pali[f] == '\0')
            f--;
        
        if(pali[i] != pali[f])
            return false;
        
        f--;
        
        if(i == f)
            break;
    }
    return true;
}

int pali(int size){
    int n1, n2, min1, min2, p, max = 0;
    
    n1 = n2 = pow(10, size) - 1; // autocast
    min1 = min2 = pow(10, size - 1);
    // min1 = min2 = 900; // improve by batches?
    
    while(n1 >= min1){
        while(n2 >= min2){
            p = n1 * n2;
            if(pali_test(p, (size * 2) + 1)){
                // printf("%d * %d = %d\n", n1, n2 , p);
                if(p > max)
                    max = p;
                min2 = n2; // n2 < n1, so this is the min of biggest product
            }
            n2--;
        }
        n1--;
        n2 = n1;
    }
    
    return max;
}

int main(void){
    assert(pali(3) == 906609);
    
    return 0;
}
