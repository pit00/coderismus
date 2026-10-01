#include <assert.h>
#include <math.h>

int square(int numb){
    int ssum = 0, ssquare = 0;
    
    for(int i = 1; i <= numb; i++){
        ssum += i;
        ssquare += (i * i);
    }
    ssum *= ssum;
    
    return (ssum - ssquare);
}

int main(void){
    assert(square(10) == 2640);
    assert(square(100) == 25164150);
    
    return 0;
}
