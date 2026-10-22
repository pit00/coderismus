/* https://projecteuler.net/problem=21 */
#include <assert.h>
#include <math.h>
// #include <stdio.h>

int amicable(int max){
    int sum = 1; // including div 1
    int array[max + 1];
    int total = 0;
    array[0] = 0; // ignorning 0
    array[1] = 1;
    
    for(int i = 2; i <= max; i++){
        double st = sqrt(i);
        
        for(int j = (int)st; j > 1; j--){ // ignoring 1 (and the pair, number itself)
            if (i % j == 0){
                sum += j;
                sum += (i / j); // divisor pairs
            }
        }
        
        // perfect square - remove mirrored pair part
        if((int)st * (int)st == i){
            sum -= st;
        }
        
        array[i] = sum;
        // printf("[%d] = %d\n", i, array[i]);
        
        // find amicable pair (i - 1 to not count itself)
        for(int j = i - 1; j > 0; j--){
            if(j == sum && array[j] == i){
                // printf("%d ↔ %d\n", j, i);
                total += i + j;
            }
        }
        sum = 1;
    }
    
    // printf("%d\n\n", total);
    return total;
}

int main(void){
    assert(amicable(300) == 504);
    assert(amicable(10000) == 31626);
    
    return 0;
}
