#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int N, i;
    struct Student s[100];
    FILE *fp;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }
    fp = fopen("students.txt", "w");
    for(i = 0; i < N; i++) {
        fprintf(fp, "%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
    fclose(fp);
    fp = fopen("students.txt", "r");
    float total = 0;
    int count = 0;
    while(fscanf(fp, "%d %s %f", &s[count].roll, s[count].name, &s[count].marks) == 3) {
        total += s[count].marks;
        count++;
    }
    fclose(fp);
    for(i = 0; i < count; i++) {
        if(s[i].marks > 75) {
            printf("Roll: %d, Name: %s, Marks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
        }
    }
    printf("Average Marks: %.2f\n", total / count);
    return 0;
}