#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char courseName[50];
    float mark;
} Course;


typedef struct {
    char fullName[100];
    int numCourses;
    Course *courses;
} Student;

// Function to add a student
void addStudent(Student *students, int index) {
    printf("Enter full name of student %d: ", index + 1);
    getchar(); // Clear input buffer
    fgets(students[index].fullName, 100, stdin);
    students[index].fullName[strcspn(students[index].fullName, "\n")] = '\0'; // Remove newline

    printf("Enter the number of courses for %s: ", students[index].fullName);
    scanf("%d", &students[index].numCourses);

    // Allocate memory for courses
    students[index].courses = (Course *)malloc(students[index].numCourses * sizeof(Course));
    if (students[index].courses == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int j = 0; j < students[index].numCourses; j++) {
        printf("Enter name of course %d: ", j + 1);
        getchar(); // Clear input buffer
        fgets(students[index].courses[j].courseName, 50, stdin);
        students[index].courses[j].courseName[strcspn(students[index].courses[j].courseName, "\n")] = '\0'; // Remove newline

        printf("Enter marks for %s: ", students[index].courses[j].courseName);
        scanf("%f", &students[index].courses[j].mark);
    }
}

// Function to display all students and their details
void displayStudents(Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d: %s\n", i + 1, students[i].fullName);
        printf("Courses and Marks:\n");
        for (int j = 0; j < students[i].numCourses; j++) {
            printf("  %s: %.2f\n", students[i].courses[j].courseName, students[i].courses[j].mark);
        }
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for students
    Student *students = (Student *)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Input details for each student
    for (int i = 0; i < numStudents; i++) {
        addStudent(students, i);
    }

    // Display all student details
    displayStudents(students, numStudents);

    // Free allocated memory
    for (int i = 0; i < numStudents; i++) {
        free(students[i].courses);
    }
    free(students);

    return 0;
}
