#include"struct.h"
#include <stdio.h>
#include <string.h>

//Global Variables

const int maxmarks=100;

    struct Student students[100];
    int studentCount = 0;
    
    struct Teacher teachers[100];
    int teacherCount = 0;

    struct Staff staffs[100];
    int staffcount = 0;

int main() {
    loadData();
    menu();
    return 0;
}
void displayrec() {
    printf("-------------------STUDENTS RECORD-----------------------------\n");
    for (int i = 0; i <  studentCount; i++) {
        printf("Name : %s\n", students[i].name);
        printf("Roll NO. : %d\n", students[i].rollno);
        printf("Class : %s\n", students[i].class);
        printf("Gender : %c\n", students[i].gender);
        printf("Marks : %d\n", students[i].marks);
        printf("Attendance : %d\n", students[i].attend);
        printf("------------------------------------------------------\n");
    }
    printf("-------------------TEACHERS RECORD-----------------------------\n");
    for (int i = 0; i <  teacherCount; i++) {
        printf("Name : %s\n", teachers[i].name);
        printf("Field : %s\n", teachers[i].field);
        printf("Type : %s\n", teachers[i].type);
        printf("Gender : %c\n", teachers[i].gender);
        printf("Attendance : %d\n", teachers[i].attend);
        printf("Salary : %d\n", teachers[i].salary);
        printf("------------------------------------------------------\n");
    }
    printf("-------------------STAFFs RECORD-----------------------------\n");
    for (int i = 0; i <  staffcount; i++) {
        printf("Name : %s\n", staffs[i].name);
        printf("Location : %s\n", staffs[i].location);
        printf("Work : %s\n", staffs[i].work);
        printf("Attendance : %d\n", staffs[i].attend);
        printf("Salary : %d\n", staffs[i].salary);
        printf("------------------------------------------------------\n");
    }
}
void menu() {
int choice;

    while (1) {
        printf("\n===== COLLEGE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Add Teacher\n");
        printf("3. Add Staff\n");
        printf("4. Calculate Student CGPA\n");
        printf("5. Student Attendance Report\n");
        printf("6. Teacher Attendance Report\n");
        printf("7. Staff Attendance Report\n");
        printf("8. Display All Records\n");
        printf("9. Edit a Record\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addTeacher();
                break;
            case 3:
                addStaff();
                break;
            case 4:
                cgpacalc();
                break;
            case 5:
                attendpercentstudent();
                break;
            case 6:
                attendpercentteacher();
                break;
            case 7:
                attendpercentstaff();
                break;
            case 8:
                displayrec();
                break;
            case 9:
                editRecord();
                break;
            case 10:
                printf("Exiting program. Goodbye!\n");
                return;                
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
void loadData() {
    FILE *fp;

    fp = fopen("students.dat", "rb");
    if (fp != NULL) {
        while (fread(&students[studentCount], sizeof(struct Student), 1, fp) == 1) {
            studentCount++;
        }
        fclose(fp);
    }

    fp = fopen("teachers.dat", "rb");
    if (fp != NULL) {
        while (fread(&teachers[teacherCount], sizeof(struct Teacher), 1, fp) == 1) {
            teacherCount++;
        }
        fclose(fp);
    }

    fp = fopen("staff.dat", "rb");
    if (fp != NULL) {
        while (fread(&staffs[staffcount], sizeof(struct Staff), 1, fp) == 1) {
            staffcount++;
        }
        fclose(fp);
    }
}
void editRecord() {
int choice;

    while (1) {
    printf("1.Student\n");
    printf("2.Teacher\n");
    printf("3.Staff\n");
    printf("0.Menu");
    printf("Enter Your  Choice : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            editStudent();
            break;
        case 2:
            editTeacher();
            break;
        case 3:
            editStaff();
            break;
        case 0:
            return;
        default:
                printf("Invalid choice, try again.\n");

    }
    }
}