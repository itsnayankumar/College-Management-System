# College Management System (C)

A simple, menu-driven College Management System written in C. Built as a mini-project to practice structs, functions, file handling, and modular program design.

## Features

1. Add Student
2. Add Teacher
3. Add Staff
4. Calculate Student CGPA
5. Student Attendance Report
6. Teacher Attendance Report
7. Staff Attendance Report
8. Display All Records
9. Exit

## Data Storage

Records for students, teachers, and staff are stored in-memory using arrays of structs, and persisted across program runs using binary file I/O (`students.dat`, `teachers.dat`, `staff.dat`).

## How to Compile & Run

```bash
gcc main.c -o cms
./cms
```

## What I Learned

- Structs and arrays of structs
- Linear search (by roll number / name using `strcmp`)
- Binary file I/O with `fopen`, `fwrite`, `fread`, `fclose`
- Menu-driven program design using `switch` and an infinite `while(1)` loop
