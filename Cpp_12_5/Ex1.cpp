/* 
BTVN:   1. viết lại bài tìm chuỗi lớn nhất và nhỏ nhất ở trên dùng thuật toán sắp xếp
        2. in kí tự bit của biến nhập vào từ bàn phím không dùng toán tử bit và phép chia lấy bit nhị phân
*/
#include <iostream>
#include <string> 
using namespace std;
/* ---------------- In, Out Function */
void Input_string(int n, string s[]);
void show_String(int n, string *s);
void show_Min_max_string(int n, string s[]);

/* ---------------- Sorted Algorithm */
void Bubble_sort_String(int n, string s[]);
void Selection_Sort(int n, string s[]); 
void Insertion_Sort(int n, string s[]);

int main(){
    int n; // Lưu số string 
    cout << "Input number of string: ";
    cin >> n;
    cin.ignore();

    string *s;
    s  = new string [n];

    Input_string(n, s);
    cout <<"\n--------- Array that you input " << endl;;
    show_String(n, s);

    // cout << "\n-------- Array have been sorted by length min -> max " << endl;
    // Bubble_sort_String(n, s);
    // show_String(n, s);

    cout << "\n-------- Sorted by Bubble Sort " << endl;
    Bubble_sort_String(n, s);
    show_Min_max_string(n, s);

    cout << "\n-------- Sorted by Selection Sort " << endl;
    Selection_Sort(n, s);
    show_Min_max_string(n, s);

    cout << "\n-------- Sorted by Insertion Sort " << endl;
    Insertion_Sort(n, s);
    show_Min_max_string(n, s);

    delete [] s;  // erase memory 
}
void Input_string(int n, string s[]){
    /* Input string */
    for (int i =  0 ; i < n ;i ++){
        cout << "Input string #"<< i + 1 << ": ";
        getline(cin, s[i]); // *(s+i)
    }
}
void show_String(int n, string *s){
    /* Show string */
    for (int i = 0; i < n; i ++){
        cout << "String #" << i + 1 << ": "<< *(s+i) << endl;
    }
}
void Bubble_sort_String(int n, string s[]){
        /* Sort string []*/
    for (int i = 0 ; i < n - 1; i ++){
        for (int j = i + 1 ; j < n ; j ++){
            if (s[i].length() > s[j].length()) {
                string tmp;
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}
void show_Min_max_string(int n, string s[]){
    cout << "-> String have min length: " << s[0] << endl;
    cout << "-> String have max length: " << s[n-1];
}
void Selection_Sort(int n, string s[]){
    for(int i = 0 ; i < n - 1; i++){
        int min_index = i;
        for (int j = i +1  ; j < n; j ++){
            if (s[j].length() < s[min_index].length()){
                min_index = j;
            }
        }
        if (min_index != i){
            string tmp = s[i];
            s[i]  = s[min_index];
            s[min_index] = tmp;
        }
    }
}
void Insertion_Sort(int n, string s[]){
    for(int i = 1; i < n; i++){
        string key = s[i];
        int pos = i - 1;
        while (pos >=0 && key < s[pos])
        {   
            s[pos+1] = s[pos];
            pos--;
        }
        s[pos + 1] = key;
         
    }
}
