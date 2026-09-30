#include <assert.h>
// #include <stdio.h>

int prime(long long numb){
    int p = 2, aux = 2, last;
    
    while(1){
        // printf("%d\n", aux);
        while (p / aux != 1){
            if (p % aux == 0){
                // printf("%d\n", p);
                p *= -1;
                break;
            }
            aux++;
        }
        if(p > 0){
            // printf("Prime %d\n", p);
            if (numb % p == 0){
                // printf("DIV - %d\n", p);
                numb /= p;
                last = p;
                if(numb == 1){
                    break;
                }
            }
        } else {
            p *= -1;
        }
        
        p++;
    }
    
    return last;
}

int main(void){
    assert(prime(600851475143) == 6857);
    
    return 0;
}
