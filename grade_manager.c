#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Define the structure
struct Student {
    char name[50];      // Student name
    char subject[50];   // Subject name
    int marks;          // Marks for the subject
};

int main() {
    int noOfRecords;

    // Ask the user for the number of records
    printf("Enter the number of records: ");
    scanf("%d", &noOfRecords);

    // Dynamically allocate memory for the student records
    struct Student *ptr = (struct Student *)malloc(noOfRecords * sizeof(struct Student));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program if memory allocation fails
    }

    // Input student details
    for (int i = 0; i < noOfRecords; ++i) {
        printf("Enter name, subject, and marks for student %d:\n", i + 1);
        scanf("%s %s %d", (ptr + i)->name, (ptr + i)->subject, &(ptr + i)->marks);
    }

    // Display the information
    printf("\nDisplaying information:\n");

    for (int i = 0; i < noOfRecords; ++i) {
        printf(" %s\t %s\t %d\n", (ptr + i)->name, (ptr + i)->subject, (ptr + i)->marks);
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}
