#include <assert.h>

int prime(int pos){
    int p = 4, count = 2, i = 0;
    int primes[pos + 1];
    primes[0] = 2; // first prime
    primes[1] = 3; // second prime
    
    while(1){
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
    assert(prime(10001) == 104743);
    
    return 0;
}
