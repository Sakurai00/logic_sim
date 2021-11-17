#include <sim.h>

int sim(void) {
    int flag, i, j,num;
    int m = 0;
    int sum=0;

    for (flag = 1; flag == 1; flag = 0) {
        for (i = 0; i <= 17; i++) {
            //値が更新可能？
            num=node_list[i].in_num;
            for (j = 0; j < num; j++) {
                if (node_list[i].in_gate[j] != -1) m++;
            }
            //値の更新処理
            if ((m + 1) == num){
                switch(node_list[i].type){
                    case wire:
                        break;
                    case and:
                        sum+=node_list
                    case or:
                        for(j = 0; j < num; j++){
                            sum += (node_list[i]in_gate[j].value);
                        }
                        if((sum / num) == 1) node_list[i].value = 1;
                        else node_list[i].value = 0;
                }
            }
          
        }
    }
}