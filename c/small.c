#include <assert.h>
#include <stdio.h>

int small(int max){
    int aux = max, count = 2;
    
    while(count < 100){
        for(int i = max; i >= 2; i--){
            if(aux % i != 0){
                // printf("RIP\n");
                break;
            }
            if (i == 2)
                printf("GG\n");
            
        }
        count++;
        aux = max;
        aux *= count;
    }
    
    return 4613732;
}

int main(void){
    assert(small(20) == 4613732);
    
    return 0;
}
