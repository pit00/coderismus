// https://www.codewars.com/kata/5d8108a41e94580023bd6419
#include <stdio.h>
#include <stdlib.h>

// Calc maximum thrill given a integer list
int maximum_thrill(int *atms, int size){
    int max_thrill = atms[0];
    for(int i = 1; i < size; i++){
        if(atms[i] > max_thrill)
            max_thrill = atms[i];
    }
    max_thrill *= 2;
    
    int calc;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            calc = atms[i] + atms[j] + abs(i - j);
            max_thrill = (max_thrill > calc) ? max_thrill : calc;
        }
    }
    
    printf("%d\n", max_thrill);
    return max_thrill;
}

int main(void){
    int atms[] = {3, 1, 3};
    int size = (int)(sizeof(atms) / sizeof(int));
    maximum_thrill(atms, size); // 8: $3 + $3 + $2 transferred between each (atms[0] and atms[2])
    
    int atms2[] = {2, 3, 4, 5};
    int size2 = (int)(sizeof(atms2) / sizeof(int));
    maximum_thrill(atms2, size2); // 10 :$5 + $5 + $0 transferred (atms[3] and atms[3] again)
    
    maximum_thrill((int[]){10, 10, 11, 13, 7, 8, 9}, (int)(sizeof((int[]){10, 10, 11, 13, 7, 8, 9}) / sizeof(int)));
    // 26: $10 + $13 + $3 transfer between each (atms[0] and atms[3])
    
    maximum_thrill((int[]){2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 11, 12, 4, 4, 2, 2, 12, 8}, (int)(sizeof((int[]){2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 11, 12, 4, 4, 2, 2, 12, 8}) / sizeof(int)));
    // 34: $10 + $12 + $12 transfer between each (atms[4] and atms[16])
    
    return 0;
}
