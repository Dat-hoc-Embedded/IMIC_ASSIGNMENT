/* --------- Problem 1 
    ./ Bật bit 9 của số nhị phân 0000100000100100
*/
#include <stdio.h>
void Bit_9_On(int n);
int main(){
    int n = 0b0000100000100100;
    printf("You input: %d", n);
    Bit_9_On(n);
}
void Bit_9_On(int n){
    n = n | (1 << 9);
    printf("\nBit 9 on is: %d", n);
}