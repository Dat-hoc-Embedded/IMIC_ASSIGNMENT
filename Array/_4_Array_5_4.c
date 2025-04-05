#include <stdio.h>
int main(){
    int rows;
    printf("Input numbers of rows: ");
    scanf("%d", &rows);

    for (int i = 1; i<=rows ; i++){
        for (int digit  = 1; digit <= i ; digit ++) 
            printf("%d  ", digit);
        printf("\n");
    }
}