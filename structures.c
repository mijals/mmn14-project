#include "data.h"

#define size 10000
#define word_len (size_t)31
#define line_len 80
#define command_count 16

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

typedef struct symbols* s;
typedef struct symbols {
    char *name;
    int address;
    int external;
    int is_command;
    s next;
} symbol;

statement first;
symbol head;

int DC;
int IC;