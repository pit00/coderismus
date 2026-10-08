#include <assert.h>
// #include <stdio.h>

int swicher(int i){
    int sum = 0;
    
    // 1 to 9
    if (i <= 9){
        switch(i){
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
            case 6:
                sum += 3; // six
                break;
            case 7:
                sum += 5; // seven
                break;
            case 8:
                sum += 5; // eight
                break;
            case 9:
                sum += 4; // nine
                break;
        }
    }
    
    // 10 to 20
    if (i >= 10 && i <= 20){
        switch(i){
            case 10:
                sum += 3; // ten
                break;
            case 11:
                sum += 6; // eleven
                break;
            case 12:
                sum += 6; // twelve
                break;
            case 13:
                sum += 8; // thirteen
                break;
            case 14:
                sum += 8; // fourteen
                break;
            case 15:
                sum += 7; // fifteen
                break;
            case 16:
                sum += 7; // sixteen
                break;
            case 17:
                sum += 9; // seventeen
                break;
            case 18:
                sum += 8; // eighteen
                break;
            case 19:
                sum += 8; // nineteen
                break;
            case 20:
                sum += 6; // twenty
                break;
        }
    }
    
    // 30, 40, ... 90
    if (i >= 30){
        switch(i){
            case 30:
                sum += 6; // thirty
                break;
            case 40:
                sum += 5; // forty
                break;
            case 50:
                sum += 5; // fifty
                break;
            case 60:
                sum += 5; // sixty
                break;
            case 70:
                sum += 7; // seventy
                break;
            case 80:
                sum += 6; // eighty
                break;
            case 90:
                sum += 6; // ninety
                break;
        }
    }
    
    return sum;
}

int counts(int max){
    int sum = 0;
    int u, d, c;
    
    for(int i = max; i > 0; i--){
        if (i == 1000){
            sum += 11; // onethousand
        }
        else if (i > 99){
            u = i % 10;
            d = ((i / 10) % 10) * 10;
            c = (i / 100);
            sum += swicher(c) + 7; // hundred | x00
            
            if (u == 0){ // xx0
                if (d != 0){ // xx0
                    sum += swicher(d) + 3; // and
                } // else x00
            } else{ // xxx
                if (d == 0){ // x0x
                    sum += swicher(u) + 3; // and
                } else{ // xxx
                    if (i % 100 < 20){
                        sum += 3; // and
                        sum += swicher(i % 100);
                    } else{
                        sum += 3; // and
                        sum += swicher(u);
                        sum += swicher(d);
                    }
                }
            }
        }
        else if (i > 20){
            u = i % 10;
            if (u == 0){ // x0
                sum += swicher(i);
            } else{ // xx
                d = (i / 10) * 10;
                sum += swicher(u);
                sum += swicher(d);
            }
        } else{
            sum += swicher(i);
        }
    }
    
    // printf("%d\n", sum);
    return sum;
}

int main(void){
    assert(counts(5) == 19);
    assert(counts(1000) == 21124);
    
    return 0;
}
