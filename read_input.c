#include "read_input.h"

void read_input() {
    char gate_name[MAX_GATE_NAME_LEN];
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

        if (gate_input != -1) {
            gate->value = gate_input;
            gate->is_input = true;
        } else if (gate_input == -1) {
            gate->is_output = true;
        }
    }
    fclose(fp);

    return;
}

void test_read_input() {
    read_input();

    for (int i = 0; i < gate_num; i++) {
        printf("%s %d\n", node_list[i]->name, node_list[i]->value);
    }
    return;
}
