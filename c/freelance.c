// https://www.codewars.com/kata/66e03a09eeaad7e94d9f40a9
#include <assert.h>

int max_earning(int *earnings, int k, int days){
    // dp[i][j]: max earnings up to day i, with j consecutive work days
    k++;
    days++;
    int dp[days][k];
    
    for (int i = 0; i < days; i++){
        // printf("i - %d\n", i);
        for (int j = 0; j < k; j++){
            dp[i][j] = 0;
            // printf("%d\n", dp[i][j]);
        }
    }
    
    // printf("%d\n", days);
    for (int i = 1; i < days; i++){
        for (int j = 1; j < k; j++){
            if (i >= j){
                // Work j days ending at i-1, then take a break before that
                // dp[i][j] = max(dp[i][j], dp[i - j][0] + sum(earnings[i - j:i]));
                int calc = dp[i - j][0];
                
                // printf("%d\n", calc);
                for (int n = i - j; n < i; n++){
                    calc += earnings[n];
                }
                dp[i][j] = (dp[i][j] > calc) ? dp[i][j] : calc;
            }
            // printf("%d\n", dp[i][j]);
        }
        // Take a break today
        dp[i][0] = dp[i - 1][0];
        for (int m = 1; m <= k; m++){
            if(dp[i][0] < dp[i - 1][m])
                dp[i][0] = dp[i - 1][m];
        }
    }
    
    int max = dp[0][0];
    for (int i = 0; i < days; i++){
        for (int j = 0; j < k; j++){
            // printf("%d\n", dp[i][j]);
            
            if(max < dp[i][j])
                max = dp[i][j];
        }
    }
    
    // printf("%d\n", max);
    return max;
}

int main(void){
    int earnings[] = {60, 70, 80, 40, 80, 90, 100, 20};
    int size = (int)(sizeof(earnings) / sizeof(earnings[0]));
    assert(max_earning(earnings, 3, size) == 480);
    
    int earnings2[] = {45, 12, 78, 34, 56, 89, 23, 67, 91};
    size = (int)(sizeof(earnings2) / sizeof(earnings2[0]));
    assert(max_earning(earnings2, 4, size) == 460);
    
    int earnings3[] = {[0] = 5, 3, 1, 8};
    size = (int)(sizeof(earnings3) / sizeof(earnings3[0]));
    assert(max_earning(earnings3, 1, size) == 13);
    
    return 0;
}
