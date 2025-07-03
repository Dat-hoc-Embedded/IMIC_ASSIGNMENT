# include <stdio.h>

void SetupArray(int arr[], int ne);
void ShowArray(int arr[], int ne);
void Sort_algorithm(int arr[], int ne);
int main(){
    int ne;
    printf("Enter the number of elements: ");
    scanf("%d", &ne);
    int arr[ne];
    /* ---------------- Enter array */
    SetupArray(arr, ne);

    Sort_algorithm(arr, ne);
    ShowArray(arr, ne);

}
void SetupArray(int arr[], int ne){
    /* -------- Enter array one dimension*/
    printf("Enter the elements: ");
    for (int i = 0; i < ne; i++)
        scanf("%d", &arr[i]);
}
void ShowArray(int arr[], int ne){
    printf("\nArray sorted increase: ");
    for (int i = 0 ; i < ne; i++){
        printf("%d \t", arr[i]);
    } 
}
void Sort_algorithm(int arr[], int ne){
    int min_index; int st;
    /* ---------------- Sort algorithm */
    for (int i = 0; i < ne - 1; i++){
        min_index = i ;
        for (int j = i + 1; j < ne; j++){
            if ( arr[min_index] > arr[j] ){
                min_index = j;
            }
        }
        if (min_index != i){
            st = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = st;
        }
    }
}
