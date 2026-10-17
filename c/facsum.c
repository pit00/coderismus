/* https://projecteuler.net/problem=20 */
#include <assert.h>
// #include <stdio.h>

int facsum(int num){
    int array[1000] = {1};
    int size = 1;
    
    // storage is in reverse order - so carry is correct
    for(int i = num; i > 1; i--){ // num! until 2
        int carry = 0;
        
        for(int j = 0; j < size; j++){
            int value = array[j] * i + carry;
            
            array[j] = value % 10;
            carry = value / 10;
        }
        
        while(carry > 0){
            array[size] = carry % 10;
            carry /= 10;
            size++;
        }
        
        /* print in corret order
        for(int k = size - 1; k >= 0; k--){
            printf("%d", array[k]);
        }
        printf("\n");
        */
    }
    
    int sum = 0;
    
    for (int i = 0; i < size; i++)
        sum += array[i];
    
    // printf("%d\n", sum);
    return sum;
}

int main(void){
    assert(facsum(10) == 27);
    assert(facsum(100) == 648);
    
    return 0;
}
