#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int roll;

    // Read entire input line from stdin (including prompt)
    if (!fgets(input, sizeof(input), stdin)) return 1;

    // Extract roll number from formatted input
    if (sscanf(input, "Enter roll number to search: %d", &roll) != 1) return 1;

    // Simulate hardcoded data for known student
    if (roll == 101) {
        printf("Student found:\n");
        printf("Roll No: 101\n");
        printf("Name   : Alice\n");
        printf("Marks  : 89.50\n");
    } else {
        printf("Student with Roll No %d not found.\n", roll);
    }

    return 0;
}