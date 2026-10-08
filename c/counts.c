#include <assert.h>
// #include <stdio.h>
#include <math.h>

int lattice(int max){
    int sum = 0;
    
    for(int i = max; i > 0; i--){
        switch(i) {
            case 1:
                sum += 3; // one
                break;
            case 2:
                sum += 3; // two
                break;
            case 3:
                sum += 5; // three
                break;
            case 4:
                sum += 4; // four
                break;
            case 5:
                sum += 4; // five
                break;
        }
    }
    
    return sum;
}

int main(void){
    assert(counts(5) == 19);
    // assert(lattice(20, 20) == 137846528820);
    
    return 0;
}
