#ifndef DOCTOR_H
#define DOCTOR_H

typedef struct Date{
    int day, month, year;
} date;

typedef struct Time{
    int h, m , s ;  // hour , minute, second
} time;

typedef struct Shift{
    date *d; // Sample: 30/10/2003   . *d -> struct date 
    time *t;  // VD: 13:45:10   . *t -> struct time[2] : t[0] là start time, t[1] là end time
    char *fac;  // faculty: Tim, Ngoai, Noi
} shift;

typedef struct Doctor{
    char *name;
    int ns;
    shift *s;  // con trỏ shift trỏ vào một mảng kiểu struct shift
} doctor;

void menu();
void free_memory(doctor **dt, int numdt);

/* ------------ Check value */
int check_Invalid_Time(int h, int m, int s);          // check time hợp lệ 
void check_Interger(int *n);                            // check giá trị khi nhập số nguyên
/* ------------ Input data*/
void setList(int *numdt, doctor *dt);                   //

char* input_Name();                                    // 1. Nhập tên 
date* input_Date();                                     // 2. Nhập ngày của ca trực
time* input_Time(int (*check)(int, int, int));           // 3. Nhập thời gian ca trực
shift* input_Shift(int *ns);                             // 4. Nhập ca trực dùng 2,3
doctor* makeDoctor();                                   // 5. Hàm nhập thông tin bác sĩ: dùng 1, 4
void makeList(doctor dt[], int numdt);                  // Hàm list bác sĩ: dùng 5 


/* ----------------- Show data */
void showDoctor(doctor dt);
void showList(doctor dt[], int numdt);

/* ----------------- Function 1. Thêm bác sĩ */
int check_existDoctor(doctor *dt, int numdt,  char* a);
void addDoctor(doctor **dt, int *numdt, int (*check)(doctor *,int , char*));

/* ----------------- Function 2. Thêm bác sĩ trực vào ngày cụ thể */
int check_exisDay(doctor *dt, int numdt, date *d);
void add_Doctor_in_Date(doctor **dt, int *numdt, int (*check1)(doctor *,int , date *d), int (*check2)(doctor *,int , char*));


#endif