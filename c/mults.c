#include <assert.h>

int mults(int max){
    int sum = 0;
    for(int i = 1; i < max; i++){
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    
    return sum;
}

int main(void){
    assert(mults(1000) == 233168);
    
    return 0;
}
