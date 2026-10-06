#include <assert.h>
#include <stdio.h>

int collatz(int n){
    int count, total = 0, max = n;
    
    for(int i = max; i > 1; i--){
        count = 1;
        n = i;
        // printf("%d\n", n);
        
        while(n != 1){
            if(n % 2 == 0){ // even
                n = n / 2;
            }
            else { // odd
                n = (3 * n) + 1;
            }
            // printf("%d\n", n);
            count++;
        }
        
        if(count > total)
            total = count;
        // printf("%d\n", count);
    }
    
    printf("%d\n", total);
    return total;
}

int main(void){
    // assert(collatz(13) == 10); // 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
    assert(collatz(999999) == 10);
    
    return 0;
}
