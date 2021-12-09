#include "output.h"

void output(void) {
    FILE* fp = fopen(OUTPUT_FILENAME, "w");

    printf("INPUT:\n");
    fprintf(fp, "INPUT:\n");
    for (int i = 0; i < gate_num; i++) {
        if (node_list[i]->is_input == true) {
            printf("%s %d\n", node_list[i]->name, node_list[i]->value);
            fprintf(fp, "%s %d\n", node_list[i]->name, node_list[i]->value);
        }
    }

    printf("\nCalc:\n");
    fprintf(fp, "\nCalc:\n");
    for (int i = 0; i < gate_num; i++) {
        if ((node_list[i]->is_input != true) &&
            (node_list[i]->is_output != true)) {
            printf("%s %d\n", node_list[i]->name, node_list[i]->value);
            fprintf(fp, "%s %d\n", node_list[i]->name, node_list[i]->value);
        }
    }


    printf("\nOUTPUT:\n");
    fprintf(fp, "\nOUTPUT:\n");
    for (int i = 0; i < gate_num; i++) {
        if (node_list[i]->is_output == true) {
            printf("%s %d\n", node_list[i]->name, node_list[i]->value);
            fprintf(fp, "%s %d\n", node_list[i]->name, node_list[i]->value);
        }
    }


    fclose(fp);
    return;
}