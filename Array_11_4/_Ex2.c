/* -------------- Problem 2 _ 12/4
    a./ Trộn 2 mảng A, B được sắp xếp tăng, mảng kết quả là một mảng sắp xếp giảm
*/
#include <stdio.h>
void setupArray(int n, int a[]);
void showArray(int n, int a[]);
void sortArray(int n, int a[]);
void mergeArray(int na, int nb, int a[], int b[], int c[]);
int main(){
    /* --------------- Test case */
    int a[] = {1,6,25,3,9,16} ; int na = sizeof(a)/sizeof(a[1]);
    int b[] = {35,2,16,8,23,19,0}; int nb = sizeof(b)/sizeof(b[1]);

    /* -------------- Set up array A, B */
    // int na, nb;
    // int a[30], b[30]
    //printf("Enter the number of A: "); scanf("%d", &na);
    //setupArray(na, a);
    sortArray(na,a); 
    showArray(na,a);

    //printf("Enter the number of B: "); scanf("%d", &nb);
    //setupArray(nb, b);
    sortArray(nb,b);
    showArray(nb,b);

    int c[30];
    mergeArray(na,nb,a,b,c);

}
void setupArray(int n, int a[]){
    for (int i = 0; i < n;i ++){
        printf("a[%d] = ", i + 1);
        scanf("%d", &a[i]);
    }
}

void showArray(int n, int a[]){
    printf("\n");
    for(int i  = 0; i < n ;i ++){
        printf("%d \t", a[i]);
    }
}

void sortArray(int n, int a[]){
    for (int i = 0; i < n - 1; i++){
        for ( int j = i+ 1; j < n;  j++){
            if (a[i] > a[j]){
                int tmp  = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void mergeArray(int na, int nb, int a[], int b[], int c[]){
    int i = na - 1, j = nb - 1; // Set up index _ begin
    int nc = 0;
    while ( i >= 0 && j >= 0){
        c[nc++] = (a[i] > b[j]) ? a[i--] : b[j--];
    }
    showArray(nc,c);
    while (i >= 0){
        printf("%d", a[i--]);
    }
    while(j >= 0){
        printf("%d", b[j--]);
    }
}