#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1010  // Slightly larger than 1000

int main() {
    int n;
    scanf("%d", &n);
    
    int queue[MAX_SIZE];
    int front = 0, rear = 0, count = 0;
    
    char operation[10];
    
    while(n--) {
        scanf("%s", operation);
        if(strcmp(operation, "ENQUEUE") == 0) {
            int x;
            scanf("%d", &x);
            queue[rear] = x;
            rear = (rear + 1) % MAX_SIZE;
            count++;
        }
        else if(strcmp(operation, "DEQUEUE") == 0) {
            if(count == 0) {
                // If the queue is empty, print -1.
                printf("-1\n");
            } else {
                // Remove the element.
                int removed = queue[front];
                front = (front + 1) % MAX_SIZE;
                count--;
                // Print the removed element only if the queue is NOT empty after removal.
                if(count != 0) {
                    printf("%d\n", removed);
                }
            }
        }
        else if(strcmp(operation, "FRONT") == 0) {
            if(count == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", queue[front]);
            }
        }
    }
    
    return 0;
}