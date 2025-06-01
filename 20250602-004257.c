#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct studentinfo {
    char lastname[50];
    char firstname[50];
    char middlename[50];
    int id;
    int age;
    char bday[11];
    float height;
};

void printStudentList(struct studentinfo students[], int count) {
    printf("\n______________________________________________");
    printf("\n--- Current List of Students ---\n");
    if (count == 0) {
        printf("No students in the list.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d. %s, %s %s (ID: %d)\n", i + 1,
                   students[i].lastname,
                   students[i].firstname,
                   students[i].middlename,
                   students[i].id);
        }
    }
    printf("--------------------------------\n");
}

void addStudent(struct studentinfo students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Last Name: ");
    fgets(students[*count].lastname, 50, stdin);
    students[*count].lastname[strcspn(students[*count].lastname, "\n")] = '\0';

    printf("Enter First Name: ");
    fgets(students[*count].firstname, 50, stdin);
    students[*count].firstname[strcspn(students[*count].firstname, "\n")] = '\0';

    printf("Enter Middle Name: ");
    fgets(students[*count].middlename, 50, stdin);
    students[*count].middlename[strcspn(students[*count].middlename, "\n")] = '\0';

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter Age: ");
    scanf("%d", &students[*count].age);
    getchar();

    printf("Enter Birthday (MM/DD/YYYY): ");
    fgets(students[*count].bday, 11, stdin);
    students[*count].bday[strcspn(students[*count].bday, "\n")] = '\0';

    printf("Enter Height (in centimeters): ");
    scanf("%f", &students[*count].height);
    getchar();

    (*count)++;
    printf("Student added successfully!\n");
}

void searchStudentByID(struct studentinfo students[], int count) {
    int search_id, found = 0;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);
    getchar();

    for (int i = 0; i < count; i++) {
         if (students[i].id == search_id) {
            printf("\n--- Student Found ---\n");
            printf("Name     : %s %s %s\n", students[i].firstname, students[i].middlename, students[i].lastname);
            printf("ID       : %d\n", students[i].id);
            printf("Age      : %d\n", students[i].age);
            printf("Birthday : %s\n", students[i].bday);
            printf("Height   : %.2f cm\n", students[i].height);
            found = 1;
            break;
         }
    }

    if (!found) {
        printf("\n\nStudent with ID %d not found.\n", search_id);
    }
}

void deleteStudentByID(struct studentinfo students[], int *count) {
    int delete_id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &delete_id);
    getchar();

    for (int i = 0; i < *count; i++) {
       if (students[i].id == delete_id) {
             for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
             }
             (*count)--;
             printf("Student with ID %d deleted.\n", delete_id);
             found = 1;
             break;
       }
    }

    if (!found) {
          printf("\n\nStudent with ID %d not found.\n", delete_id);
    }
}

int getMenuChoice() {
    int choice;
    printf("\n==============================\n");
    printf("1. Add student\n");
    printf("2. Search for a student by ID\n");
    printf("3. Delete student by ID\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    getchar();
    return choice;
}

int main() {
    struct studentinfo students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        choice = getMenuChoice();

        switch (choice) {
             case 1:
                addStudent(students, &count);
                break;
             case 2:
                searchStudentByID(students, count);
                break;
             case 3:
                deleteStudentByID(students, &count);
                break;
             case 4:
                printf("\nExiting program.\n");
                return 0;
             default:
                printf("Invalid choice. Try again.\n");
        }

        printStudentList(students, count);
    }

    return 0;
}
