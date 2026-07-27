`timescale 1ns/1ps
//`include "Carry_Bypass_adder/Carry_bypass_adder.v"

module tb_CBA;
  reg  [3:0] A, B;   // 4-bit inputs
  reg        Cin;    // 1-bit carry in
  wire [3:0] S;      // 4-bit sum
  wire       Cout;   // 1-bit carry out

  // Instantiate DUT
  Carry_bypass_adder uut (
    .A(A),
    .B(B),
    .Cin(Cin),
    .S(S),
    .Cout(Cout)
  );

  // Expected outputs
  reg [4:0] expected;

  // Scoreboard counters
  integer tests_run     = 0;
  integer tests_passed  = 0;
  integer tests_failed  = 0;

  integer i;

  initial begin
    $dumpfile("CBA.vcd");
    $dumpvars(0, tb_CBA);

    // -------------------------------
    // 1. Randomized Testing with Constraints
    // -------------------------------
    for (i = 0; i < 200; i = i + 1) begin
      A   = $random % 16;   // keep within 4-bit
      B   = $random % 16;
      Cin = $random % 2;

      expected = A + B + Cin;

      #1; // allow DUT to settle

      tests_run = tests_run + 1;

      if ({Cout, S} === expected) begin
        tests_passed = tests_passed + 1;
        $display("✅ PASS | Time=%0t | A=%b B=%b Cin=%b | Sum=%b Cout=%b",
                  $time, A, B, Cin, S, Cout);
      end else begin
        tests_failed = tests_failed + 1;
        $display("❌ FAIL | Time=%0t | A=%b B=%b Cin=%b | DUT={Cout=%b, S=%b} | Expected=%b",
                  $time, A, B, Cin, Cout, S, expected);
      end

      #5;
    end

    // -------------------------------
    // 2. Directed Corner Cases
    // -------------------------------
    apply_test(4'b0000, 4'b0000, 0);
    apply_test(4'b1111, 4'b1111, 1);
    apply_test(4'b1010, 4'b0101, 0);
    apply_test(4'b0111, 4'b0001, 1);

    // -------------------------------
    // 3. Final Scoreboard Summary
    // -------------------------------
    #10;
    $display("\n=======================================================");
    $display("TEST COMPLETION SUMMARY");
    $display("=======================================================");
    $display("Total Tests Run: %0d", tests_run);
    $display("Tests Passed:    %0d", tests_passed);
    $display("Tests Failed:    %0d", tests_failed);

    if (tests_failed == 0) begin
      $display("RESULT: 🏆 PASS! All tests successful.");
    end else begin
      $display("RESULT: ❌ FAIL! %0d mismatches detected.", tests_failed);
    end
    $display("=======================================================\n");

    $finish;
  end

  // -------------------------------
  // Task: Apply Directed Test
  // -------------------------------
  task apply_test(input [3:0] a, input [3:0] b, input cin);
    begin
      A = a; B = b; Cin = cin;
      expected = A + B + Cin;
      #1;
      tests_run = tests_run + 1;
      if ({Cout, S} === expected) begin
        tests_passed = tests_passed + 1;
        $display("✅ PASS | Directed | A=%b B=%b Cin=%b | Sum=%b Cout=%b",
                  A, B, Cin, S, Cout);
      end else begin
        tests_failed = tests_failed + 1;
        $display("❌ FAIL | Directed | A=%b B=%b Cin=%b | DUT={Cout=%b, S=%b} | Expected=%b",
                  A, B, Cin, Cout, S, expected);
      end
    end
  endtask

endmodule
