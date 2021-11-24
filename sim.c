#include "sim.h"

// logic_gate* node_list[128];

void sim(void) {
    int flag = 1;
    int sum = 0;
    bool is_update = true;

    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < gate_num; i++) {
            //値が更新可能？
            logic_gate* gate = node_list[i];
            is_update = true;

            if (gate->value != -1) is_update = false;

            for (int j = 0; j < gate->in_num; j++) {
                if (gate->in_gate[j]->value == -1) is_update = false;
            }
            if (is_update == true) {
                //値の更新処理
                sum = 0;
                // printf("gatetype: %d\n", gate->type);
                switch (gate->type) {
                    case WIRE:
                        break;
                    case AND:
                        gate->value =
                            gate->in_gate[0]->value & gate->in_gate[1]->value;

                        break;

                    case OR:
                        gate->value =
                            gate->in_gate[0]->value | gate->in_gate[1]->value;
                        break;

                    case NOT:
                        gate->value = !(gate->in_gate[0]->value);
                        break;
                    case XOR:
                        sum += gate->in_gate[0]->value;
                        sum += gate->in_gate[1]->value;

                        if (sum == 1)
                            gate->value = 1;
                        else
                            gate->value = 0;
                        break;
                    case NOR:
                        sum += gate->in_gate[0]->value;
                        sum += gate->in_gate[1]->value;

                        if (sum == 0)
                            gate->value = 1;
                        else
                            gate->value = 0;
                        break;

                    case NAND:
                        sum += gate->in_gate[0]->value;
                        sum += gate->in_gate[1]->value;

                        if (sum == 2)
                            gate->value = 0;
                        else
                            gate->value = 1;
                        break;
                }
                flag = 1;
            }
        }
    }
    return;
}