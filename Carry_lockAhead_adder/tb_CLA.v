`timescale 1ns/1ps
`include "Carry_lockAhead_adder/Carry_lookAhead_adder.v"

module tb_CLA;
  // Parameters
  localparam STIM_DELAY = 10;
  
  // Testbench Signals
  reg  [3:0] A_in, B_in; // 4-bit inputs
  reg        Cin_in;     // 1-bit carry in
  wire [3:0] S_dut;      // 4-bit sum from DUT
  wire       Cout_dut;   // 1-bit carry out from DUT

  // Golden Reference Model Signals
  integer i, j, k;
  reg [4:0] expected_full_result; // 5-bit to hold {Cout, Sum}
  reg [3:0] expected_S;
  reg       expected_Cout;

  // Scoreboard Variables
  integer tests_run = 0;
  integer tests_passed = 0;
  integer tests_failed = 0;

  // 1. Instantiate the Design Under Test (DUT)
  Carry_lookAhead_adder dut (
    .A(A_in),
    .B(B_in),
    .Cin(Cin_in),
    .S(S_dut),
    .Cout(Cout_dut)
  );

  // 2. Waveform Dumping
  initial begin
    $dumpfile("CLA.vcd");
    $dumpvars(0, tb_CLA);
  end

  // 3. Exhaustive Stimulus Generation and Self-Checking Loop
  initial begin
    $display("\n=======================================================");
    $display("STARTING EXHAUSTIVE, SELF-CHECKING CLA TESTBENCH");
    $display("=======================================================");
    
    // Set initial values
    A_in = 4'b0; B_in = 4'b0; Cin_in = 0;
    #2; // Slight offset from time 0

    // Exhaustive Loop 1: Carry-In (0 to 1)
    for (i = 0; i < 2; i = i + 1) begin
      Cin_in = i;
      
      // Exhaustive Loop 2: A Inputs (0 to 15)
      for (j = 0; j < 16; j = j + 1) begin
        A_in = j;
        
        // Exhaustive Loop 3: B Inputs (0 to 15)
        for (k = 0; k < 16; k = k + 1) begin
          B_in = k;
          
          tests_run = tests_run + 1;
          
          // Apply stimulus and wait for logic to settle
          #(STIM_DELAY); 

          // ----------------------------------------------------
          // 4. Golden Reference Model Comparison
          // ----------------------------------------------------
          // We calculate the expected result using standard Verilog math.
          // This models a perfect behavioral reference.
          expected_full_result = A_in + B_in + Cin_in;
          
          // Split the golden result into Cout and S
          expected_Cout = expected_full_result[4]; // 5th bit (MSB)
          expected_S    = expected_full_result[3:0]; // Lower 4 bits

          // ----------------------------------------------------
          // 5. Checking and Scoreboarding
          // ----------------------------------------------------
          if ((S_dut !== expected_S) || (Cout_dut !== expected_Cout)) begin
            tests_failed = tests_failed + 1;
            // Report failure instantly
            $error("ERROR @ %0t | A:%d | B:%d | Cin:%d | DUT Got:{%b,%d} | EXPECTED:{%b,%d}",
                   $time, A_in, B_in, Cin_in, Cout_dut, S_dut, expected_Cout, expected_S);
          end else begin
            tests_passed = tests_passed + 1;
            // Optional: verbose tracking for debug
            // $display("PASS @ %0t | A:%d | B:%d | Cin:%d", $time, A_in, B_in, Cin_in);
          end
        end
      end
    end

    // 6. Test Completion and Summary Report
    #10;
    $display("\n=======================================================");
    $display("TEST COMPLETION SUMMARY");
    $display("=======================================================");
    $display("Total Tests Run: %0d", tests_run);
    $display("Tests Passed:    %0d", tests_passed);
    $display("Tests Failed:    %0d", tests_failed);
    
    if (tests_failed == 0 && tests_run == 512) begin
      $display("RESULT: 🏆 PASS! All inputs tested, zero errors.");
    end else if (tests_run != 512) begin
      $display("RESULT: 🛑 FAIL! Did not complete all tests (Run:%0d/512).", tests_run);
    end else begin
      $display("RESULT: ❌ FAIL! %0d test mismatches detected.", tests_failed);
    end
    $display("=======================================================\n");

    $finish;
  end

endmodule