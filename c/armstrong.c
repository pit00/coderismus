// https://exercism.org/tracks/r/exercises/armstrong-numbers
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool armstrong(int numb){
    /* case int
    int div, count = 1;
    
    div = numb / 10;
    while(div != 0){
        div/=10;
        count++;
    }*/
    
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
    armstrong(0); // true
    armstrong(5); // true
    armstrong(9); // true
    armstrong(10); // false
    armstrong(100); // false
    armstrong(153); // true
    armstrong(154); // false
    armstrong(9474); // true
    armstrong(9475); // false
    armstrong(9926315); // true
    armstrong(9926314); // false
    
    return 0;
}
