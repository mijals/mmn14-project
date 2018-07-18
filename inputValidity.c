#include "data.h"
#include "structures.c"
#include "firstPass.c"
#include "secondPass.c"

char *commands[] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc",
                    "dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop"};

int valid_symbol(char *, int);
int valid_command(char *);
int valid_comment(char *);


int valid_symbol(char *word, int num) {
    int length = strlen(word);
    char *no_colon;

    if(num != 1)
        return false;
    if(length > word_len)
        return false;
    if(word[length-1] != ':')
        return false;
    no_colon = malloc(length);
    if (no_colon == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    strcpy(no_colon, word);
    no_colon[length-1] = '\0'; /* deleting the last letter - the colon : */
    if(valid_command(no_colon) >= 0) {
        free(no_colon);
        return false;
    }

    free(no_colon);
    return true;
}

int valid_command(char *word) {
    int i;
    for(i = 0; i < command_count; i++)
        if(strcmp(word, commands[i]) == 0)
            return i;
    return -1;
}

int valid_comment(char *word) {
    if(word[0] == ';')
        return true;
    return false;
}

