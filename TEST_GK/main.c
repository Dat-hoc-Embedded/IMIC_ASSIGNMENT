# include <stdio.h>
# include <stdlib.h>
# include "doctor.h"

int main(){
    system("chcp 65001 > null");
    int choice = 0; 
    int numdt = 0; // number of doctor
    doctor *dt = NULL;
    int tmp; // lựa chọn có dùng default data không ?
    
    do{
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nDo you want to use default data? (1-Yes, 0-No): ");
            scanf("%d", &tmp);

            if (tmp == 1)
            {   
                dt = (doctor*)calloc(1, sizeof(doctor));
                setList(&numdt, dt);
                printf("\n---- Data has been updated.");
            }
            else
            {
                printf("\n Input the number of doctor:  ");
                check_Interger(&numdt);
                dt = (doctor*)calloc(numdt, sizeof(doctor)); // con trỏ dt -> mảng struct doctor 
                makeList(dt, numdt); 
            }
            break;
        case 2:
            showList(dt, numdt);
            printf("\n Press any key + enter to exit!");
            getchar();getchar();
            break;
        case 3:
            addDoctor(&dt,&numdt,check_existDoctor);
            break;  
        case 4:
            add_Doctor_in_Date(&dt,&numdt,check_exisDay, check_existDoctor);
            break;
        case 0:
            /* Giải phóng bộ nhớ*/
            free_memory(&dt, numdt);
            printf("\n ----------- Thanks you for your access 😎 --------------------");
            break;
        default:
            break;
        }
    }while(choice);

    return 0;
}
