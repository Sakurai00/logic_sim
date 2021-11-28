#pragma once

#include <stdbool.h>

#define MAX_BUF 1024
#define MAX_GATE_NUM 128
#define MAX_GATE_NAME_LEN 32

enum logic { WIRE, AND, OR, NOT, XOR, NOR, NAND };

struct logic_gate {
    char name[MAX_GATE_NAME_LEN];
    enum logic type;
    int value;
    bool is_input;
    bool is_output;
    int in_num;
    struct logic_gate *in_gate[3];
    struct logic_gate *out_gate[MAX_GATE_NUM];
};

typedef struct logic_gate logic_gate;

extern logic_gate *node_list[MAX_GATE_NUM];
extern int gate_num;
