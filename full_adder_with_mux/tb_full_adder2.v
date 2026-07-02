`timescale 1ns/1ps
`include "full_adder_with_mux/full_adder2.v"

module tb_full_adder2;
  reg A, B, Cin;
  wire S, Cout;

  // Instantiate the full adder
  full_adder2 uut (
    .A(A),
    .B(B),
    .C(Cin),
    .SUM(S),
    .COUT(Cout)
  );

  initial begin
    $dumpfile("full_adder2.vcd");
    $dumpvars(0, tb_full_adder2);
  end

  initial begin
    // Apply test vectors
    $monitor("Time: %0t | A: %b | B: %b | Cin: %b | S: %b | Cout: %b", $time, A, B, Cin, S, Cout);
    A = 0; B = 0; Cin = 0;
    #10 A = 0; B = 0; Cin = 1;
    #10 A = 0; B = 1; Cin = 0;
    #10 A = 0; B = 1; Cin = 1;
    #10 A = 1; B = 0; Cin = 0;
    #10 A = 1; B = 0; Cin = 1;
    #10 A = 1; B = 1; Cin = 0;
    #10 A = 1; B = 1; Cin = 1;

    #10 $finish;
  end

endmodule
