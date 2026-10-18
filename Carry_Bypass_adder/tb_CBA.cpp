#include <iostream>
#include <memory>
#include <verilated.h>
#include "VCarry_bypass_adder.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<VCarry_bypass_adder>();

    // Test vectors (A, B, Cin)
    uint8_t test_A[]   = {0, 1, 2, 5, 15, 10, 15};
    uint8_t test_B[]   = {0, 1, 3, 6, 1,  5,  15};
    uint8_t test_Cin[] = {0, 0, 1, 0, 1,  0,  1};

    int num_tests = sizeof(test_A) / sizeof(test_A[0]);

    for (int i = 0; i < num_tests; i++) {
        top->A = test_A[i];
        top->B = test_B[i];
        top->Cin = test_Cin[i];
        top->eval();

        std::cout << "A: " << (int)top->A 
                  << " | B: " << (int)top->B 
                  << " | Cin: " << (int)top->Cin 
                  << " => S: " << (int)top->S 
                  << " | Cout: " << (int)top->Cout << std::endl;
    }

    // Write coverage data to file
    Verilated::threadContextp()->coveragep()->write("coverage.dat");
    return 0;
}