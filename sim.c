#include "sim.h"

void sim(void) {
    int flag = 1;
    int sum = 0;
    bool is_update = true;

    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < gate_num; i++) {
            logic_gate* gate = node_list[i];

            //値が更新可能？
            is_update = true;

            if (gate->value != -1) is_update = false;

            for (int j = 0; j < gate->in_num; j++) {
                if (gate->in_gate[j]->value == -1) is_update = false;
            }

            if (is_update == true) {
                //値の更新処理
                sum = 0;
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
                        gate->value =
                            !(gate->in_gate[0]->value | gate->in_gate[1]->value);
                        break;

                    case NAND:
                        gate->value =
                            !(gate->in_gate[0]->value & gate->in_gate[1]->value);
                        break;
                }
                flag = 1;
            } // end of update
        } // enf of all gate check
    } // end of main loop
    return;
}