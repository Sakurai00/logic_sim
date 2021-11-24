#include "read_logic.h"
#include "read_input.h"
#include "sim.h"
#include "output.h"

int main(void) {
    read_logic();
    read_input();
    sim();
    output();
    return 0;
}