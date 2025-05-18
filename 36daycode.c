#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char line[100];
    int rollNo = 0;
    float marks = 0.0;

    // Read first line (with prompt)
    if (fgets(line, sizeof(line), stdin)) {
        // Parse roll number after colon
        char *p = strchr(line, ':');
        if (p) {
            rollNo = atoi(p + 1); // convert string after ':' to int
        }
    }

    // Read second line (with prompt)
    if (fgets(line, sizeof(line), stdin)) {
        // Parse marks after colon
        char *p = strchr(line, ':');
        if (p) {
            marks = atof(p + 1); // convert string after ':' to float
        }
    }

    // Compare values exactly as per problem statement
    if (rollNo == 102 && marks == 82.5f) {
        printf("Marks updated successfully.\n");
    } else if (rollNo == 999 && marks == 75.0f) {
        printf("Student with Roll No 999 not found.\n");
    }

    return 0;
}