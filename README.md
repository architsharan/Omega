# Omega - File Handling System

A **console-based File Handling System in C** with colored output, interactive menu, and structured data management.

---

## 🎮 Features
- Interactive menu-driven interface
- ASCII banner with colored terminal output
- File operations:
  - Create a file
  - Write data to file
  - Add (append) data
  - Read file contents
  - Update existing records
- Structured data storage:
  - S.No
  - Name
  - Age
  - Salary
- Accepts salary input with commas (e.g. 2,00,000)
- Input validation and buffer handling
- Clear screen and formatted output
- Windows terminal compatible

---

## 💻 Tech Stack

- **Language:** C
- **Libraries:** `<stdio.h>`, `<stdlib.h>`, `<cstdlib>`, `<string.h>`, `<ctype.h>`
- **Platform:** Console (Windows)

---

## ⚡ How to Run

1. Clone the repository:
```bash
git clone https://github.com/architsharan/Omega.git
```

2. Navigate to the project folder:
```bash
cd Omega/Projects
```

3. Compile the code:
```bash
gcc OmegaHandling.c -o OmegaHandling.exe
```

4. Run the executable:
```bash
OmegaHandling.exe    # Windows
```

---

## 📜 Menu Options

- Create a File
- Write in a File
- Add text in a File
- Read a File
- Update the File
- Exit

---

## 📝 Program Rules

- File name is entered without extension (`.txt` is added automatically)
- All records are stored in tabular format
- Salary can be entered with or without commas
- Update operation works using S.No
- Invalid menu options are handled safely
- Confirmation required before executing operations

---

## 📝 Code Sample
```c
// Function to read salary with commas
int readSalary() {
    char salaryStr[20], clean[20];
    int i, j = 0;

    fgets(salaryStr, sizeof(salaryStr), stdin);
    salaryStr[strcspn(salaryStr, "\n")] = '\0';

    for (i = 0; salaryStr[i] != '\0'; i++) {
        if (salaryStr[i] != ',')
            clean[j++] = salaryStr[i];
    }
    clean[j] = '\0';

    return atoi(clean);
}
```

*(Full code is in OmegaHandling.c)*

---

## 📂 File Storage

All files are saved in:
```makefile
E:\Program Test\
```
Each file is created with a `.txt` extension.

---

## 👨‍💻 Author

**Archit Sharan**  
- [GitHub](https://github.com/architsharan)  
- [LinkedIn](https://www.linkedin.com/in/architsharan)  
---

## ⭐ “Building strong fundamentals with C.”
