#include <assert.h>
// #include <stdio.h>

int small(){
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19}; // calc otherwhere
    int min = 9699690; // min prime prod = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19
    int aux, pri;
    
    for(int i = 2; i <= 20; i++){
        // number not div
        if(min % i != 0){
            aux = 0;
            while(1){
                pri = primes[aux];
                
                // find min prime of the number
                if(i % pri == 0){
                    min *= pri; // mult prime prod
                    break;
                }
                aux++;
            }
        }
    }
    
    return min;
}

int main(void){
    assert(small() == 232792560);
    
    return 0;
}
