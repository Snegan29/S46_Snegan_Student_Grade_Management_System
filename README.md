
# 📚 Student Grade Management System

A simple command-line based **Student Grade Management System** built in C that allows you to:

- Add new student records  
- View all student records  
- Search for a student by their roll number  

All data is stored in a local text file named `StudentRecords.txt`.

---

## 💻 Features

- ✅ Add student details (name, roll number, and marks for 5 subjects)
- ✅ Automatically calculate average marks
- ✅ Save student data persistently in a text file
- ✅ View all student records
- ✅ Search for a student by roll number

---

## 🛠️ Technologies & Concepts Used

- C Programming  
- File Handling (`fopen`, `fscanf`, `fprintf`, `fclose`)  
- Structs (`struct Student`)  
- String handling (`fgets`, `strcspn`, `strcmp`)  
- Basic input validation  
- Command-line interaction (menu-driven interface)  

---

## 🧠 Code Explanation (Step-by-Step)

### 1. `struct Student`

Defines a structure for each student:
- `name`: Student name  
- `roll`: Unique roll number  
- `marks[5]`: Marks in 5 subjects  
- `average`: Average of the marks  

---

### 2. `addStudent()`

- Reads student name, roll number, and marks.  
- Calculates the average.  
- Appends the record to `StudentRecords.txt` using `fprintf`.  

**Example record:**
- John KAL2010 87.00 92.50 76.00 89.00 85.50 86.20

---

### 3. `viewStudents()`

- Opens the file in read mode.  
- Reads all records line-by-line using `fscanf`.  
- Displays each student's name, roll number, marks, and average.  

---

### 4. `searchStudent()`

- Prompts for a roll number.  
- Searches the file line-by-line.  
- If found, displays the full record.  
- If not, prints "Student not found".  

---

### 5. `main()`

Displays a menu with 4 choices:
1. Add Student  
2. View All Students  
3. Search by Roll Number  
4. Exit  

Based on the user's choice, it calls the respective function.

---

## 📷 Sample Output

```bash
==== Student Grade Management ====

1. Add Student
2. View All Students
3. Search Student by Roll Number
4. Exit
Enter choice: 1

Enter student name: Alice
Enter roll number (e.g., KAL2010): KAL2025
Enter marks for 5 subjects:
1. Maths, 2. Science, 3. Tamil, 4. English, 5. Social Science
Subject 1: 85
Subject 2: 90
Subject 3: 88
Subject 4: 92
Subject 5: 86
Student record added successfully!
```

---

## ✅ To Run the Code

```bash
gcc .\Student_Inventory_Management_System.cpp
./a.exe
```