/* https://projecteuler.net/problem=24 */
#include <assert.h>
#include <stdlib.h>

int available[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int final[10] = {0};

int aux(int digits, int pos){
    int partial = 0;
    
    // calc factorial comb
    int fact = 1;
    for (int i = 2; i <= digits; i++)
        fact *= i;
    
    for(int i = 0; i <= digits; i++){
        // check for position
        if(partial + fact > pos){
            final[digits] = available[i]; // set available digits to final answer
            
            // shift available
            for(int j = i; j < digits; j++){
                available[j] = available[j+1];
            }
            
            return(pos - partial); // update pos for next fixed number
        }
        partial += fact;
    }
    
    return -1; // force error
}

long long lexicog(int pos){
    // Total is 10! = 3628800
    // fixing 0 as first, 9! = 362880. this logic goes on
    
    int digits = 10;
    pos--; // start at 0th
    while(digits > 1){ // find each position
        pos = aux(--digits, pos);
    }
    
    // construct final answer
    char answer[11] = {'\0'};
    for(int i = 9; i > 0; i--){
        answer[9 - i] = final[i] + '0';
    }
    answer[9] = available[0] + '0'; // last possible digit remaining
    
    // printf("%s\n", answer);
    return strtoll(answer, NULL, 10);
}

int main(void){
    assert(lexicog(1000000) == 2783915460);
    
    return 0;
}
