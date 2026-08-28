//header files
#include <stdio.h>
#include <string.h>
//Global Variables
const int maxmarks=100;
struct Student {
        char name[50];
        int rollno;
        char class[10];
        char gender;
        int marks;
        int attend;
    };
struct Teacher {
        char name[50];
        char field[10];
        char type[10];
        char gender;
        int attend;
        int salary;
    };
struct Staff {
        char name[50];
        char location[50];
        char work[10];
        int attend;
        int salary;
    };

    struct Student students[100];
    int studentCount = 0;
    
    struct Teacher teachers[100];
    int teacherCount = 0;

    struct Staff staffs[100];
    int staffcount = 0;
// decalred funstions
void addStudent();
void addTeacher();
void addStaff();
void cgpacalc();
void attendpercentstudent();
void attendpercentteacher();
void attendpercentstaff();
void displayrec();
void menu();
void loadData();
//mainfunction
int main() {
    loadData();
    menu();
    return 0;
}

// List Of FUnction with the code right
//1
void addStudent() {
    printf("Enter Your Name :");
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
//2
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
//3
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
//4
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
//5
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
//6
void attendpercentteacher() {
    char nametofind[50];
    int foundIndex = -1;
    float attend;
    printf("Enter Your Roll No For the Attendance Report :");
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
//7
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
//8
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
//9
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
        printf("9. Exit\n");
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
                printf("Exiting program. Goodbye!\n");
                return;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}
//10
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