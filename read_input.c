#include "read_input.h"

void read_input() {
    char gate_name[128];
    int gate_input;

    FILE* fp = fopen(INPUT_FILENAME, "r");

    if (fp == NULL) {
        printf("Error opening imput.txt");
        exit(1);
    }
    while (fscanf(fp, "%s%d", gate_name, &gate_input) != EOF) {
        logic_gate* gate;
        int gate_index = find_gate(gate_name);
        if (gate_index == -1) {
            printf("Error: gate %s not found\n", gate_name);
            exit(1);
        } else {
            gate = node_list[gate_index];
        }
        gate->value = gate_input;
    }
    fclose(fp);
}

void test_read_input() {
    read_input();

    for (int i = 0; i < gate_num; i++) {
        printf("%s %d\n", node_list[i]->name, node_list[i]->value);
    }
}

/* input.txt
G1 1
G2 0
G3 1
*/