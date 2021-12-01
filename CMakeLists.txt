cmake_minimum_required(VERSION 3.0.0)
project(logic-sim VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(sim.out main.c read_input.c read_logic.c sim.c)
add_executable(sim.out main.c read_input.c read_logic.c sim.c output.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
