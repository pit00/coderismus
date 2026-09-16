// https://exercism.org/tracks/r/exercises/run-length-encoding
#include <stdio.h>

void encode(char *str){
    int i = 0;
    char actual;
    
    printf("\"");
    while(str[i] != '\0'){
        actual = str[i];
        int count = 0;
        while(str[i] == actual){
            count++;
            i++;
        }
        
        if(count > 1)
            printf("%d%c", count, actual);
        else
            printf("%c", actual);
    }
    printf("\"\n");
}

void decode(char *str){
    int i = 0;
    printf("\"");
    while(str[i] != '\0'){
        if(str[i] >= 58){
            printf("%c", str[i]);
        }
        else{
            int count = 0;
            
            while(str[i] >= 48 && str[i] <= 57){
                count *= 10;
                count += str[i] - '0';
                i++;
            }
            
            // printf("%d\n", count);
            for (int j = 0; j < count; j++){
                printf("%c", str[i]);
            }
        }
        i++;
    }
    printf("\"\n");
}

int main(void){
    printf("Encoder:\n");
    encode(""); // ""
    encode("XYZ"); // "XYZ"
    encode("AABBBCCCC"); // "2A3B4C"
    encode("WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB"); // "12WB12W3B24WB"
    encode("  hsqq qww  "); // "2 hs2q q2w2 "
    encode("aabbbcccc"); // "2a3b4c"
    encode("zzz ZZ  zZ"); // "3z 2Z2 zZ"
    
    printf("\nDecoder\n");
    decode(""); // ""
    decode("XYZ"); // "XYZ"
    decode("2A3B4C"); // "AABBBCCCC"
    decode("12WB12W3B24WB"); // "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB"
    decode("2 hs2q q2w2 "); // "  hsqq qww  "
    decode("2a3b4c"); // "aabbbcccc"
    decode("3z 2Z2 zZ"); // "zzz ZZ  zZ"
    
    return 0;
}
