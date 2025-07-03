#include <stdio.h>
void Transfer_Dec_to_Bin(int n);

int main(){
    /*  - Khi chỉ nhập và xuất thì kiểu unsigned hay int đều như nhau 
        chỉ khi thực hiện các phép toán bit sẽ có khác khi nhập số âm.
        máy tính sẽ hiểu với kiểu int số 1 ở đầu là bit dấu, còn với 
        unsigned int thì số 1 ở đầu là số bình thường.  
    */
    int n ;
    // Input value to change Dec -> Bin
    printf("Input positive interger number (>0): ");
    scanf("%d", &n);
    // Check positive
        
    while(-(n>>31))   scanf("%d", &n);
    printf("Dec: %d\n", n);
    printf("Bin: ");

    Transfer_Dec_to_Bin(n);

}
void Transfer_Dec_to_Bin(int n){
    // Transfer Dec to Bin
    for (int i=sizeof(n)*8-1; i>=0; i--){
        if((n>>i) & 1)  printf("%d", 1);
        else printf("%d",0);
    }
}