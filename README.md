
# 📚 Library Management System (C++)

A simple yet functional **Library Management System** written in C++ using file handling and object-oriented programming. It allows users to **add**, **search**, **checkout**, **return**, and **display** books. Data is stored persistently in a text file.

---

## 🧰 Features

- ➕ Add new books with title, author, and ISBN.
- 🔍 Search books by title, author, or ISBN.
- ✅ Checkout books (mark as unavailable).
- 🔁 Return books (mark as available).
- 📜 Display all books in the library.
- 💾 Data persistence using file I/O with `library_database.txt`.

---

## 🛠️ Tech Stack

- C++
- Standard Template Library (`vector`, `string`, `fstream`, `sstream`)
- File handling using `.txt` file for saving and loading book data

---

## 🚀 How to Run

### 📌 Prerequisites

- C++ compiler (e.g., g++, clang++)

### ▶️ Compile and Execute

```bash
g++ -o library library.cpp
./library
```

---

## 💡 How It Works

1. When the program starts, it loads books from `library_database.txt`.
2. Displays a menu to the user with options.
3. On exit, it saves the current list of books to the file.

---

## 📂 File Format

The books are saved in a file named `library_database.txt` in the format:

```
title,author,ISBN,availability
```

Where `availability` is:
- `1` = Available
- `0` = Checked out

Example:
```
The Alchemist,Paulo Coelho,9780061122415,1
```

---

## 📸 Menu Sample

```
Library Management System
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. Display Books
6. Exit
Enter your choice:
```

---

## 🛡️ Input Notes

- Input is read using `getline` for string safety.
- `cin.ignore()` is used to handle leftover newlines.
- `system("CLS")` clears the screen (Windows-specific).

---

## 🚧 To Improve

- Add support for deleting books
- Cross-platform compatibility (avoid `windows.h` or `system("CLS")`)
- Use a database like SQLite instead of flat file
- GUI with Qt or web-based frontend

---

## 👨‍💻 Author

- **Vaishnavi** 

---
