// https://projecteuler.net/problem=30
#include <assert.h>
#include <stdio.h>
#include <math.h>

int powers(int digits){
    printf("\nPow: %d\n", digits);
    int final = 0, min = 10;
    int n = 2;
    
    while(n * pow(9, digits) >= pow(10, n - 1)){
        // printf("biggest: %d\n", (int)(pow(10, n) - 1));
        // printf("sum: %d\n", (int)(n * pow(9, digits)));
        n++;
    }
    int max = (n - 1) * pow(9, digits);
    
    for(int i = min; i <= max; i++){
        int aux = i;
        int sum = 0;
        
        while (aux > 0) {
            int digit = aux % 10; // get last integer digit
            sum += pow(digit, digits); // (int)
            aux /= 10; // remove last integer digit
        }
        
        if(sum == i){
            printf("%d\n", i);
            final += sum;
        }
    }
    printf("Total: %d\n", final);
    return final;
}

int main(void){
    assert(powers(3) == 1301); // (153 370 371 407)
    assert(powers(4) == 19316); // (1634 8208 9474)
    assert(powers(5) == 443839); // (4150 4151 54748 92727 93084 194979)
    assert(powers(6) == 548834); // (548834)
    
    return 0;
}
