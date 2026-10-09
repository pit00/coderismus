#include <assert.h>
// #include <stdio.h>

int pathi_eg(void){
    int size = 4;
    
    int trig[4][4] = { // cant use [size] in this declaration style
        {3},
        {7, 4},
        {2, 4, 6},
        {8, 5, 9, 3}
    };
    
    int prev, next; // for sum
    int aux = size - 2; // similar to i in for
    // bottom to top, sum best choises, ultil 0x0 is to total
    for(int i = (size - 2); i >= 0; i--){ // -1 for index and -1 to starting point (before last row)
        for(int j = 0; j <= aux; j++){
            // printf("[%d][%d]\n", i, j);
            prev = trig[i][j] + trig[i + 1][j];
            next = trig[i][j] + trig[i + 1][j + 1];
            trig[i][j] = prev > next ? prev : next;
        }
        aux--;
    }
    
    return trig[0][0];
}

int pathi(void){
    int size = 15;
    int trig[15][15] = {
        {75},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20, 4, 82, 47, 65},
        {19, 1, 23, 75, 3, 34},
        {88, 2, 77, 73, 7, 63, 67},
        {99, 65, 4, 28, 6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
    };
    
    int prev, next; // for sum
    int aux = size - 2; // similar to i in for
    // bottom to top, sum best choises, ultil 0x0 is to total
    for(int i = (size - 2); i >= 0; i--){ // -1 for index and -1 to starting point (before last row)
        for(int j = 0; j <= aux; j++){
            // printf("[%d][%d]\n", i, j);
            prev = trig[i][j] + trig[i + 1][j];
            next = trig[i][j] + trig[i + 1][j + 1];
            trig[i][j] = prev > next ? prev : next;
        }
        aux--;
    }
    
    // printf("%d\n", trig[0][0]);
    return trig[0][0];
}

int main(void){
    assert(pathi_eg() == 23);
    assert(pathi() == 1074);
    
    return 0;
}
