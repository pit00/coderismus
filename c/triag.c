#include <assert.h>
// #include <stdio.h>
#include <math.h>

int triag(int div){
    int t = 1, n = 1, factors = 0;
    
    while(1){
        t = ((n * (n + 1)) / 2);
        n++;
        
        double st = sqrt(t);
        
        for(int i = (int)st; i > 0; i--){
            if (t % i == 0){
                factors++;
            }
        }
        factors *= 2; // divisor comes in pairs
        
        // perfect square
        if(st * st == (double)t){
            factors--;
        }
        
        // printf("%d\n", factors);
        if(factors > div){
            // printf("%d\n", factors);
            // printf("%d\n", t);
            break;
        }
        
        factors = 0;
    }
    
    return t;
}

int main(void){
    assert(triag(500) == 76576500);
    
    return 0;
}
