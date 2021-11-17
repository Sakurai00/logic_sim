#include "read_logic.h"

const char* filename = "logic.txt";

logic_gate node_list[128];
int gate_num = 0;

void read_logic() {
    FILE *fp = fopen(filename, "r");
    char buf[1024];
    bool is_exist = false;
    gate_num = 0;

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(fp, "%s", buf) != EOF) {
        // 読み込んだゲートが存在するか
        for(int i = 0; i < gate_num; i++) {
            if (strcmp(buf, node_list[i].name) == 0) {
                is_exist = true;
                break;
            }
        }
        if(is_exist) break;

        // 読み込んだゲートが存在しない場合
        strcpy(node_list[gate_num].name, buf);
        gate_num++;


    }
    
}