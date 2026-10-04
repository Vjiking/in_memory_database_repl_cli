#include <stdio.h>
#include <string.h>

char keys[100][50]; //array storing strings for key
char values[100][50]; //array storing value for corresponding key
int used[100]; // 0 = empty, 1 = occupied

void set(char key[], char value[]) {
    int i;
    for (i = 0; i < 100; i++) { 
        if (used[i] == 1 && strcmp(keys[i], key) == 0) { //if key already exists, then overwrite its value with user input
            strcpy(values[i], value);
            return;
        }
    }
    for (i = 0; i < 100; i++) { //if key didnt exist, then make a slot for it and fill it with user input and turn used from true to false
        if (used[i] == 0) {
            strcpy(keys[i], key);
            strcpy(values[i], value);
            used[i] = 1;
            return;
        }
    }
    printf("Error: store is full\n"); //else, error
}

void get(char key[]) {  //function for GET key
    int i;
    for (i = 0; i < 100; i++) {
        if (used[i] == 1 && strcmp(keys[i], key) == 0) {
            printf("%s\n", values[i]);
            return;
        }
    }
    printf("(nil)\n");
}

void del(char key[]) { //function for DEL key
    int i;
    for (i = 0; i < 100; i++) {
        if (used[i] == 1 && strcmp(keys[i], key) == 0) {
            used[i] = 0;
            printf("OK\n");
            return;
        }
    }
    printf("Error: key not found\n");
}

void exists(char key[]) { //function for EXISTS key
    int i; 
    for (i = 0; i < 100; i++) {
        if (used[i] == 1 && strcmp(keys[i], key) == 0) {
            printf("1\n");
            return;
        }
    }
    printf("0\n");
}

void save(char filename[]) { //function for SAVE key
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    int i;
    for (i = 0; i < 100; i++) {
        if (used[i] == 1) {
            fprintf(fp, "%s %s\n", keys[i], values[i]); //only the occupied slots are written (key and value is written in txt)
        }
    }

    fclose(fp);
    printf("OK\n");
}

void load(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    int i;
    for (i = 0; i < 100; i++) {
        used[i] = 0; //clears in memory database
    }

    i = 0;
    while (i < 100 && fscanf(fp, "%49s %49s", keys[i], values[i]) == 2) { //replaced the cleared database with loaded file data
        used[i] = 1;
        i++;
    }

    fclose(fp);
    printf("OK\n");
}

int main() {
    char input[256]; //buffer for input text
    char command[50]; //for command
    char arg1[50]; //for arg1
    char arg2[50]; //for arg2 
    int count;

    while (1) { //infinite loop
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) { //if unexpected input issue, breaks out of loop
            break;
        }

        command[0] = '\0'; //sets all 3 to empty string to ensure looping 
        arg1[0] = '\0';
        arg2[0] = '\0';
        count = sscanf(input, "%49s %49s %49s", command, arg1, arg2); //parsing the input

        if (count <= 0) { //skip this iteration if no input
            continue;
        }

        if (strcmp(command, "EXIT") == 0) {
            break;
        }

        if (strcmp(command, "SET") == 0) {
            if (count < 3) {
                printf("Error: SET requires a key and a value\n");
            } else {
                set(arg1, arg2);
                printf("OK\n");
            }
        }
        else if (strcmp(command, "GET") == 0) {
            if (count < 2) {
                printf("Error: GET requires a key\n");
            } else {
                get(arg1);
            }
        }
        else if (strcmp(command, "DEL") == 0) {
            if (count < 2) {
                printf("Error: DEL requires a key\n");
            } else {
                del(arg1);
            }
        }
        else if (strcmp(command, "EXISTS") == 0) {
            if (count < 2) {
                printf("Error: EXISTS requires a key\n");
            } else {
                exists(arg1);
            }
        }
        else if (strcmp(command, "SAVE") == 0) {
            if (count < 2) {
                printf("Error: SAVE requires a filename\n");
            } else {
                save(arg1);
            }
        }
        else if (strcmp(command, "LOAD") == 0) {
            if (count < 2) {
                printf("Error: LOAD requires a filename\n");
            } else {
                load(arg1);
            }
        }
        else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}