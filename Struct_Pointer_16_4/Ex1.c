/* -=----------- Problem 1 ---------------
        Viết chương trình nhập dữ liệu cho 03 lớp, mỗi lớp có 5 sinh viên : tên lớp, mã lớp, sinhvien; 
    trong đó sinh viên có kiểu struct (mã sinh viên, điểm toán, điểm văn, điểm anh). 
    Hiển thị điểm trung bình của sinh viên và xếp loại sinh viên (bằng cách gọi hàm) 
    theo nguyên tắc : 1-5 : loại C, trên 5-8: Loại B, trên 8 : loại A. 
    Viết 02 function : function tính điểm trung bình và function xếp loại.*/
#include <stdio.h>
struct Student{
    char code[30];
    double math, lite, eng;
    double dtb ; // average Score of 1 Student  
    char xl; // rank of 1 Student
};
struct Class{
    char name[30]; 
    char code[30];
    struct Student std[5];
};

const int MaxListClass = 10; // Max class of list 
/* ------------------ Function make data*/
void makeList(int , struct Class []); // Create list for class_list
struct Class makeClass(); // Create list for one class

void displayList(int , struct Class []); //Show all class
void displayClass(struct Class); // Display one class for class_list
void programme(); // Main programme
void setList(int *,struct Class []); // Create data for test case

/* ------------------ Function calculate*/
void average_rank(int , struct Class []);

int main(){
    programme();
    return 0;
}

void programme(){
    system("chcp 65001 > null");
    int choice; // choice for user
    int num_cl; // option for number class (default = 3)          
    struct Class cl[MaxListClass];
    setList(&num_cl, cl); // default data for test case
    do {
        printf("\n---------------- Student LLM -------------- \n");
        printf("\n 1. Make List of students <Note: List has been set up. Please continue to 2! Thanks (❁´◡`❁) >");
        printf("\n 2. Display List of students");
        printf("\n 3. Calculate average score & ranking.");
        printf("\n 0. Exit. ");
        printf("\n ------------------------------------------- \n");
        printf("\nYour choice ?");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            makeList(num_cl, cl);       
            break;
        case 2:
            displayList(num_cl, cl); getchar();
            printf("\n Press any key + enter to exit!"); getchar();
            break;
        case 3: 
            average_rank(num_cl, cl);
            displayList(num_cl, cl); getchar();
            printf("\n Press any key + enter to exit!"); getchar();
            break;
        default:
            printf("\n Not suitable!");
            break;
        }
    }while(choice);
}
/* -------------- Input information for List of class*/
void  makeList(int num_cl, struct Class cl[MaxListClass]){
    printf("\n Enter the number of class:  "); 
    scanf("%d", &num_cl); 
    for (int i = 0; i < num_cl ; i++){
        printf("\n ------------ Enter information Class #%d", i + 1);   
        cl[i] = makeClass();
    }   
}
struct Class makeClass(){
    struct Class x; 
    printf("\nEnter class name: ");  getchar(); gets(x.name); 
    printf("Enter class code: "); gets(x. code);
    for (int i = 0 ; i < 5; i ++){  // 5 student
        printf("Enter inf of student # %d", i + 1);
        printf("\n\tCode: "); gets(x.std[i].code);
        printf("\tMath: "); scanf("%lf",&x.std[i].math);
        printf("\tLiterature: "); scanf("%lf",&x.std[i].lite);
        printf("\tEnglish: "); scanf("%lf",&x.std[i].eng); 
        getchar();
    }
    return x;
}
void displayList(int num_cl, struct Class cl[MaxListClass]){
    printf("\n--------- LISTS OF STUDENTS ---------- ");
    for (int i = 0; i < num_cl; i++){
        printf("\n --- #%d  ", i + 1);
        displayClass(cl[i]);
    }
}
void displayClass(struct Class x){
    printf("Class name: %s \t || \tClass code: %s", x.name, x.code);
    printf("\n+-----------+----------+--------+------------+----------+-----------+----------");
    printf("\n| Student # | Code     | Math   | Literature | English  | Average   |Ranking   ");
    for(int i = 0; i < 5; i++){
        printf("\n+-----------+----------+--------+------------+----------+-----------+----------\n");
        printf("|#%-9d ", i + 1);
        printf("| %-8s   | %-6.2lf | %-10.2lf | %-8.2lf | %-8.2lf | %-8c |", x.std[i].code, x.std[i].math, x.std[i].lite, x.std[i].eng, x.std[i].dtb, x.std[i].xl);
    }
    printf("\n+-----------+----------+--------+------------+----------+-----------+----------\n");
    //getchar();
}
void setList(int *num_cl, struct Class cl[MaxListClass]){
    *num_cl = 3;
    struct Class x = {"C++", "C++_F1", {{"Mừng",9.9,8.5,8.56},{"Ngày",1.2,1.1,2.6},{"Nghỉ",6.5,4.5,9},{"Lễ",6.1,7.9,8.2},{"Lớn",6.3,7.8,8.1},}};
    struct Class y = {"LINUX", "Linux_F4", {{"Thống",6.4,7.2,8.1},{"Nhất",6.2,8.4,4.6},{"Đất",5.6,4.7,7.8},{"Nước",6,7.8,8},{"Ta",6.7,7,8},}};
    struct Class z = {"STM32", "STM_F3", {{"Nam",8.6,3.7,2.8},{"Bắc",6,8,4.6},{"Hòa",6,7.8,8.6},{"Làm",6.9,3.9,8},{"Một",6.6,7,8.1},}};
    cl[0] = x; cl[1] = y; cl[2] = z;
}
void average_rank(int num_cl, struct Class cl[MaxListClass]){
    for (int i = 0; i < num_cl; i++){
        for (int j  = 0; j < 5; j++){ // số vòng lặp student
            double score = (cl[i].std[j].math + cl[i].std[j].lite + cl[i].std[j].eng)/3;
            cl[i].std[j].dtb = score;
            if (score <= 5) {
                cl[i].std[j].xl ='C';
            }else if (score <=8)
            {
                cl[i].std[j].xl = 'B';
            }else{
                cl[i].std[j].xl = 'A';
            }
            
        } 
    }
}
