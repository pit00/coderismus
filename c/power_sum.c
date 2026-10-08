#include <assert.h>
// #include <stdio.h>

int power(int num){
    int array[1000] = {1};
    int size = 1;
    
    // storage is in reverse order - so carry is correct
    for(int i = 0; i < num; i++){
        int carry = 0;
        
        for(int j = 0; j < size; j++){
            int value = array[j] * 2 + carry;
            
            array[j] = value % 10;
            carry = value / 10;
        }
        
        while(carry > 0){
            array[size] = carry % 10;
            carry /= 10;
            size++;
        }
    }
    
    int sum = 0;
    
    for (int i = 0; i < size; i++)
        sum += array[i];
    
    // printf("%d\n", sum);
    
    return sum;
}

int main(void){
    assert(power(15) == 26);
    assert(power(1000) == 1366);
    
    return 0;
}
