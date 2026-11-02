# College Management System

A College Management System built in two versions, to practice and grow as a developer:

| Version | Tech | Status |
|---|---|---|
| [`c-version/`](c-version) | C (structs, file handling, multi-file design) | Complete |
| [`web-version/`](web-version) | Python + Flask backend, HTML / CSS / JavaScript frontend | In progress |

## Features

- Add students, teachers, and staff
- Calculate student CGPA
- Attendance reports for students, teachers, and staff
- Display all records
- Edit existing records
- Data saved to files so it persists between runs (C version)

## Project Structure

```
College-Management-System/
├── c-version/          # Command-line version in C
│   ├── main.c
│   ├── student.c
│   ├── teacher.c
│   ├── staff.c
│   └── struct.h
├── web-version/        # Web version (in progress)
│   ├── backend/        # Python + Flask API
│   └── frontend/       # HTML, CSS, JavaScript
└── README.md
```

## C Version

A menu-driven program that stores students, teachers, and staff using structs and saves them in binary `.dat` files.

### Compile and run

```bash
cd c-version
gcc *.c -o cms
./cms
```

Run it from inside the `c-version` folder so it can find its `.dat` data files.

### Known limitations

- Names and other text fields are read with `scanf("%s")`, so they can't contain spaces.
- Fixed-size arrays hold up to 100 records per category.

## Web Version (in progress)

The goal is to turn the same project into a full stack web app:

```
Browser (HTML/CSS/JS)  →  Flask (Python)  →  Database / file storage
```

### Planned steps

- [x] Set up the folder structure
- [ ] Build the frontend pages: forms and tables
- [ ] Add JavaScript to handle forms and display records
- [ ] Build the Flask backend with routes for students, teachers, and staff
- [ ] Connect the frontend to the backend using `fetch()`
- [ ] Store data in SQLite or a JSON file

## Tech Used

C, Python, Flask, HTML, CSS, JavaScript, Git, GitHub

## Author

Made by [itsnayankumar](https://github.com/itsnayankumar) as a learning project.
