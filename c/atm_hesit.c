// https://www.codewars.com/kata/5d8108a41e94580023bd6419
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool maximum_thrill(int numb){
    char num[10];
    
    // int to char
    snprintf(num, sizeof num, "%d", numb);
    
    int count = strlen(num), i = 0, calc = 0;
    
    while(num[i] != 0){
        calc += pow(num[i] - 48, count); // char to int
        i++;
    }
    bool arms = (calc == numb);
    printf("%d is %s\n", numb, arms ? "true" : "false");
    
    return arms;
}

int main(void){
    maximum_thrill(atms=[3, 1, 3]);
    // 8: $3 + $3 + $2 transferred between each (atms[0] and atms[2])
    maximum_thrill(atms=[2, 3, 4, 5]);
    // 10 :$5 + $5 + $0 transferred (atms[3] and atms[3] again)
    maximum_thrill(atms=[10, 10, 11, 13, 7, 8, 9]);
    // 26: $10 + $13 + $3 transfer between each (atms[0] and atms[3])
    maximum_thrill(atms=[2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 11, 12, 4, 4, 2, 2, 12, 8]);
    // 34: $10 + $12 + $12 transfer between each (atms[4] and atms[16])
    
    return 0;
}
