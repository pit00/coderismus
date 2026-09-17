// https://exercism.org/tracks/r/exercises/luhn
#include <assert.h>
// #include <stdio.h>

bool luhn(char card[]){
    int size = 0, i = 0;
    while(card[i] != '\0'){
        if(card[i] == ' ')
            i++;
        else if(0 <= (card[i] - 48) && (card[i] - 48) <= 9){
            i++;
            size++;
        }
        else
            return false;
    }
    
    // printf("%s\n", card);
    char aux[size];
    int count = 0;
    // Trim spaces
    for(int i = 0; card[i] != '\0'; i++){
        if(card[i] != ' '){
            aux[count] = card[i];
            count++;
        }
    }
    // printf("%s\n", aux);
    // printf("%d\n", count);
    
    if(count == 16){
        // Get digits at odd positions
        int sum_odd = 0, sum_even = 0;
        int odd;
        for(int i = 0; i < count; i++){
            if((i % 2) == 0){ // "even", because is right to left
                odd = (aux[i] - 48) * 2;
                odd = (odd > 9) ? (odd - 9) : odd;
                sum_odd += odd;
            }
            else{ // "odd" (right to left)
                sum_even += (aux[i] - 48);
            }
        }
        
        // printf("%d\n", (sum_odd + sum_even));
        if((sum_odd + sum_even) % 10 == 0){
            // printf("Valid credit card number");
            return true;
        }
    }
    return false;
}

int main(void){
    // int size = (int)(sizeof(card) - 1); // char is 1 byte - ␀
    assert(luhn("4539 3195 0343 6467") == true);
    assert(luhn("8273 1232 7352 0569") == false);
    assert(luhn("8273 123A 7352 0569") == false);
    assert(luhn("8273 123227352 0569") == false);
    
    return 0;
}
