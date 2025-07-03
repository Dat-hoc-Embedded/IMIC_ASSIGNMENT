#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctor.h"

/* ------------ Check value */
int check_Invalid_Time(int h, int m, int s) {           // check time hợp lệ 
    return (h >= 24 || h < 0 || m >= 60 || m < 0 || s >= 60 || s < 0);
}
void check_Interger(int *n){                            // check giá trị khi nhập số nguyên
    int result = scanf("%d", n);

    while (result != 1) {
        // Xóa bộ đệm stdin: đọc và bỏ các ký tự lỗi còn lại
        while (getchar() != '\n');

        printf("Invalid input. Please enter an integer: ");
        result = scanf("%d", n);
    }
}

/* ------------ Input data*/
void setList(int *numdt, doctor *dt)                    //
{
    *numdt = 1;
    doctor *x = (doctor*) malloc(sizeof(doctor));
    if (x == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Cấp phát và gán tên
    char sample_name[] = "Dat_cham_chi";
    x->name = (char*) malloc((strlen(sample_name) + 1) * sizeof(char));
    strcpy(x->name, sample_name);

    // Số ca trực
    x->ns = 2; // ví dụ 2 ca

    // Cấp phát mảng shift
    x->s = (shift*) malloc(x->ns * sizeof(shift));
    if (x->s == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Khởi tạo từng shift
    for (int i = 0; i < x->ns; i++) {
        // Cấp phát ngày
        x->s[i].d = (date*) malloc(sizeof(date));
        x->s[i].d->day = 30 + i;   // VD: 30, 31
        x->s[i].d->month = 10;
        x->s[i].d->year = 2003;

        // Cấp phát time (2 mốc thời gian)
        x->s[i].t = (time*) malloc(2 * sizeof(time));
        // thời gian bắt đầu
        x->s[i].t[0].h = 8 + i;
        x->s[i].t[0].m = 30;
        x->s[i].t[0].s = 0;
        // thời gian kết thúc
        x->s[i].t[1].h = 16 + i;
        x->s[i].t[1].m = 45;
        x->s[i].t[1].s = 0;

        // Khoa (fac)
        char sample_fac[] = "Cardiology"; // Tim mạch
        x->s[i].fac = (char*) malloc((strlen(sample_fac) + 1) * sizeof(char));
        strcpy(x->s[i].fac, sample_fac);
    }
    *dt  = *x;
}

char* input_Name(){                                     // 1. Nhập tên 
    getchar();
    printf("\nEnter name of doctor: "); 
    char tmp[100];
    fgets(tmp,100,stdin);
    size_t len = strlen(tmp);
    if (len > 0 && tmp[len - 1] == '\n') {
        tmp[len - 1] = '\0';
    }
    char *n = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
    strcpy(n, tmp);
    return n;
}
date* input_Date(){                                     // 2. Nhập ngày của ca trực
    date *d = (date*)malloc(sizeof(date)); 
    do{
        printf("\nInput shift date (format dd/mm/yyyy): ");
        scanf("%d/%d/%d", &d->day, &d->month, &d->year);
        if (d->day > 31 || d->day < 1 || d->month >12 || d->month <1){
            printf("\n Not suitable. Please enter again!");
        }
    }while (d->day > 31 || d->day < 1 || d->month >12 || d->month <1); 

    return d;
}
time* input_Time(int (*check)(int, int, int))           // 3. Nhập thời gian ca trực
{
    time *t = (time *)malloc(2 * sizeof(time));
    for (int i = 0; i < 2; i++)
    {
        do
        {
            if (i == 0)
            {
                printf("\nInput start time (format h:m:s): ");
            }
            else
            {
                printf("\nInput end time (format h:m:s): ");
            }
            scanf("%d:%d:%d", &t[i].h, &t[i].m, &t[i].s);
            if (check(t[i].h, t[i].h, t[i].s))
            {
                printf("\n Not suitable. Please enter again!");
            }
        } while (check(t[i].h, t[i].h, t[i].s));
    }
    return t;
}
shift* input_Shift(int *ns)                             // 4. Nhập ca trực dùng 2,3
{
    /* Number Shift */
    printf("\nEnter number of shift: ");
    check_Interger(ns); // number shift

    shift *s = (shift *)calloc((*ns),sizeof(shift));
    /* Enter shift */
    for (int i = 0; i < *ns; i++)
    {
        printf("\n--------------- Enter shift #%d", i + 1);
        s[i].d = input_Date();
        s[i].t = input_Time(check_Invalid_Time);
        getchar();
        printf("\nFaculty: "); 
        char tmp[100];
        fgets(tmp,100,stdin);
        size_t len = strlen(tmp);
        if (len > 0 && tmp[len - 1] == '\n') {
            tmp[len - 1] = '\0';
        }
        s[i].fac = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
        strcpy(s[i].fac, tmp);
    }
    return s;
}
doctor* makeDoctor(){                                   // 5. Hàm nhập thông tin bác sĩ: dùng 1, 4
    doctor *dt = (doctor*)malloc(sizeof(doctor));
    dt->name = input_Name();
    dt->ns = 0;
    dt->s = input_Shift(&(dt->ns));

    return dt;
}
void makeList(doctor dt[], int numdt){                  // Hàm list bác sĩ: dùng 5 
    for (int i = 0; i < numdt; i++){
        printf("\n ---------------- Information doctor #%d", i + 1);
        dt[i] = *makeDoctor();
    }
}

/* ----------------- Show data */
void showDoctor(doctor dt){
    shift* s = (dt.s);
    printf("\nName: %s", (dt.name));
    for (int i = 0; i < dt.ns; i ++){
        date d = *(s->d);
        time t = *(s->t);
        time t2 = (s->t)[1];
        printf("\n Shift #%d: -> Date: %d/%d/%d \t|| Time: %d:%d:%d -> %d:%d:%d \t|| Faculty: %s", i + 1,d.day,d.month,d.year,t.h,t.m,t.s,t2.h, t2.m, t2.s, s->fac);
        s++;
    }
}
void showList(doctor dt[], int numdt){
    for (int i = 0; i < numdt; i++){
        printf("\n -------------- Doctor %d", i + 1);
        showDoctor(dt[i]);
    }
}

/* ----------------- Function 1. Thêm bác sĩ */
int check_existDoctor(doctor *dt, int numdt,  char* a){
    for (int i = 0; i < numdt; i ++){
        if(!strcmpi(dt[i].name,a)){   // Nếu giống
            printf("\n Doctor has existed in list.");
            return i+1; // tồn tại trong list -> trả về số thứ tự của bác sĩ giống
        }
    }
    return 0; // không tồn tại trong list
}
void addDoctor(doctor **dt, int *numdt, int (*check)(doctor *,int , char*)){
    doctor *x = (doctor*)malloc(sizeof(doctor)); // tạo biến mới doctor
    printf("\n ---------------------- ENTER INFORMATION NEW DOCTOR ");
    x->name = input_Name();
    int stt =  check(*dt, *numdt, x->name);
    if (stt != 0){
        int choice;
        printf("\n Do you want add shift for this doctor (1: Yes, 0: No) ? ");
        scanf("%d", &choice);
        if(choice == 1){
            (*dt)[stt-1].ns ++;
            (*dt)[stt-1].s = (shift*)realloc((*dt)[stt-1].s, ((*dt)[stt-1].ns) *sizeof(shift));
            printf("\n--------------- Enter new shift for %s", (*dt)[stt-1].name);
            (*dt)[stt-1].s[(*dt)[stt-1].ns -1].d = input_Date();
            (*dt)[stt-1].s[(*dt)[stt-1].ns -1].t = input_Time(check_Invalid_Time);
            getchar();
            printf("\nFaculty: "); 
            char tmp[100];
            fgets(tmp,100,stdin);
            // Xóa '\n' nếu có
            size_t len = strlen(tmp);
            if (len > 0 && tmp[len - 1] == '\n') {
                tmp[len - 1] = '\0';
            }
            (*dt)[stt-1].s[(*dt)[stt-1].ns -1 ].fac = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
            strcpy((*dt)[stt-1].s[(*dt)[stt-1].ns -1 ].fac, tmp);
        }
    }else{
        x->ns = 0; // khởi tạo ca trực = 0 ;
        x->s = input_Shift(&(x->ns));
        int sure;
        printf("Are you sure for updating (1: sure, 0: cancle) ? ");  
        check_Interger(&sure);
        if (sure) {
            (*numdt)++;
            *dt = (doctor*)realloc(*dt, (*numdt)*sizeof(doctor)); // cấp phát thêm vào dt
            printf("%d", *numdt);
            (*dt)[(*numdt)-1] = *x; // thêm vào cuối 
            printf("\nInformation of student was updated\n");
        }else printf("\nUpdating cancelled\n");
    }
}

/* ----------------- Function 2. Thêm bác sĩ trực vào ngày cụ thể */
int check_exisDay(doctor *dt, int numdt, date *d){
    int c  = 0;
    for (int i = 0; i < numdt; i ++){
        for (int j = 0; j < dt[i].ns; j ++){
            date *tmp = dt[i].s[j].d;
            if(tmp->day == d->day && tmp->month == d->month && tmp->year == d->year){   // Nếu giống
                printf("\n----------- Doctor has shift in date %d/%d/%d.",d->day,d->month,d->year);
                showDoctor(dt[i]);
                c ++;
            }
        }
    }
    return c;
}
void add_Doctor_in_Date(doctor **dt, int *numdt, int (*check1)(doctor *,int , date *d), int (*check2)(doctor *,int , char*)){
    date *d = NULL;
    d = input_Date();
    int ch =  check1(*dt, *numdt, d);

    doctor *x = (doctor*)malloc(sizeof(doctor)); // tạo biến mới doctor
    printf("\n ---------------------- ENTER DOCTOR for %d/%d/%d.",d->day,d->month,d->year);
    x->name = input_Name();
    int stt =  check2(*dt, *numdt, x->name);
    if (stt != 0){
        (*dt)[stt-1].ns ++;
        (*dt)[stt-1].s = (shift*)realloc((*dt)[stt-1].s, ((*dt)[stt-1].ns) *sizeof(shift));
        printf("\n--------------- Enter new shift for %s", (*dt)[stt-1].name);
        (*dt)[stt-1].s[(*dt)[stt-1].ns -1].d = d;
        (*dt)[stt-1].s[(*dt)[stt-1].ns -1].t = input_Time(check_Invalid_Time);
        getchar();
        printf("\nFaculty: "); 
        char tmp[100];
        fgets(tmp,100,stdin);
        // Xóa '\n' nếu có
        size_t len = strlen(tmp);
        if (len > 0 && tmp[len - 1] == '\n'){
            tmp[len - 1] = '\0';
        }
        (*dt)[stt-1].s[(*dt)[stt-1].ns -1 ].fac = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
        strcpy((*dt)[stt-1].s[(*dt)[stt-1].ns -1 ].fac, tmp);
    }else{
        x->ns = 0; // khởi tạo ca trực = 0 ;
        x->s = input_Shift(&(x->ns));
        int sure;
        printf("Are you sure for updating (1: sure, 0: cancle) ? ");  
        check_Interger(&sure);
        if (sure) {
            (*numdt)++;
            *dt = (doctor*)realloc(*dt, (*numdt)*sizeof(doctor)); // cấp phát thêm vào dt
            printf("%d", *numdt);
            (*dt)[(*numdt)-1] = *x; // thêm vào cuối 
            printf("\nInformation of student was updated\n");
        }else printf("\nUpdating cancelled\n");
    }
}

void free_memory(doctor **dt, int numdt) {
    for (int i = 0; i < numdt; i++) {
        for (int j = 0; j < (*dt)[i].ns; j++) {
            free((*dt)[i].s[j].d);
            (*dt)[i].s[j].d = NULL;

            free((*dt)[i].s[j].t);
            (*dt)[i].s[j].t = NULL;

            free((*dt)[i].s[j].fac);
            (*dt)[i].s[j].fac = NULL;
        }

        free((*dt)[i].s);
        (*dt)[i].s = NULL;

        free((*dt)[i].name);
        (*dt)[i].name = NULL;
    }

    free(*dt);
    *dt = NULL;

    // Kiểm tra
    if (*dt == NULL) {
        printf("Memory free successfully!\n");
    } else {
        printf("Memory free failed!\n");
    }
}

void menu(){
    printf("\n----------------🏥 DOCTOR MANAGEMENT -------------- \n");
    printf("\n 1. 📝  Make list of doctor.  ");
    printf("\n 2. 🖨️   Display doctor");
    printf("\n 3. ➕  Add doctor");
    printf("\n 4. ⌚  Add doctor in specify date");
    printf("\n 0. ❌  Exit.");
    printf("\n ------------------------------------------- \n");
    printf("\nYour choice ?");
}
