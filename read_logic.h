#pragma once

#define LOGIC_FILENAME "logic.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

extern void read_logic();

extern int find_gate(char* name);

extern void test_read_logic();
