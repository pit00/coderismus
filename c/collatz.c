#include <assert.h>
// #include <stdio.h>

#define LIMIT 1000000

long long length[LIMIT] = {0};

long long collatz_r(long long n){
    if (n < LIMIT && length[n] != 0){ // already calc chain size | recursion exit (at first, when length[1] == 1)
        return length[n];
    }
    
    long long next;
    
    if(n % 2 == 0){
        next = n / 2;
    } else {
        next = 3 * n + 1;
    }
    
    // printf("%lld - %lld\n", n, next);
    long long result = 1 + collatz_r(next); // increment/sum chain size
    
    if (n < LIMIT){
        length[n] = result; // save chain size (above limit will be ignored, bit performance loss)
        // printf("%lld - %lld\n", n, result);
    }
    
    return result;
}

int collatz(int n){
    length[1] = 1;
    
    long long longest = 0;
    int answer = 0;
    
    for(int i = 2; i <= n; i++){
        long long len = collatz_r(i);
        // printf("%d\n", i);
        
        if (len > longest){
            longest = len;
            answer = i;
        }
    }
    
    // printf("%lld\n", longest);
    // printf("%d\n", answer);
    return answer;
}

int main(void){
    // assert(collatz(13) == 10);
    assert(collatz(LIMIT - 1) == 837799);
    
    return 0;
}
