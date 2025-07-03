// Viết chương trình nhập vào số tự nhiên n
#include <stdio.h>
void Caculate(int n);
int main(){
    int n;
    printf("Input natural number (n>=0): "); 
    scanf("%d",&n);
    while(-(n>>31)){ // Kiểm tra âm hoặc dương
        printf("Invalid!. Please re-enter: "); 
        scanf("%d",&n);
    }
   Caculate(n);
}
void Caculate(int n){
    int count = 0;
    int reverse_n = 0;
    int sum = 0, digit;
    while (n>0)
    {
        count++;
        digit = n%10;
        if(count == 1) printf("The last digit of n: %d",digit);
        n = n/10;
        sum += digit;
        reverse_n = reverse_n*10 + digit;
    }
    printf("\nThe number digits of n: %d", count);
    printf("\nThe first digit of n: %d", digit);
    printf("\nSum of digits: %d", sum);
    printf("\nThe reverse number of n: %d", reverse_n);
}

