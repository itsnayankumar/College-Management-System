#include<stdio.h>
#include<string.h>
#include "struct.h"

void addStaff() {
    printf("Enter Your Name :");
    scanf("%s", staffs[staffcount].name);
    
    printf("Enter Your Location :");
    scanf("%s", staffs[staffcount].location);
    
    printf("Enter Your Work :");
    scanf("%s", staffs[staffcount].work);

    printf("Enter Your Attendance :");
    scanf("%d", &staffs[staffcount].attend);
    
    printf("Enter Your Salary :");
    scanf("%d", &staffs[staffcount].salary);
    staffcount++;
    FILE *staff;
        staff = fopen("staff.dat", "ab");
        fwrite(&staffs[staffcount-1],sizeof(struct Staff),1,staff);
        fclose(staff);
}

void attendpercentstaff() {
    char nametofind[50];
    int foundIndex = -1;
    float attend;
    printf("Enter Your Name For the Attendance Report :");
    scanf("%s", nametofind);

    for(int i = 0; i < staffcount; i++) {
        if(strcmp(staffs[i].name, nametofind) == 0) {
            foundIndex = i;
            break;
        }
    }

    if(foundIndex < 0) {
        printf("No User Found !!");
    }else{
         int attendance = staffs[foundIndex].attend;
        attend = ((float)attendance/30) * 100;
        printf("Your Attendance Report is %f", attend);
    }
}

void editStaff() {
    char nametofind[50];
    int foundIndex = -1;
    int choice;
    printf("Enter Your Name :");
    scanf("%s", nametofind);

    for(int i = 0; i < staffcount; i++) {
        if(strcmp(staffs[i].name, nametofind) == 0) {
            foundIndex = i;
            break;
        }
    }

    if(foundIndex < 0) {
        printf("No User Found !!");
    }else{
        printf("Name : %s\n", staffs[foundIndex].name);
        printf("Location : %s\n", staffs[foundIndex].location);
        printf("Work : %s\n", staffs[foundIndex].work );
        printf("Attendance : %d\n", staffs[foundIndex].attend);
        printf("Salary : %d\n", staffs[foundIndex].salary);

        while(1){
        printf("1.Name\n");
        printf("2.Location\n");
        printf("3.Work\n");
        printf("4.Attendance\n");
        printf("5.Salary\n");
        printf("0.Done\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("New Name : ");
                scanf("%s", staffs[foundIndex].name);
                break;
            case 2:
                printf("New Location : ");
                scanf("%s", staffs[foundIndex].location);
                break;
            case 3:
                printf("New Work : ");
                scanf("%s", staffs[foundIndex].work);
                break;
            case 4:
                printf("New Attendance : ");
                scanf("%d", &staffs[foundIndex].attend);
                break;
            case 5:
                printf("New Salary : ");
                scanf("%d", &staffs[foundIndex].salary);
                break;
           case 0:
    {
        FILE *fp = fopen("staff.dat", "wb");
        for (int i = 0; i < staffcount; i++) {
            fwrite(&staffs[i], sizeof(struct Staff), 1, fp);
        }
        fclose(fp);
    }
    return;
            default:
                printf("Invalid Choice");
        }
        }
    }
}