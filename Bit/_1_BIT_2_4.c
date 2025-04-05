#include <stdio.h>

int main(){
    int n = 0b0000100000100100;
    printf("You input: %d", n);

    n = n | (1 << 9);
    printf("\nBit 9 on is: %d", n);
}