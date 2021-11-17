/**
 * @file read_logic.c
 * @author Sakurai
 * @brief 論理回路読み込み
 * @version 0.1
 * @date 2021-11-17
 */

#include "read_logic.h"

// prototype
int find_gate(char* name);
logic_gate* make_gate(char* name);

// global variable
const char* filename = "logic.txt";
logic_gate* node_list[128];
int gate_num = 0;
int out_list[128];

/**
 * @brief ファイルから回路データを読み込む
 *
 */
void read_logic() {
    FILE* fp = fopen(filename, "r");
    char buf[1024];

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(fp, "%s", buf) != EOF) {
        logic_gate* gate;

        int gate_index = find_gate(buf);
        if (gate_index == -1) {
            // 入力ゲートが存在しない場合
            gate = make_gate(buf);

        } else {
            gate = node_list[gate_index];
        };

        fscanf(fp, "%s", buf);
        if (strcmp(buf, "AND") == 0) {
            gate->type = AND;
            gate->in_num = 2;
        } else if (strcmp(buf, "OR") == 0) {
            gate->type = OR;
            gate->in_num = 2;
        } else if (strcmp(buf, "NOT") == 0) {
            gate->type = NOT;
            gate->in_num = 1;
        } else if (strcmp(buf, "XOR") == 0) {
            gate->type = XOR;
            gate->in_num = 2;
        } else if (strcmp(buf, "NAND") == 0) {
            gate->type = NAND;
            gate->in_num = 2;
        } else {
            printf("Error: Unknown gate type!\n");
            exit(1);
        }

        // 入力ゲート設定
        for (int input_num = 0; input_num < gate->in_num; input_num++) {
            fscanf(fp, "%s", buf);

            gate_index = find_gate(buf);
            if (gate_index == -1) {
                // 入力ゲートが存在しない場合新規に作成
                logic_gate* tmp_gate = make_gate(buf);
                gate->in_gate[input_num] = tmp_gate;
            } else {
                gate->in_gate[input_num] = node_list[gate_index];
            }
        }
    }

    fclose(fp);

    // 出力ゲート設定
    for (int i = 0; i < gate_num; i++) {
        logic_gate* out_gate = node_list[i];
        for (int j = 0; j < out_gate->in_num; j++) {
            // node_list[i]の入力元を探す
            logic_gate* base_gate = out_gate->in_gate[j];

            // 入力元の出力先にnode_list[i]を追加
            base_gate->out_gate[out_list[i]] = out_gate;
            out_list[i]++;
        }
    }
}

/**
 * @brief nodo_list内に対象のゲートがあるか調べる
 *
 * @param name 探索対象のゲート名
 * @return int 存在すればインデックス，存在しなければ-1を返す
 */
int find_gate(char* name) {
    for (int i = 0; i < gate_num; i++) {
        if (strcmp(name, node_list[i]->name) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief logic_gateを一つ作成する
 *
 * @param name ゲート名
 * @return logic_gate* 作成した構造体へのポインタ
 */
logic_gate* make_gate(char* name) {
    logic_gate* gate = malloc(sizeof(logic_gate));
    strcpy(gate->name, name);
    gate->type = WIRE;
    gate->value = -1;

    // node_listの最後尾に追加
    node_list[gate_num] = gate;
    gate_num++;

    return gate;
}

/**
 * @brief test for read_logic()
 *
 */
void test_read_logic() {
    read_logic();

    for (int i = 0; i < gate_num; i++) {
        printf("%s %d\n", node_list[i]->name, node_list[i]->type);
        printf("    IN: ");
        for (int j = 0; j < node_list[i]->in_num; j++) {
            printf("%s ", node_list[i]->in_gate[j]->name);
        }
        printf("\n");
        printf("    OUT: ");
        for (int j = 0; j < out_list[i]; j++) {
            printf("%s ", node_list[i]->out_gate[j]->name);
        }
        printf("\n");
    }
}
