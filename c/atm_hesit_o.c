// https://www.codewars.com/kata/5d8108a41e94580023bd6419
#include <assert.h>

// Calc maximum thrill given a integer list
int maximum_thrill(int *atms, int size){
    // atms[i] + atms[j] + abs(i - j);
    // possibilities
    // part1 = atms[i] +- i
    // part2 = atms[j] -+ j
    
    // initiating as 0
    int max_thrill = 0;
    int part2_minus = 0; // atms[j] - j;
    int part2_plus = 0; // atms[j] + j;
    
    // The sum is the possibilities current (i) part + best another (j, prev) part
    for (int i = 0; i < size; i++) {
        int part1_plus = atms[i] + i;
        int part1_minus = atms[i] - i;
        
        // current part1 + best prev part2
        int case1 = part1_plus + part2_minus;
        int case2 = part1_minus + part2_plus;
        
        // set the best prev part2, when exist
        if (part1_minus > part2_minus)
            part2_minus = part1_minus;
        if (part1_plus > part2_plus)
            part2_plus = part1_plus;
        
        // set max_thrill, when exist
        if (case1 > max_thrill)
            max_thrill = case1;
        if (case2 > max_thrill)
            max_thrill = case2;
    }
    
    return max_thrill;
}

int main(void){
    int atms[] = {3, 1, 3};
    int size = (int)(sizeof(atms) / sizeof(atms[0]));
    assert(maximum_thrill(atms, size) == 8);
    
    int atms2[] = {2, 3, 4, 5};
    size = (int)(sizeof(atms2) / sizeof(atms2[0]));
    assert(maximum_thrill(atms2, size) == 10);
    
    int atms3[] = {10, 10, 11, 13, 7, 8, 9};
    size = (int)(sizeof(atms3) / sizeof(atms3[0]));
    assert(maximum_thrill(atms3, size) == 26);
    
    int atms4[] = {2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 11, 12, 4, 4, 2, 2, 12, 8};
    size = (int)(sizeof(atms4) / sizeof(atms4[0]));
    assert(maximum_thrill(atms4, size) == 34);
    
    return 0;
}
