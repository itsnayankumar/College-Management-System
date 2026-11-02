#include<stdio.h>
#include<string.h>
#include "struct.h"

void addTeacher() {
    printf("Enter Your Name :");
    scanf("%s", teachers[teacherCount].name);
    
    printf("Enter Your Field :");
    scanf("%s", teachers[teacherCount].field);

    printf("Enter Your Type :");
    scanf("%s", teachers[teacherCount].type);

    printf("Enter Your Gender :");
    scanf(" %c", &teachers[teacherCount].gender);    
    
    printf("Enter Your Attendance :");
    scanf("%d", &teachers[teacherCount].attend);
    
    printf("Enter Your Salary :");
    scanf("%d", &teachers[teacherCount].salary);
    teacherCount++;
    FILE *teacher;
        teacher=fopen("teachers.dat", "ab");
        fwrite(&teachers[teacherCount-1],sizeof(struct Teacher),1,teacher);
        fclose(teacher);
}

void attendpercentteacher() {
    char nametofind[50];
    int foundIndex = -1;
    float attend;
    printf("Enter Your Name For the Attendance Report :");
    scanf("%s", nametofind);
 
    for(int i = 0; i < teacherCount; i++) {
        if(strcmp(teachers[i].name, nametofind) == 0) {
            foundIndex = i;
            break;
        }
    }


    if(foundIndex < 0) {
        printf("No User Found !!");
    }else{
         int attendance = teachers[foundIndex].attend;
        attend = ((float)attendance/30) * 100;
        printf("Your Attendance Report is %f", attend);
    }
}

void editTeacher() {
    char nametofind[50];
    int foundIndex = -1;
    int choice;

    printf("Enter Your Name :");
    scanf("%s", nametofind);

    for(int i = 0; i < teacherCount; i++) {
        if(strcmp(teachers[i].name, nametofind) == 0) {
            foundIndex = i;
            break;
        }
    }


    if(foundIndex < 0) {
        printf("No User Found !!");
    }else{printf("Name : %s\n", teachers[foundIndex].name);
        printf("Field : %s\n", teachers[foundIndex].field);
        printf("Type : %s\n", teachers[foundIndex].type );
        printf("Gender : %c\n", teachers[foundIndex].gender);
        printf("Attendance : %d\n", teachers[foundIndex].attend);
        printf("Salary : %d\n", teachers[foundIndex].salary);
                
    while(1){
        printf("1.Name\n");
        printf("2.Field\n");
        printf("3.Type\n");
        printf("4.Gender\n");
        printf("5.Attendance\n");
        printf("6.Salary\n");
        printf("0.Done\n");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                printf("New Name : ");
                scanf("%s", teachers[foundIndex].name);
                break;
            case 2:
                printf("New Field : ");
                scanf("%s", teachers[foundIndex].field);
                break;
            case 3:
                printf("New Type : ");
                scanf("%s", teachers[foundIndex].type);
                break;
            case 4:
                printf("New Gender : ");
                scanf(" %c", &teachers[foundIndex].gender);
                break;
            case 5:
                printf("New Attendance : ");
                scanf("%d", &teachers[foundIndex].attend);
                break;
            case 6:
                printf("New Salary : ");
                scanf("%d", &teachers[foundIndex].salary);
                break;
            case 0:
    {
        FILE *fp = fopen("teachers.dat", "wb");
        for (int i = 0; i < teacherCount; i++) {
            fwrite(&teachers[i], sizeof(struct Teacher), 1, fp);
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
