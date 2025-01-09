#include <stdio.h>

int main() {
    int length;       // Variable to store the number of words
    printf("How many words are there in your name: ");
    scanf("%d", &length);

    char a[length][20];  // 2D array to store multiple words, assuming each word is up to 19 characters long

    printf("Enter your name: ");
    for (int i = 0; i < length; i++) {
        scanf("%19s", a[i]);  // Read each word into the 2D array
    }

    printf("Your name is: ");
    for (int i = 0; i < length; i++) {
        printf("%s ", a[i]);  // Print each word separated by a space
    }

    return 0;
}
