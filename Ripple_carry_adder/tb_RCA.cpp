#include <iostream>
#include <memory>
#include <sys/stat.h>
#include "VRipple_carry_adder.h"
#include "verilated.h"
#include "verilated_cov.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Instantiate top design module
    auto top = std::make_unique<VRipple_carry_adder>();

    // Force per-instance coverage collection
    Verilated::threadContextp()->coveragep()->forcePerInstance(true);

    std::cout << "Starting full input sweep for RCA coverage..." << std::endl;

    int total_vectors = 0;
    int errors = 0;

    // Sweep all combinations of Cin (0-1), A (0-15), and B (0-15)
    for (int cin = 0; cin < 2; ++cin) {
        for (int a = 0; a < 16; ++a) {
            for (int b = 0; b < 16; ++b) {
                top->Cin = cin;
                top->A = a;
                top->B = b;

                // Evaluate combinational logic
                top->eval();

                // Self-checking sanity assertion
                int expected_sum = a + b + cin;
                int actual_sum = (top->Cout << 4) | (top->S & 0x0F);

                if (actual_sum != expected_sum) {
                    std::cerr << "ERROR: A=" << a << " B=" << b << " Cin=" << cin 
                              << " -> Expected=" << expected_sum 
                              << " Got=" << actual_sum << std::endl;
                    errors++;
                }

                total_vectors++;
            }
        }
    }

    std::cout << "Simulation completed: " << total_vectors 
              << " vectors tested with " << errors << " errors." << std::endl;

    // Create logs directory if it doesn't exist and write coverage file
    mkdir("logs", 0777);
    VerilatedCov::write("logs/coverage.dat");

    return (errors == 0) ? 0 : 1;
}