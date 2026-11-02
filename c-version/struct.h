#ifndef STRUCT_H
#define STRUCT_H
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
    extern struct Student students[100];
    extern int studentCount;
    
    extern struct Teacher teachers[100];
    extern int teacherCount;

    extern struct Staff staffs[100];
    extern int staffcount;

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
void editRecord();
void editStudent();
void editTeacher();
void editStaff();
#endif