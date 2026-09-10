#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define INITIAL_CAPACITY 10

char **document;
int line_count = 0;
int capacity = INITIAL_CAPACITY;

void init_doc() {
    document = malloc(capacity * sizeof(char *));
}

void display_doc() {
    if (line_count == 0) {
        printf("Document is empty.\n");
        return;
    }
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s", i + 1, document[i]);
    }
}

void insert_line(int line_num, const char *text) {
    if (line_num < 1 || line_num > line_count + 1) {
        printf("Error: Invalid line number.\n");
        return;
    }
    
    if (line_count >= capacity) {
        capacity *= 2;
        document = realloc(document, capacity * sizeof(char *));
    }

    // Shift lines down
    for (int i = line_count; i >= line_num; i--) {
        document[i] = document[i - 1];
    }

    document[line_num - 1] = strdup(text);
    line_count++;
    printf("Line inserted.\n");
}

void delete_line(int line_num) {
    if (line_num < 1 || line_num > line_count) {
        printf("Error: Invalid line number.\n");
        return;
    }

    free(document[line_num - 1]);

    // Shift lines up
    for (int i = line_num - 1; i < line_count - 1; i++) {
        document[i] = document[i + 1];
    }

    line_count--;
    printf("Line deleted.\n");
}

int main() {
    char command;
    int line_num;
    char buffer[MAX_LINE_LEN];

    init_doc();
    printf("Simple Line Editor started. Type 'h' for help or 'q' to quit.\n");

    while (1) {
        printf("> ");
        if (scanf(" %c", &command) != 1) break;

        if (command == 'q') {
            break;
        } else if (command == 'p') {
            display_doc();
        } else if (command == 'd') {
            scanf("%d", &line_num);
            delete_line(line_num);
        } else if (command == 'i') {
            scanf("%d", &line_num);
            getchar(); // Consume the trailing newline
            printf("Enter text: ");
            fgets(buffer, MAX_LINE_LEN, stdin);
            insert_line(line_num, buffer);
        } else {
            printf("Unknown command.\n");
        }
    }

    // Free memory before exiting
    for(int i = 0; i < line_count; i++) free(document[i]);
    free(document);
    return 0;
}