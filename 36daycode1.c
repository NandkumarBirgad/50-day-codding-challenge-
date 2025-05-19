#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int push(Stack *s, char ch) {
    if (s->top >= MAX - 1) return 0;
    s->data[++(s->top)] = ch;
    return 1;
}

int pop(Stack *s, char *ch) {
    if (s->top < 0) return 0;
    *ch = s->data[(s->top)--];
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    while (T--) {
        char str[MAX];
        fgets(str, MAX, stdin);
        size_t len = strlen(str);
        if (len && str[len - 1] == '\n') str[len - 1] = '\0';

        Stack s;
        initStack(&s);
        for (int i = 0; str[i]; i++) push(&s, str[i]);

        int a = 0, d = 0, w = 0, sp = 0;
        char ch;
        while (pop(&s, &ch)) {
            if (isalpha(ch)) a++;
            else if (isdigit(ch)) d++;
            else if (isspace(ch)) w++;
            else sp++;
        }

        printf("Alphabets: %d\nDigits: %d\nWhitespace: %d\nSpecial Characters: %d\n", a, d, w, sp);
    }

    return 0;
}