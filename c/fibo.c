#include <assert.h>

int fibo(int max){
    int f1 = 1, f2 = 2, f3, sum = 2;
    
    for(int i = 1; i < 50; i++){
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        
        if (f3 % 2 == 0){
            sum += f3;
        }
        
        if (f3 > max){
            break;
        }
    }
    return sum;
}

int main(void){
    assert(fibo(4000000) == 4613732);
    
    return 0;
}
