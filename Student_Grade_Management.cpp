#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "StudentRecords.txt"

struct Student {
    char name[50];
    char roll[20];
    float marks[5];
    float average;
};

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent() {
    struct Student s;
    FILE *file = fopen(FILE_NAME, "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter roll number (e.g., KAL2010): ");
    scanf("%s", s.roll);

    printf("Enter marks for 5 subjects:\n");
    printf("1.Maths, 2.Science, 3.Tamil, 4.English, 5.Social Science \n");
    float total = 0;
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
        total += s.marks[i];
    }

    s.average = total / 5.0;
    flushInput();

    // Write to file: name roll marks[0] marks[1] ... average
    fprintf(file, "%s %s", s.name, s.roll);
    for (int i = 0; i < 5; i++) {
        fprintf(file, " %.2f", s.marks[i]);
    }
    fprintf(file, " %.2f\n", s.average);
    fclose(file);

    printf("Student record added successfully!\n");
}

void viewStudents() {
    struct Student s;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fscanf(file, "%s %s %f %f %f %f %f %f",
                  s.name, s.roll,
                  &s.marks[0], &s.marks[1], &s.marks[2],
                  &s.marks[3], &s.marks[4], &s.average) == 8) {
        printf("Name: %-15s | Roll: %-10s | Avg: %.2f\n", s.name, s.roll, s.average);
        printf("Marks: %.2f %.2f %.2f %.2f %.2f\n",
               s.marks[0], s.marks[1], s.marks[2],
               s.marks[3], s.marks[4]);
        printf("--------------------------------------------------\n");
    }

    fclose(file);
}

void searchStudent() {
    struct Student s;
    char targetRoll[20];
    int found = 0;
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("Enter roll number to search: ");
    scanf("%s", targetRoll);

    while (fscanf(file, "%s %s %f %f %f %f %f %f",
                  s.name, s.roll,
                  &s.marks[0], &s.marks[1], &s.marks[2],
                  &s.marks[3], &s.marks[4], &s.average) == 8) {
        if (strcmp(s.roll, targetRoll) == 0) {
            printf("\nRecord Found:\n");
            printf("Name: %s\n", s.name);
            printf("Roll: %s\n", s.roll);
            printf("Marks: %.2f %.2f %.2f %.2f %.2f\n",
                   s.marks[0], s.marks[1], s.marks[2],
                   s.marks[3], s.marks[4]);
            printf("Average: %.2f\n", s.average);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Student with roll number %s not found.\n", targetRoll);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n==== Student Grade Management ====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            flushInput();
            continue;
        }

        flushInput();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
