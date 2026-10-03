#include <assert.h>
#include <stdio.h>

int triag(int pos){
    int p = 1, count = 2, i = 0;
    int primes[pos + 1];
    primes[0] = 2; // first prime
    primes[1] = 3; // second prime
    int t = 2;
    while(1){
        p = p + t;
        printf("%d\n", p);
        while(primes[i] * primes[i] <= p){ // stay here to test if prime [+], or break [-]
            if (p % primes[i] == 0){ // not prime: negative
                p *= -1;
                break;
            }
            i++;
            // prime: positive
        }
        i = 0; // reset
        
        if(p > 0){
            primes[count] = p;
            count++;
            
            // Found
            if (count == pos){
                // printf("%d\n", p);
                break;
            }
        } else {
            p *= -1;
        }
        
        p++;
    }
    
    return p;
}

int main(void){
    assert(triag(500) == 5);
    
    return 0;
}
