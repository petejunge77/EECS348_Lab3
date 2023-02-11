#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define td 6
#define tdp 7
#define tdc 8 
#define fg 3
#define sf 2



int main(){
    int score = 2;
    while (score > 1){
        printf("Enter 0 or 1 to stop combonation generator\n");
        printf("Enter a Football score: ");
        scanf("%d",&score);
        printf("Possble scoring combonations for this score\n");
        for (int i = 0; i < score; i++){
            for(int k = 0; k < score; k++){
                for(int l = 0; l < score; l++){
                    for(int m = 0; m < score; m++){
                        for(int n = 0; n < score;n++){
                            if (score == (i*tdc + k*tdp + l*td + m*fg + n*sf)){
                                printf("%d touchdown + 2pt, %d touchdown + FG, %d touchdown, %d FG 3pts, %d Safety\n",i,k,l,m,n);
                            }
                        }
                    }
                }
            }
        }

    }
return 0;
}
