#include <stdio.h>
void SetupArray(int arr[], int ne);
void ShowArray(int arr[], int ne);
void Max_appear(int arr[], int ne);
int main(){
    // input number element
    int ne;  
    printf("Input number element: ");
    scanf("%d", &ne);
    int arr[ne];

    SetupArray(arr, ne);
    ShowArray(arr, ne);
    Max_appear(arr, ne);

}

void SetupArray(int arr[], int ne){
    /* -------- Enter array one dimension*/
    printf("Enter the elements: ");
    for (int i = 0; i < ne; i++)
        scanf("%d", &arr[i]);
}
void ShowArray(int arr[], int ne){
    printf("Array you inputed: [\t");
    for (int i=0; i<ne; i++){
        printf("%d \t",arr[i]);
    };printf("]");
}
void Max_appear(int arr[], int ne){
    int _max = 1; // lưu số lần xuất hiện lớn nhất
    int count_index[ne] ; // Lưu số lần xuất hiện của từng phần tử
    for(int i = 0; i < ne ;i++){
        if (count_index[i] == 0){  // Nếu giá trị đang xét là giá trị mà đã đếm rồi thì tiếp tục lần lặp tiếp
            continue;
        }
        int _count = 1; // đếm số lần xuất hiện
        for (int j = i+1; j < ne ; j++){ // duyệt tất cả phần từ ở sau phần tử đang xét
            if(arr[i] == arr[j]){ // Nếu bằng giá trị đang xét thì đếm + 1, cho các vị trị đã đếm = 0 
                _count ++; 
                count_index[j] = 0;
            }
        }
        count_index[i]  = _count; // Vị trí đang xét lưu số lần xuất hiện
        if (_count > _max){
            _max = _count;  // So sánh với các lần count để có được _max cuối cùng
        }
    }
    printf("\n Max_count_appear: %d", _max);

    // In ra những giá trị xuất hiện nhiều nhất
    printf("\nElement has max appear: [\t");
    for (int i=0; i<ne; i++){
        if (count_index[i] == _max){
            printf("%d \t",arr[i]);
        }
    };printf("]");
}
