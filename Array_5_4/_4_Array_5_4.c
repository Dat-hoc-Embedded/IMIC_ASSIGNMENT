#include <stdio.h>
void Draw(int rows);
int main(){
    int rows;
    printf("Input numbers of rows: ");
    scanf("%d", &rows);
    Draw(rows);
}
void Draw(int rows){
    for (int i = 1; i<=rows ; i++){
        for (int digit  = 1; digit <= i ; digit ++) 
            printf("%d  ", digit);
        printf("\n");
    }
}

