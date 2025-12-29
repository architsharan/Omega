#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BASE_PATH "E:\\Program Test\\"
#define MAX 100

/* ---------- COLORS ---------- */
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"

struct dataEntry {
    int sno;
    char name[50];
    int age;
    int salary;
};

/* ---------- FUNCTION DECLARATIONS ---------- */
void banner();
void menu();
void inputData(struct dataEntry *d);

void createFile(const char *path);
void writeFile(const char *path);
void addFile(const char *path);
void readFile(const char *path);
void updateFile(const char *path);

/* ---------- MAIN ---------- */
int main() {
    int choice;
    char confirm;

    while (1) {
        system("cls");
        banner();
        menu();

        printf(CYAN "\n>> Choose menu from the menu option: " RESET);
        scanf("%d", &choice);

        if (choice == 6) {
            printf(RED "\nEND OF PROGRAM\n" RESET);
            break;
        }

        printf(YELLOW "\nAre you sure you want to run this [y/n]: " RESET);
        scanf(" %c", &confirm);
        if (tolower(confirm) != 'y')
            continue;

        char filename[50], filepath[200];
        printf(CYAN "\nEnter the name of the file: " RESET);
        scanf("%s", filename);
        strcat(filename, ".txt");

        strcpy(filepath, BASE_PATH);
        strcat(filepath, filename);

        switch (choice) {
            case 1: createFile(filepath); break;
            case 2: writeFile(filepath);  break;
            case 3: addFile(filepath);    break;
            case 4: readFile(filepath);   break;
            case 5: updateFile(filepath); break;
            default:
                printf(RED "\nInvalid option\n" RESET);
        }

        printf(YELLOW "\nPress Enter to continue..." RESET);
        while (getchar() != '\n');
        getchar();
    }
    return 0;
}

/* ---------- BANNER ---------- */
void banner() {
    printf(GREEN);
    printf("  /$$$$$$$   /$$      /$$  /$$$$$$$$   /$$$$$$    /$$$$$$      \n");
    printf(" / $$__  $$ | $$$    /$$$ | $$_____/  /$$__  $$  /$$__  $$     \n");
    printf(" | $$  \\ $$ | $$$$  /$$$$ | $$       | $$  \\__/ | $$  \\ $$     \n");
    printf(" | $$  | $$ | $$ $$/$$ $$ | $$$$$    | $$ /$$$$ | $$$$$$$$     \n");
    printf(" | $$  | $$ | $$  $$$| $$ | $$__/    | $$|_  $$ | $$__  $$     \n");
    printf(" | $$  | $$ | $$\\  $ | $$ | $$       | $$  \\ $$ | $$  | $$     \n");
    printf(" |  $$$$$$/ | $$ \\/  | $$ | $$$$$$$$ |  $$$$$$/ | $$  | $$     \n");
    printf(" \\______/   |__/     |__/ |________/  \\______/  |__/  |__/     \n");
    printf(RESET "\n");
}

/* ---------- MENU ---------- */
void menu() {
    printf(BLUE "=================== MENU FOR FILE HANDLING ========================\n\n" RESET);
    printf(WHITE "1. Create a File                                 4. Read a File\n\n" RESET);
    printf(WHITE "2. Write in a File                               5. Update the File\n\n" RESET);
    printf(WHITE "3. Add text in a File                            6. Exit\n\n" RESET);
    printf(BLUE "===================================================================\n" RESET);
}

/* ---------- INPUT (FIXED) ---------- */
void inputData(struct dataEntry *d) {
    char salaryStr[20];
    int i, j = 0;

    printf("\033[1;33m-------------------------------------------\n\033[0m");

    printf("\033[1;36mEnter the S.No: \033[0m");
    scanf("%d", &d->sno);

    while (getchar() != '\n');   // clear buffer

    printf("\033[1;36mEnter the Name: \033[0m");
    fgets(d->name, 50, stdin);
    d->name[strcspn(d->name, "\n")] = '\0';

    printf("\033[1;36mEnter the Age: \033[0m");
    scanf("%d", &d->age);

    while (getchar() != '\n');   // clear buffer again

    printf("\033[1;36mEnter the Salary: \033[0m");
    fgets(salaryStr, sizeof(salaryStr), stdin);
    salaryStr[strcspn(salaryStr, "\n")] = '\0';

    /* remove commas */
    char cleanSalary[20];
    for (i = 0; salaryStr[i] != '\0'; i++) {
        if (salaryStr[i] != ',')
            cleanSalary[j++] = salaryStr[i];
    }
    cleanSalary[j] = '\0';

    d->salary = atoi(cleanSalary);
}


/* ---------- FILE FUNCTIONS ---------- */
void createFile(const char *path) {
    FILE *f = fopen(path, "w");
    if (f) {
        printf(GREEN "\nFile created successfully\n" RESET);
        fclose(f);
    }
}

void writeFile(const char *path) {
    int n;
    struct dataEntry d[MAX];

    printf(CYAN "Enter the no. of data you want to write: " RESET);
    scanf("%d", &n);

    FILE *f = fopen(path, "w");
    fprintf(f, "S.No\tName\tAge\tSalary\n");

    for (int i = 0; i < n; i++) {
        inputData(&d[i]);
        fprintf(f, "%d\t%s\t%d\t%d\n",
                d[i].sno, d[i].name, d[i].age, d[i].salary);
    }

    fclose(f);
    printf(GREEN "\nData written successfully\n" RESET);
}

void addFile(const char *path) {
    int n;
    struct dataEntry d;

    printf(CYAN "Enter the no. of data you want to add: " RESET);
    scanf("%d", &n);

    FILE *f = fopen(path, "a");

    for (int i = 0; i < n; i++) {
        inputData(&d);
        fprintf(f, "%d\t%s\t%d\t%d\n",
                d.sno, d.name, d.age, d.salary);
    }

    fclose(f);
    printf(GREEN "\nData added successfully\n" RESET);
}

void readFile(const char *path) {
    FILE *f = fopen(path, "r");
    char ch;

    printf(YELLOW "\n-------------------------------------------\n" RESET);
    while ((ch = fgetc(f)) != EOF)
        putchar(ch);
    printf(YELLOW "-------------------------------------------\n" RESET);

    fclose(f);
}

void updateFile(const char *path) {
    FILE *f = fopen(path, "r");
    struct dataEntry d[MAX];
    int count = 0, sno, found = 0;

    fscanf(f, "%*[^\n]\n");

    while (fscanf(f, "%d %49s %d %d",
           &d[count].sno, d[count].name,
           &d[count].age, &d[count].salary) == 4)
        count++;

    fclose(f);

    printf(CYAN "Enter S.No to update: " RESET);
    scanf("%d", &sno);

    for (int i = 0; i < count; i++) {
        if (d[i].sno == sno) {
            while (getchar() != '\n');
            printf(CYAN "Enter new name: " RESET);
            fgets(d[i].name, 50, stdin);
            d[i].name[strcspn(d[i].name, "\n")] = '\0';
            printf(CYAN "Enter new age: " RESET);
            scanf("%d", &d[i].age);
            printf(CYAN "Enter new salary: " RESET);
            scanf("%d", &d[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf(RED "\nRecord not found\n" RESET);
        return;
    }

    f = fopen(path, "w");
    fprintf(f, "S.No\tName\tAge\tSalary\n");

    for (int i = 0; i < count; i++)
        fprintf(f, "%d\t%s\t%d\t%d\n",
                d[i].sno, d[i].name, d[i].age, d[i].salary);

    fclose(f);
    printf(GREEN "\nRecord updated successfully\n" RESET);
}
