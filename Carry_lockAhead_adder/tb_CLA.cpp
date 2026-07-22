#include <iostream>
#include <memory>
#include <sys/stat.h>
#include "VCarry_lookAhead_adder.h"
#include "verilated.h"
#include "verilated_cov.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    auto top = std::make_unique<VCarry_lookAhead_adder>();

    Verilated::threadContextp()->coveragep()->forcePerInstance(true);

    std::cout << "Running Complete Coverage Simulation..." << std::endl;

    // Run nested loops to hit every logic branch
    for (int cin = 0; cin < 2; ++cin) {
        for (int a = 0; a < 16; ++a) {
            for (int b = 0; b < 16; ++b) {
                top->Cin = cin;
                top->A = a;
                top->B = b;
                top->eval(); // Evaluates design for each pair
            }
        }
    }

    mkdir("logs", 0777);
    VerilatedCov::write("logs/coverage.dat");

    std::cout << "Done! All branches evaluated." << std::endl;
    return 0;
}