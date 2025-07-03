#include <stdio.h>

void SetupArray(int arr[], int ne);
int SumPositive(int arr[], int ne);
void Delete_p_index(int arr[], int ne, int p);
int main(){
    int ne;
    printf("Enter the number of elements: ");
    scanf("%d", &ne);
    int arr[ne];
    SetupArray(arr, ne);
    printf("\n=> Sum of positive interger: %d", SumPositive(arr, ne));

    /* --------------- Delete index p in array*/
    int p;
    printf("\nEnter the index is deleted: "); scanf("%d", &p);
    while (p > ne)
    {
        printf("\n Index p exceeds the number of elements. Re-enter!");
        scanf("%d", &p);
    }
    Delete_p_index(arr, ne, p);
}
void SetupArray(int arr[], int ne){
    /* ---------------- Enter array */
    for(int i = 0; i < ne; i++){
        printf("\narr[%d]= ", i + 1);
        do{
            scanf("%d", &arr[i]);
        }while(arr[i] < -100 || arr[i] > 100 );
    }
}
int SumPositive(int arr[], int ne){
    int sum_pi = 0;
    /* --------------- Sum positive interger */
    for (int i = 0 ; i < ne; i++){
        if (arr[i] > 0){
            sum_pi += arr[i] ;
        }
        printf("%d \t", arr[i]);
    }
    return sum_pi;
}

void Delete_p_index(int arr[], int ne, int p){
    for ( ne-- ; p - 1 < ne; p++){
        arr[p-1] = arr[p];  
    }
    printf("\n => Array is deleted index p: ");
    arr[ne] = 0;
    for (int i = 0 ; i < ne; i++){
        printf("%d \t", arr[i]);
    }
}