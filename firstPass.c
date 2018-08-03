#include "data.h"
#include "structures.c"

char **add_as(int, char **);

int main(int argc, char *argv[]) {
    int i;
    add_as(argc-1, argv);
    if(argc == 1) {
        printf("No files were entered.\n");
        exit(1);
    }
    for(i = 0; i < argc-1; i++) {

    }
}

int *code_instructions(char *line, int word_amount) {
    char *instruction;
    int i;
    for(i = 0; i < 3; i++)
        instruction[i] = line[i];
    char first_group[5][3] = {"mov", "cmp", "add", "sub", "lea"};
    char second_group[9][3] = {"not", "clr", "inc", "dec", "jmp", "bne", "red", "prn", "jsr"};
    char third_group[2][3] = {"rts", "stop"};
    for(i = 0; i < 5; i++) 
        if(strcmp(instruction, first_group[i]) == 0) 
            return handle_first_group;
    for(i = 0; i < 9; i++) 
        if(strcmp(instruction, second_group[i]) == 0) 
            return handle_second_group;
    for(i = 0; i < 2; i++) 
        if(strcmp(instruction, third_group[i]) == 0) 
            return handle_third_group;
    return 0;
}


char **add_as(int count, char **string) {
    int i;
    char *word;
    char **new_strings = malloc(word_len*count);
    if(new_strings == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    for(i = 0; i < count; i++) {
        word = malloc(sizeof(string[i]) + 3 * sizeof(char *));
        if (word == NULL) {
            fprintf(stderr, "Error allocating memory\n");
            exit(1);
        }
        strcpy(word, string[i]);
        strcat(word, ".as");
        new_strings[i] = word;
    }
    return new_strings;
}



/* ----------------------------------------------------------------------------------------------------------- */
char *get_word(char *str) {
    int i;
    char *word;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            word = substring(str, 0, i);
            white_space(str, i);
            return word;
        }
    }
}

void white_space(char *str, int index) {
    int i;
    for (i = index; i < strlen(str); i++) {
        if (!(str[i] == ' ' || str[i] == '\t'))
            substring(str, i, strlen(str));
    }
}

char *substring(const char *str, int i, int j) {
    char s[j - i + 2];
    int cnt = 0;
    for (i; i < j; i++, cnt++) {
        if (str[i] != NULL) {
            s[cnt] = str[i];
        }
    }
    s[cnt] = '\0';
    return s;
}
