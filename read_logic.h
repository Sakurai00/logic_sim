#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

extern void read_logic();
int find_gate(char* name);
logic_gate* make_gate(char* name);
extern void test_read_logic();
