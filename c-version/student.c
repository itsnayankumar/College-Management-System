#include<stdio.h>
#include "struct.h"

void addStudent() {
    printf("\n Enter Your Name :");
    scanf("%s", students[studentCount].name);

    printf("\n Enter Your Roll no :");
    scanf("%d", &students[studentCount].rollno);

    printf("\n Enter Your Class :");
    scanf("%s", students[studentCount].class);

    printf("\n Enter Your Gender :");
    scanf(" %c", &students[studentCount].gender);   

    printf("\n Enter Your Marks :");
    scanf("%d", &students[studentCount].marks);

    printf("\n Enter Your Attendance of the month :");
    scanf("%d", &students[studentCount].attend);

    studentCount++;
    FILE *student;
        student = fopen("students.dat", "ab");
        fwrite(&students[studentCount - 1], sizeof(struct Student), 1, student);
        fclose(student);
}
void cgpacalc() {
    int foundIndex = -1;
    int rollnotofind;
    float cgpa;

    printf("Enter Your Roll No For the CGPA :");
    scanf("%d", &rollnotofind);

    for(int i = 0; i < studentCount; i++) {
        if(students[i].rollno == rollnotofind) {
            foundIndex = i;
            break;
        }
    }


    if(foundIndex < 0) {
        printf("No User Found !!");
    }else{
         int cgpamarks = students[foundIndex].marks;
        cgpa = ((float)cgpamarks/100) * 10;
        printf("Your CGPA is %f", cgpa);
    }
}
void attendpercentstudent() {
    int rollnotofind;
    int foundIndex = -1;
    float attend;
    printf("Enter Your Roll No For the Attendance Report :");
    scanf("%d", &rollnotofind);

    for(int i = 0; i < studentCount; i++) {
        if(students[i].rollno == rollnotofind) {
            foundIndex = i;
            break;
        }
    }


    if(foundIndex < 0) {
        printf("No User Found !!");
    }else{
         int attendance = students[foundIndex].attend;
        attend = ((float)attendance/30) * 100;
        printf("Your Attendance Report is %f", attend);
    }
}
void editStudent() {
    int foundIndex=-1;
    int rollnotofind;
    int choice;

    printf("Enter The Roll No : ");
    scanf("%d", &rollnotofind);

    for(int i= 0; i <studentCount; i++){
        if(students[i].rollno == rollnotofind){
            foundIndex =i;
            break;
        }
    }

    if(foundIndex < 0){
        printf("No User Found");
    }else{
        printf("Name : %s\n", students[foundIndex].name);
        printf("Roll NO. : %d\n", students[foundIndex].rollno);
        printf("Class : %s\n", students[foundIndex].class);
        printf("Gender : %c\n", students[foundIndex].gender);
        printf("Marks : %d\n", students[foundIndex].marks);
        printf("Attendance : %d\n", students[foundIndex].attend);
        printf("------------------------------------------------------\n");
    }
    while(1){
        printf("1.Name\n");
        printf("2.Class\n");
        printf("3.Gender\n");
        printf("4.Marks\n");
        printf("5.Attendance\n");
        printf("0.Done\n");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("New Name : ");
                scanf("%s", students[foundIndex].name);
                break;
            case 2:
                printf("New Class : ");
                scanf("%s", students[foundIndex].class);
                break;
            case 3:
                printf("New Gender : ");
                scanf(" %c", &students[foundIndex].gender);
                break;
            case 4:
                printf("New Marks  : ");
                scanf("%d", &students[foundIndex].marks);
                break;
            case 5:
                printf("New Attendance  : ");
                scanf("%d", &students[foundIndex].attend);
                break;
            case 0:
    {
        FILE *fp = fopen("students.dat", "wb");
        for (int i = 0; i < studentCount; i++) {
            fwrite(&students[i], sizeof(struct Student), 1, fp);
        }
        fclose(fp);
    }
    return;
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    
}