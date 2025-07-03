#include <stdio.h>

/* -------- Classify odd, even elements*/
void SetupArray(int arr[], int ne);
void Classify_odd_even(int arr[], int ne , int arr_odd[],int co, int arr_even[], int ce, int sum_odd, int sum_even);
int main()
{
    int ne;
    int ce = 0, co = 0; // count odd & even elements
    int sum_odd = 0, sum_even = 0; // varibale for sum
    int arr_odd[30], arr_even[30]; // arrray for classify
    printf("Enter the number of elements: ");
    scanf("%d", &ne);
    int arr[ne];
    SetupArray(arr, ne);
    Classify_odd_even(arr, ne, arr_odd, co, arr_even, ce, sum_odd, sum_even);

}
void SetupArray(int arr[], int ne){
    /* -------- Enter array one dimension*/
    printf("Enter the elements: ");
    for (int i = 0; i < ne; i++)
        scanf("%d", &arr[i]);
}
void Classify_odd_even(int arr[], int ne , int arr_odd[], int co, int arr_even[], int ce, int sum_odd, int sum_even){
    for (int i = 0; i < ne; i++)
    {
        //printf("%d \t", arr[i]);
        if (arr[i] & 1){      // odd
            arr_odd[co] = arr[i] ;
            co ++;
            sum_odd += arr[i]; 
        }else{
            arr_even[ce] = arr[i] ;
            ce ++;
            sum_even += arr[i]; 
        }
    }
    printf("\nArray odd element: ");
    for(int i = 0; i < co; i++){
        printf("%d \t", arr_odd[i]);
    }
    printf("=> Sum odd elements: %d \t", sum_odd);

    printf("\nArray even element: ");
    for(int i = 0; i < ce; i++){
        printf("%d \t", arr_even[i]);
    }
    printf("=> Sum even elements: %d \t", sum_even);
}

