/* https://projecteuler.net/problem=19 */
#include <assert.h>
// #include <stdio.h>

/* Calendar
1. Jan 31
2. Fev 28 | 29 [%4, exlcuding century (%100) | %400]
3. Mar 31
4. Abr 30
5. Mai 31
6. Jun 30
7. Jul 31
8. Ago 31
9. Set 30
10. Out 31
11. Nov 30
12. Dez 31
*/

int sundays(int d){
    /*
    1/Jan/1900 is Monday.
    Range is [1/Jan/1901 to 31/Dec/2000]
    */
    enum {
        jan = 1,
        fev,
        mar,
        abr,
        mai,
        jun,
        jul,
        ago,
        set,
        out,
        nov,
        dez,
        
        com = 28,
        leap,
        unc,
        def
    };
    int sunday = 7; // The first sunday of 1900 is 7 Jan
    int month = 1;
    int max = def;
    int year = 1900;
    int count = 0;
    
    while(1){
        if (sunday == d && year > 1900){
            // printf("%d/%d/%d\n", sunday, month, year);
            count++;
        }
        sunday += 7;
        
        if (sunday > max){
            month++;
            // printf("%d [%d]\n", sunday, max);
            sunday -= max;
            // printf("%d\n", sunday);
            
            if(month == abr || month == jun || month == set || month == nov){
                max = unc;
            }
            else if (month == fev){
                if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
                    max = leap;
                }
                else{
                    max = com;
                }
            }
            else{
                if (month > dez){
                    year++;
                    month = 1;
                }
                max = def;
            }
        }
        
        if(year > 2000)
            break;
    }
    
    // printf("%d\n", count);
    return count;
}

int main(void){
    assert(sundays(1) == 171);
    
    return 0;
}
