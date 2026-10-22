/* https://projecteuler.net/problem=25 */
#include <assert.h>

int kfibo(void) {
    int f1[1000] = {0};
    int f2[1000] = {0};
    int f3[1000] = {0};
    
    f1[0] = 1; // F(1)
    f2[0] = 1; // F(2)
    int index = 2;
    int size = 1;
    
    // storage is in reverse order - so carry is correct
    while (size < 1000) {
        int carry = 0;
        
        for (int j = 0; j < size; j++) {
            int value = f1[j] + f2[j] + carry;
            
            f3[j] = value % 10;
            carry = value / 10;
        }
        
        while (carry > 0) {
            f3[size] = carry % 10;
            carry /= 10;
            size++;
        }
        
        index++;
        
        if (size >= 1000)
            return index;
        
        // correct fibo seq
        for (int j = 0; j < 1000; j++) {
            f1[j] = f2[j];
            f2[j] = f3[j];
            f3[j] = 0;
        }
    }
    
    return index;
}

int main(void){
    assert(kfibo() == 4782);
    
    return 0;
}
