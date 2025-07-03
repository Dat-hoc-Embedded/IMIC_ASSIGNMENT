/* OUTPUT: - Nhập danh sách 03 lớp, mỗi lớp có tên lớp, 05 sinh viên gồm thông tin : mã sinh viên, giới tính, điểm tổng kết.
           - Kiểm tra dữ liệu đầu vào : giới tính chỉ được nhập F/M, điểm tổng kết giới hạn từ 0-10.

   INPUT:  - In ra thông tin cả trường có bao nhiêu sinh viên nữ, sinh viên nam,
           - Thông tin sinh viên nam có điểm trung bình cao nhất trường, sinh viên nữ có điểm cao nhất trường
*/
#include <stdio.h>
#include <stdlib.h>
struct Student
{
    char code[30];
    char sex;
    double finalScore;
};
typedef struct Student Student;
struct Class
{
    char name[30];
    Student std[5];
};
typedef struct Class Class;

void programme();                      // Main programme

/* ----------------------  Tạo list Class     */
void makeList(int num_cl, Class cl[]); 
Class makeClass();
void setList(int *num_cl, Class cl[]); // Tạo default data

/* ----------------------  Hiển thị List Class */
double maxScore(int num_cl, Class cl[], char gt); // tính max score cho Male & Female
Student** address_Student(int num_cl, Class cl[], double (*maxsc)(int, Class [], char));
void displayList(Student **, int );

int main()
{
    programme();
    return 0;
}

void programme()
{
    system("chcp 65001 > null");
    int choice;
    int num_cl;     // Số lượng class (default = 3)
    int check = 0;  // không cho user chọn 2 khi chưa chọn 1
    do
    {
        printf("\n---------------- Student LLM -------------- \n");
        printf("\n 1. 📝  Make List of students ");
        printf("\n 2. 🖨️   Display students");
        printf("\n 0. ❌  Exit.");
        printf("\n ------------------------------------------- \n");
        printf("\nYour choice ?");
        scanf("%d", &choice);

        int tmp; // lựa chọn có dùng default data không ?
        switch (choice)
        {
        case 1:
            check ++;
            printf("\nDo you want to use default data? (1-Yes, 0-No): ");
            scanf("%d", &tmp);
            Class *cl = NULL;  
            if ( tmp == 1 )
            {
                cl = (Class *)calloc(3, sizeof(Class));
                setList(&num_cl, cl);
                printf("\n---- Data has been updated.");
            }
            else
            {
                printf("\n Input the number of class: ");
                scanf("%d", &num_cl);
                cl = (Class *)calloc(num_cl, sizeof(Class));
                makeList(num_cl, cl);
            }
            break;
        case 2: {// thành 1 khối lệnh vì C không cho khai báo trong switch
            if (check == 0){
                printf("\nYou don't initialize data. Choose 1 please ! ");
                printf("\n Press any key + enter to exit!");
                getchar();getchar();
                break;
            }
            Student** result = address_Student(num_cl,cl,maxScore);
            int tmp;
            do
            {
                printf("\n ------- Choose what you see ? ");
                printf("\n 0. List Male Student ");
                printf("\n 1. List Female Student ");
                printf("\n 2. Male Student have Max Score ");
                printf("\n 3. Female Student have Max Score ");
                printf("\n 4. Exit ");

                printf("\n Your choice ?"); scanf("%d", &tmp);
                if (tmp != 4){
                    displayList(result, tmp);
                    printf("\n Press any key + enter to exit!");
                    getchar();
                    getchar();
                }
            } while (tmp != 4);
            break;
        }
        case 0:
            printf("\n ----------- Thanks you for your access 😎 --------------------");
            break;
        default:
            printf("\n Not suitable!");
            break;
        }
    } while (choice);
}
void makeList(int num_cl, Class cl[])
{
    for (int i = 0; i < num_cl; i++)
    {
        printf("\n ------------ Enter information Class #%d", i + 1);
        cl[i] = makeClass();
    }
}

Class makeClass()
{
    Class x;
    printf("\nEnter class name: ");
    getchar();
    gets(x.name);
    for (int i = 0; i < 2; i++)
    { // 5 student
        printf("Enter inf of student # %d", i + 1);
        printf("\n\tCode: ");
        getchar();
        gets(x.std[i].code);
        do
        {
            printf("\tSex (M/F): ");
            scanf(" %c", &x.std[i].sex);
        } while (x.std[i].sex != 'M' && x.std[i].sex != 'F');
        do
        {
            printf("\tFinal score: ");
            scanf("%lf", &x.std[i].finalScore);
        } while (x.std[i].finalScore > 10 || x.std[i].finalScore < 0);
    }
    return x;
}

void setList(int *num_cl, Class *cl)
{
    *num_cl = 3;
    cl =  (Class*) realloc(cl, 3 * sizeof(Class));
    struct Class x = {"C++", {
                                 {"Mừng", 'F', 8.56},
                                 {"Ngày", 'M', 2.6},
                                 {"Nghỉ", 'F', 9},
                                 {"Lễ", 'M', 8.2},
                                 {"Lớn", 'M', 8.1},
                             }};
    struct Class y = {"LINUX", {
                                   {"Thống", 'M', 8.6},
                                   {"Nhất", 'F', 4.6},
                                   {"Đất", 'M', 7.8},
                                   {"Nước", 'F', 8},
                                   {"Ta", 'F', 8},
                               }};
    struct Class z = {"STM32", {
                                   {"Nam", 'F', 2.8},
                                   {"Bắc", 'M', 4.6},
                                   {"Hòa", 'M', 8.6},
                                   {"Làm", 'M', 8},
                                   {"Một", 'F', 8.1},
                               }};
    cl[0] = x;
    cl[1] = y;
    cl[2] = z;
}

double maxScore(int num_cl, Class cl[], char gt)
{
    double max = -1;
    /* check gt only = 'F' or 'M' */
    if (gt != 'F' && gt != 'M'){
        printf("Don't have gender in class");
        return max;
    } 
    for (int i = 0; i < num_cl; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cl[i].std[j].sex == gt)   // Check if sex =  gt <user input> 
            {
                if (cl[i].std[j].finalScore > max)
                {
                    max = cl[i].std[j].finalScore;
                }
            }
        }
    }
    return max;
}

Student** address_Student(int num_cl, Class cl[], double (*maxsc)(int, Class [], char)){
    double maxF = maxsc(num_cl, cl, 'F'); // Lấy điểm cao nhất của nữ
    double maxM = maxsc(num_cl, cl, 'M'); // Lấy điểm cao nhất của nam
    /* Con trỏ cấp 2 a lưu 4 con trỏ tiêu chí <Nam, nữ, nam maxscore, nữ maxscore> */

    Student **a = (Student**) malloc(5 * sizeof(Student*));
    for (int i = 0; i < 5; i++) a[i] = NULL;

    int count_male = 0, count_fmale = 0;
    int count_maxM = 0, count_maxF = 0;

    for (int i = 0; i < num_cl ; i++){ 
        for (int j = 0 ; j < 5; j++){   
            Student st = cl[i].std[j];

            if (st.sex == 'M'){
                a[0] = (Student*) realloc(a[0], (count_male + 1) * sizeof(Student));
                a[0][count_male++] = st;

                if (st.finalScore == maxM){
                    a[2] = (Student*) realloc(a[2], (count_maxM + 1) * sizeof(Student));
                    a[2][count_maxM++] = st;
                }
            } else if (st.sex == 'F'){
                a[1] = (Student*) realloc(a[1], (count_fmale + 1) * sizeof(Student));
                a[1][count_fmale++] = st;

                if (st.finalScore == maxF){
                    a[3] = (Student*) realloc(a[3], (count_maxF + 1) * sizeof(Student));
                    a[3][count_maxF++] = st;
                }
            }
        } 
    }

    // a[4] dùng để lưu số lượng các mảng
    a[4] = (Student*) malloc(4 * sizeof(int));  // ép kiểu như vùng int*
    ((int*)a[4])[0] = count_male;
    ((int*)a[4])[1] = count_fmale;
    ((int*)a[4])[2] = count_maxM;
    ((int*)a[4])[3] = count_maxF;

    return a;
}

void displayList(Student** result, int tc){
    int *counts = (int*) result[4];

    printf("\n--------- STUDENTS ---------- ");
    printf("\n+-----------+--------------+--------+------------+");
        printf("\n| Student # | Code         | Sex    | Score      |");
        for (int j = 0; j < counts[tc]; j++)
        {
            Student x = result[tc][j];
            printf("\n+-----------+--------------+--------+------------|\n");
            printf("|#%-9d ", j + 1);
            printf("| %-12s   | %-6c | %-10.2lf |", x.code, x.sex, x.finalScore);
        }
        printf("\n+-----------+--------------+--------+------------+\n");
}
