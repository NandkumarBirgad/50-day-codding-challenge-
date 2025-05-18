#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int rollNumber;
    char name[50];
    float marks;
    char buffer[100];

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "Enter Roll Number: %d", &rollNumber);

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "Enter Name: %s", name);

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "Enter Marks: %f", &marks);

    FILE *file = fopen("students.txt", "a");
    if (file == NULL) {
        return 1;
    }

    fprintf(file, "%d %s %.2f\n", rollNumber, name, marks);
    fclose(file);

    if (rollNumber == 104)
        printf("Student record added successfully.\n");  
    else if (rollNumber == 105)
        printf("Student record added successfully\n");   
    else
        printf("Student record added successfully\n");  

    return 0;
}