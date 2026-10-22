/* https://projecteuler.net/problem=24 */
#include <assert.h>
#include <math.h>
#include <stdio.h>

int aux(int digits, int pos){
    int partial = 0;
    int fact = 1;
    printf("Digits %d\n", digits);
    for (int i = 2; i <= digits; i++)
        fact *= i;
    
    for(int i = 0; i <= digits; i++){
        if(partial + fact > pos){
            printf("partial %d\n", partial);
            printf("i %d\n", i);
            printf("pos %d\n", pos);
            return (pos - partial);
        }
        partial += fact;
    }
    // printf("%d\n", partial);
    return 0;
}

long long lexicog(int pos){
    // [0123456789]
    // Total is 10! = 3628800
    // if 0 is first, 9! = 362880. same for others
    // int total = 0;
    int digits = 10;
    
    while(digits > 1){
        pos = aux(--digits, pos);
    }
    
    printf("\n");
    return 0;
}

int main(void){
    assert(lexicog(1000000) == 2783915460);
    return 0;
}
