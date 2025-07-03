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
void makeList(int num_cl, Class cl[]); // Tạo một list Class
Class makeClass();                     // Tạo một Class
void displayList(int num_cl, Class cl[]);
void displayClass(Student x);
void displayBySex(int num_cl, Class cl[]);
void setList(int *num_cl, Class cl[]); // Tạo default data
double maxScoreMale(int num_cl, Class cl[]);
double maxScoreFemale(int num_cl, Class cl[]);
void displayMaxScore(int num_cl, Class cl[]);

int main()
{
    programme();
    return 0;
}
void programme()
{
    system("chcp 65001 > null");
    int choice;
    int num_cl; // Số lượng class (default = 3)
    do
    {
        printf("\n---------------- Student LLM -------------- \n");
        printf("\n 1. Make List of students ");
        printf("\n 2. Display List of students");
        printf("\n 3. Display Male & Female students.");
        printf("\n 4. Display Male & Female have max final_score. ");
        printf("\n 0. Exit.");
        printf("\n ------------------------------------------- \n");
        printf("\nYour choice ?");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Input the number of class: ");
            scanf("%d", &num_cl);
            Class *cl; // con trỏ kiểu class
            cl = (Class *)calloc(num_cl, sizeof(Class));

            int tmp;
            printf("\nDo you want to use default data? (1-Yes, 0-No): ");
            scanf("%d", &tmp);
            if (tmp == 1)
            {
                setList(&num_cl, cl);
                printf("\n---- Data has been updated.");
            }
            else
            {
                makeList(num_cl, cl);
            }
            break;
        case 2:
            displayList(num_cl, cl);
            printf("\n Press any key + enter to exit!");
            getchar();
            getchar();
            break;
        case 3:
            displayBySex(num_cl, cl);
            printf("\n Press any key + enter to exit!");
            getchar();
            break;
        case 4:
            displayMaxScore(num_cl, cl);
            printf("\n Press any key + enter to exit!");
            getchar();
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
void displayList(int num_cl, Class cl[])
{
    printf("\n--------- LISTS OF STUDENTS ---------- ");
    for (int i = 0; i < num_cl; i++)
    {
        printf("\n --- #%d  ", i + 1);
        printf("Class name: %s", cl[i].name);
        printf("\n+-----------+--------------+--------+------------+");
        printf("\n| Student # | Code         | Sex    | Score      |");
        for (int j = 0; j < 5; j++)
        {
            printf("\n+-----------+--------------+--------+------------|\n");
            printf("|#%-9d ", j + 1);
            displayClass(cl[i].std[j]);
        }
        printf("\n+-----------+--------------+--------+------------+\n");
    }
}
void displayClass(Student x)
{
    printf("| %-12s   | %-6c | %-10.2lf |", x.code, x.sex, x.finalScore);
}
void displayBySex(int num_cl, Class cl[])
{
    char t;
    int count = 0;
    do
    {
        t = printf("\nDisplay Female or Male (F/M): ");
        scanf(" %c", &t);
    } while (t != 'M' && t != 'F');

    printf("\n--------- LISTS OF STUDENTS BY SEX ---------- ");
    for (int i = 0; i < num_cl; i++)
    {
        printf("\n --- #%d  ", i + 1);
        printf("Class name: %s", cl[i].name);
        printf("\n+-----------+--------------+--------+------------+");
        printf("\n| Student # | Code         | Sex    | Score      |");
        for (int j = 0; j < 5; j++)
        {
            if (cl[i].std[j].sex == t)
            {
                printf("\n+-----------+--------------+--------+------------|\n");
                printf("|#%-9d ", j + 1);
                count ++;
                displayClass(cl[i].std[j]);
            }
        }
    }
    printf("\n+-----------+--------------+--------+------------+\n");
    printf("===> Total %c: %d", t, count);
    getchar();
}
void setList(int *num_cl, Class cl[])
{
    *num_cl = 3;
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

double maxScoreMale(int num_cl, Class cl[])
{
    double max = -1;
    for (int i = 0; i < num_cl; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cl[i].std[j].sex == 'M')
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
double maxScoreFemale(int num_cl, Class cl[])
{
    double max = -1;
    for (int i = 0; i < num_cl; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cl[i].std[j].sex == 'F')
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
void displayMaxScore(int num_cl, Class cl[]){
    double maxF = maxScoreFemale(num_cl,cl);
    double maxM = maxScoreMale(num_cl,cl);

    printf("\n--------- STUDENTS MAX SCORE BY SEX ---------- ");
    for (int i = 0; i < num_cl; i++)
    {
        printf("\n --- #%d  ", i + 1);
        printf("Class name: %s", cl[i].name);
        printf("\n+-----------+--------------+--------+------------+");
        printf("\n| Student # | Code         | Sex    | Score      |");
        for (int j = 0; j < 5; j++)
        {
            if (cl[i].std[j].sex == 'M' && cl[i].std[j].finalScore == maxM)
            {
                printf("\n+-----------+--------------+--------+------------|\n");
                printf("|#%-9d ", j + 1);
                displayClass(cl[i].std[j]);
            }
            if (cl[i].std[j].sex == 'F' && cl[i].std[j].finalScore == maxF)
            {
                printf("\n+-----------+--------------+--------+------------|\n");
                printf("|#%-9d ", j + 1);
                displayClass(cl[i].std[j]);
            }
        }
    }
    printf("\n+-----------+--------------+--------+------------+\n");
    getchar();
}