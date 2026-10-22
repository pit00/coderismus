/* https://projecteuler.net/problem=22 */
#include <assert.h>
#include <stdio.h>
#include <string.h>

int scores(char *filename){
    FILE *f = fopen(filename, "r");
    int sum = 0;
    int total = 0;
    
    if (f != NULL){ // NULL case fail
        char names[5200][50];
        char aux[50];
        char c = ' ';
        int i = 0, j = 0;
        
        // fscanf(f, "%s", name);
        while(c != EOF){
            c = fgetc(f);
            
            if(c == ',' || c == EOF){ // next name
                names[i][j] = '\0';
                
                if(i > 0){ // sort
                    if(strcmp(names[i], names[i - 1]) < 0){ // actual < prev
                        for (int k = 0; k < i; k++) {
                            if (strcmp(names[i], names[k]) < 0) { // actual < loop
                                
                                strcpy(aux, names[i]); // bak actual
                                
                                for (int w = i; w > k; w--) { // shift
                                    strcpy(names[w], names[w - 1]);
                                }
                                
                                strcpy(names[k], aux); // loop = actual
                                break;
                            }
                        }
                    }
                }
                i++;
                j = 0;
                // printf("\n");
            }
            else if (c >= 'A' && c <= 'Z'){ // else if (c != '"' && c != EOF){
                names[i][j] = c;
                // printf("%c", c);
                j++;
            }
        }
        
        // printf("%d\n", i); // total names
        j = 0;
        for(int h = 0; h < i; h++){
            // printf("%d. %s\n", h + 1, names[h]);
            while(names[h][j] != '\0'){
                sum += (names[h][j] - 64); // A is 65, minus 64 give 1 (alph pos)
                // printf("%d\n", names[h][j] - 64);
                
                j++;
            }
            sum *= (h + 1); // rank
            
            // printf("%d\n", sum);
            total += sum;
            j = 0;
            sum = 0;
        }
    }
    
    // printf("%d\n", total);
    fclose(f); // must close
    return total;
}

int main(void){
    assert(scores("./Data/0022_names.txt") == 871198282);
    
    return 0;
}
