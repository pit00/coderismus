#include <assert.h>
// #include <stdio.h>

long long sprime(int max){
    int p = 4, count = 2, i = 0;
    int primes[max];
    primes[0] = 2; // first prime
    primes[1] = 3; // second prime
    long long sum = 5;
    
    while(1){
        while(primes[i] * primes[i] <= p){ // stay here to test if prime [+], or break [-] | long long warever
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
            // printf("%d\n", p);
            count++;
            
            // Limit
            if(p > max){
                // printf("%lld\n", sum);
                break;
            }
            sum += p;
        } else {
            p *= -1;
        }
        
        p++;
    }
    
    return sum;
}

int main(void){
    assert(sprime(2000000) == 142913828922);
    
    return 0;
}
