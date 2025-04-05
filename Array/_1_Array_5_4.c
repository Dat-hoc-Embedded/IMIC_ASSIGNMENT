#include <stdio.h>
int main(){
    int n ;
    // Input value to change Dec -> Bin
    printf("Input positive interger number (>0): ");
    scanf("%d", &n);
    
        // Check positive
    while(-(n>>31))   scanf("%d", &n);
    printf("Dec: %d\n", n);
    printf("Bin: ");

    // Transfer Dec to Bin
    for (int i=sizeof(n)*8-1; i>=0; i--){
        if((n>>i) & 1)  printf("%d", 1);
        else printf("%d",0);
    }
}