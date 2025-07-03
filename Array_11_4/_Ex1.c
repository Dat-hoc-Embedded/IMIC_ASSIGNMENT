/* ----------------- Problem 1 _ 12/4
    a./ Tạo mảng 2 chiều n x n với các phần tử là tự nhiên dương & xuất mảng.
    b./ Sort: Dòng tăng từ trái qua phải, cột tăng từ trên xuống dưới. 
*/
#include <stdio.h>
int inputSize();
void inputArray(int n, int [][10]);
void showArray(int n, const int [][10]);

void photoArray(int n, int [][10], int [][10]);

void sortRow(int n, int [][10], int id_row);
void sortRowArray(int n, int [][10]);

void sortCollumn(int n, int [][10], int id_collumn);
void sortCollumnArray(int n, int [][10]);
int main(){
    /* ---------- Input size square matrix*/
    //int a[10][10] = {{4,9,12},{3,9,4},{19,4,20}};
    int a[10][10];
    int rArr[10][10];
    int cArr[10][10];
    int n = inputSize();
    inputArray(n, a);
    printf("\n/*--------------- Array input \n");
    showArray(n, a);

    photoArray(n,a,rArr);
    sortRowArray(n,rArr);
    printf("\n/*--------------- Array sort by rows \n");
    showArray(n,rArr);

    photoArray(n,a,cArr);
    sortCollumnArray(n,cArr);
    printf("\n/*--------------- Array sort by collumns \n");
    showArray(n,cArr);
    return 0;
}
int inputSize(){
    int n; 
    printf("Input size square matrix (n x n): ");
    /* Check not suitable (char and number <=0)*/
    while (scanf("%d", &n)==0 || n <= 0){  
        printf("Value not suitable. Please re-enter! n = ");
        getchar();
    }
    return n;
}

void inputArray(int n, int a[][10]){
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n ;j++){
            printf("a[%d][%d] = ",i+1,j+1) ; 
            scanf("%d", &a[i][j]);
        }
        printf("\n");
    }
}

void showArray(int n, const int a[][10]){
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n ;j++){
            printf("%d \t" , a[i][j]);
        }
        printf("\n");
    }
}

void photoArray(int n, int a[][10], int cp[][10]){
    for (int i  = 0; i < n ;i ++){
        for (int j  = 0; j < n; j ++){
            cp[i][j] = a[i][j];
        }
    }
}

void sortRow(int n, int a[][10], int id_row){
    for(int i = 0; i < n - 1;i++){
        for (int j = i + 1; j < n; j++){
            if (a[id_row][i] > a[id_row][j]){
                int tmp = a[id_row][i];
                a[id_row][i] =  a[id_row][j];
                a[id_row][j] = tmp;
            }
        }
    }
}

void sortRowArray(int n, int a[][10]){
    for (int i = 0; i < n ;i++){
        sortRow(n, a, i);
    }
}

void sortCollumn(int n, int a[][10], int id_collumn){
    for(int i = 0; i < n - 1;i++){
        for (int j = i + 1; j < n; j++){
            if (a[i][id_collumn] > a[j][id_collumn]){
                int tmp = a[i][id_collumn];
                a[i][id_collumn] =  a[j][id_collumn];
                a[j][id_collumn] = tmp;
            }
        }
    }
}

void sortCollumnArray(int n, int a[][10]){
    for (int i = 0; i < n ;i++){
        sortCollumn(n, a, i);
    }
}