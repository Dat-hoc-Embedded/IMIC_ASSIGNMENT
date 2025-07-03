/* ---------------------- Problem 2 
    Cho mảng 1,2,3,2,4,1,1,7. Viết chương trình đưa ra phần tử có 
    lần xuất hiện nhiều nhất dùng con trỏ và trả lại kết quả là một mảng 
    các phần tử có lần xuất hiện nhiều nhất, mỗi phần tử gồm 02 thông tin vị trí & số lần xuất hiện.
*/
#include <stdio.h>

struct elementMaxAppear{
    int *po[10], cpo; // mảng con trỏ lưu vị trí. 
    int value;  // giá trị phần tử xuất hiện nhiều nhất 
    int count; // số lần xuất hiện nhiều nhất
};
void SetupArray(int arr[], int ne);
void ShowArray(int arr[], int ne);
void maxAppear(int arr[], int ne, struct elementMaxAppear [], int *);
void showResult(struct elementMaxAppear [], int); 
int main(){
    int ne;  
    /* ---------------- Enter number element */
    printf("Input number element: ");
    scanf("%d", &ne);
    int arr[30];
    /* ----------------- Set up & show array */
    SetupArray(arr, ne);
    ShowArray(arr, ne);
    /* ----------------- Find element max appear */
    struct elementMaxAppear elm[30];
    int nelm = 0;
    maxAppear(arr, ne, elm, &nelm);
    showResult(elm, nelm);
}
void SetupArray(int arr[], int ne){
    /* -------- Enter array one dimension*/
    printf("Enter the elements (Note: != 0): ");
    for (int i = 0; i < ne; i++)
        scanf("%d", &arr[i]);
}
void ShowArray(int arr[], int ne){
    printf("Array you inputed: [\t");
    for (int i=0; i<ne; i++){
        printf("%d \t",arr[i]);
    };printf("]");
}
void maxAppear(int arr[], int ne, struct elementMaxAppear elm[], int *ce){
    int *p = arr; // p trỏ vào arr[0]
    while (p <= &arr[ne - 1]){ // địa chỉ của p = địa chỉ phần tử gần cuối [ne - 2]
        int *p2 = p + 1;
        int count = 1;
        if (*p == 0){
            p++;    
            continue;
        }
        elm[*ce].po[0] = p;
        elm[*ce].cpo = 0;
        while (p2 <= &arr[ne - 1] ){  // loop for p2 = p + 1 -> arr[ne - 1]
            if (*p == *(p2)){ // value p = p2
                *p2 = 0;
                elm[*ce].po[++elm[*ce].cpo] =  p2;
                count ++;
            }
            p2++;
        }
        elm[*ce].value = *p;
        elm[*ce].count = count;
        (*ce)++;
        p++;
    }
}
void showResult(struct elementMaxAppear elm[], int nelm){
    printf("\n--------- List appearance of element \n");
    printf("\n+-----------+----------+-----------------+");
    printf("\n| Element   | Count    | Adress          |");
    for (int i = 0; i < nelm; i++ ){
        printf("\n+-----------+----------+-----------------+\n");
        printf("| %-9d | %-8d |", elm[i].value, elm[i].count);
        for (int j  = 0; j <= elm[i].cpo; j ++){
            printf("%p\t",elm[i].po[j]);
        }
    }   
}