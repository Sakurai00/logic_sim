#ifndef MAIN
#define MAIN

#include <stdbool.h>

// #include "read_logic.h"

enum logic { WIRE, AND, OR, NOT, XOR, NOR, NAND };

struct logic_gate {
    char name[128];
    enum logic type;
    int value;
    bool is_input;
    bool is_output;
    int in_num;
    struct logic_gate *in_gate[10];
    struct logic_gate *out_gate[32];
};

typedef struct logic_gate logic_gate;

extern logic_gate *node_list[128];
extern int gate_num;

#endif