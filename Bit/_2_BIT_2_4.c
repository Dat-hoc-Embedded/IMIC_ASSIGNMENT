#include <stdio.h>
int main(){
    unsigned int a;
    printf("Please input a integer number (16 bit, 0 < a < 65535): ");
    scanf("%i", &a);

    /*
        1234 = 0000 0100 1101 0010
        Muốn hiện 8 bit cao -> Tiến hành đẩy sang phải >> 8 
        Muốn hiện 8 bit thấp -> a & 0000 0000 1111 1111 => Giữ lại 8 bit thấp
    */
    
    printf ("\n8 bit high is: %d", a >> 8);
    printf ("\n8 bit low is: %d",  (a & 0b11111111));
    return 0;
}

