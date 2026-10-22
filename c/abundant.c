/* https://projecteuler.net/problem=23 */
#include <assert.h>
#include <math.h>
// #include <stdio.h>

int abundant(void){
    int sum = 1; // included
    int total = 0; // included
    int array[28123];
    int numbers[28124] = {0};
    int pos = 0;
    
    for(int i = 12; i <= 28123; i++){
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
        
        if(sum > i){ // abundant | == is perfect | < is deficient
            array[pos] = i;
            // printf("%d [%d]\n", sum, i);
            pos++;
        }
        
        sum = 1;
    }
    
    for(int i = 0; i < pos; i++){
        for(int j = 0; j < pos; j++){
            sum = array[i] + array[j];
            if (sum >= 28123)
                break;
            numbers[sum] = -1; // printf("%d [%d]\n", array[i], i);
        }
    }
    
    for(int i = 0; i < 28123; i++){
        if (numbers[i] != -1)
            total += i;
    }
    
    // printf("%d\n", total);
    return total;
}

int main(void){
    assert(abundant() == 4179871);
    return 0;
}
