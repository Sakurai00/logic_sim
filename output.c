#include "output.h"

void output(void) {
    const char* filename = "output.txt";
    FILE* fp = fopen(filename, "w");

    for(int i = 0; i < gate_num; i++) {
        printf("%s %d\n", node_list[i]->name, node_list[i]->value);
        fprintf(fp, "%s %d\n", node_list[i]->name, node_list[i]->value);
    }
    fclose(fp);
    return;
}