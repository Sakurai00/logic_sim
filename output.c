#include "output.h"

void output(void) {
    FILE* fp = fopen(OUTPUT_FILENAME, "w");

    for(int i = 0; i < gate_num; i++) {
        printf("%s %d\n", node_list[i]->name, node_list[i]->value);
        fprintf(fp, "%s %d\n", node_list[i]->name, node_list[i]->value);
    }
    fclose(fp);
    return;
}