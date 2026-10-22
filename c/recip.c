/* https://projecteuler.net/problem=26 */
#include <assert.h>
// #include <stdio.h>

int recip(int max) {
    int final = 0;
    for(int i = 2; i <= max; i++){
        int remainder = 1;
        int denominator = i;
        int count = 0;
        int repeat[1000] = {0};
        // printf("%d\n", denominator);
        
        /*
        instead of 1/d, use 10%d
        
        loop with d = 10 % d: if result 0, break | if result repeats, its a cycle
        
        made a slop solution [can be wrong at lower numbers], just see if repeats and keep counting
        */
        while(remainder != 0){
            // int digit = (remainder * 10) / denominator;
            // printf("%d / %d = %d", remainder * 10, denominator, digit);
            remainder = (remainder * 10) % denominator;
            // printf(" | Rest: %d\n", remainder);
            
            count++;
            if (repeat[remainder] == 1){ // repeated
                break;
            }
            repeat[remainder] = 1; // first time
        }
        
        if(count > final)
            final = count;
    }
    
    // printf("%d\n", final);
    return final;
}

int main(void){
    assert(recip(1000) == 983);
    
    return 0;
}
