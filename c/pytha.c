#include <assert.h>
#include <math.h>
// #include <stdio.h>

/*
Given [A² + B² = C²] and [A + B + C = 1000]
From second, [C = 1000 - A - B]
Appling in first and reducing, result is [(1000 - A)(1000 - B) = 500000]
*/

int pytha(){
    // (1000 - A)(1000 - B) = 500000 -> X * Y = 500000, lets find the biggest factors (Y > X)
    
    int partial = 500000;
    int max = sqrt(partial);
    int A, B = 0, C, Y = 0, X;
    
    for(int i = max; i > 0; i--){
        if(partial % i == 0){
            Y = i;
            B = 1000 - Y;
            break;
            
        }
    }
    X = partial / Y;
    A = 1000 - X;
    C = 1000 - A - B;
    // printf("%d + %d + %d\n", A, B, C); // is 1000
    
    return (A * B * C);
}

int main(void){
    assert(pytha() == 31875000);
    
    return 0;
}
