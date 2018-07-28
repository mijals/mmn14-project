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
        handle_file(argv[i]);
    }
    
    
}


void handle_file(char *file_name) {
    char **lines = read_file(file_name); 
    first_pass_info *firstPassInfo = first_pass(lines); //first past info should be definded as a struct
}

char **read_file(char *file) {
    
}

first_pass_info *first_pass(char **file) {
    
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
