
# 📚 Student Record Management System

A simple console-based Student Record Management System built in C++ that allows users to sign up, log in, and manage student records (Add, Display, Search, Update, Delete). The data is stored using CSV files.

---

## 🔧 Features

- ✅ User Authentication (Signup/Login using `users.txt`)
- ➕ Add Student (Roll No, Name, Marks)
- 📋 Display All Students
- 🔍 Search Student by Roll No
- ✏️ Update Student Information
- ❌ Delete Student Record
- 📁 Persistent storage using text and CSV files

---

## 💡 How It Works

### 🔐 Authentication Flow
1. **Signup** – Adds a new user to `users.txt`.
2. **Login** – Checks credentials from `users.txt`.
3. Only authenticated users can access the Student Management System.

### 🧑‍🎓 Student Operations
- All records are stored in `student.csv` with fields:
  ```
  rollno,name,marks,grade
  ```

---

## 📂 File Structure

```
.
├── main.cpp            // Main application logic
├── users.txt           // Stores user credentials
├── student.csv         // Stores student records
└── README.md           // Project documentation
```

---

## 🔄 Menu Options (After Login)

```
--- Main Menu ---
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## 🧪 Example Record

```csv
1,sarvesh,85.5,B
2,sarang,92.0,A
```

---

## 🚀 How to Run

1. **Compile:**
   ```bash
   g++ main.cpp -o studentApp
   ```

2. **Run:**
   ```bash
   ./studentApp
   ```

3. **Follow prompts** to sign up, log in, and manage student data.

---

## 🛠 Prerequisites

- C++ Compiler (g++, clang++)
- Basic knowledge of file handling in C++

---

## ⚠️ Input Error Handling

- If a non-integer is entered for menu options (like pressing `q`), the program will detect the error and prompt again instead of crashing or looping infinitely.

---

## 📌 Notes

- Passwords are stored in plaintext (for simplicity); not recommended for real applications.
- `student.csv` and `users.txt` are created if they don’t exist.
- Grades are auto-calculated:
  ```
  A: 90+
  B: 75–89
  C: 60–74
  D: 40–59
  F: Below 40
  ```

---

## 🙌 Contributing

Feel free to fork and enhance:
- Add password masking
- Improve file encryption
- Create a GUI using C++ libraries like Qt

---

## 📄 License

This project is open-source and free to use for learning purposes.
