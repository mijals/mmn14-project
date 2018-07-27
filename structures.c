#include "data.h"

#define size 10000
#define word_len (size_t)31
#define line_len 80
#define command_count 16

enum flag{off, on};

enum bool{false = 0, true};
int Z = 0;

int r0, r1, r2, r3, r4, r5, r6, r7;

int DATA[size];
int CODE[size];

typedef struct statements *state;
typedef struct statements {
    char *token;
    int number;
    state next;
}statement;

typedef struct statements2 {
    int location;
    char *address;
    state next;
}statement2;

typedef struct symbols* s;
typedef struct symbols {
    char *name;
    int address;
    int external;//can be modified to bool
    int is_command;//can be modified to bool
    s next;
} symbol;

typedef struct symbols_table_item {
    char *name;
    int address;
    bool is_external;
    bool is_command;
}


statement first;
symbol head;

int DC;
int IC;
