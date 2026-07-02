`timescale 1ns/1ps
`include "Ripple_carry_adder/Ripple_carry_adder.v"

module tb_RCA;
  reg  [3:0] A, B;   // 4-bit inputs
  reg        Cin;    // 1-bit carry in
  wire [3:0] S;      // 4-bit sum
  wire       Cout;   // 1-bit carry out

  // Instantiate the 4-bit ripple carry adder
  Ripple_carry_adder uut (
    .A(A),
    .B(B),
    .Cin(Cin),
    .S(S),
    .Cout(Cout)
  );

  initial begin
    $dumpfile("RCA.vcd");
    $dumpvars(0, tb_RCA);
  end

  initial begin
    $monitor("Time: %0t | A: %b | B: %b | Cin: %b | S: %b | Cout: %b",
              $time, A, B, Cin, S, Cout);

    // Apply test vectors
    A = 4'b0000; B = 4'b0000; Cin = 0;
    #10 A = 4'b0001; B = 4'b0001; Cin = 0;
    #10 A = 4'b0010; B = 4'b0011; Cin = 1;
    #10 A = 4'b0101; B = 4'b0110; Cin = 0;
    #10 A = 4'b1111; B = 4'b0001; Cin = 1;
    #10 A = 4'b1010; B = 4'b0101; Cin = 0;
    #10 A = 4'b1111; B = 4'b1111; Cin = 1;

    #10 $finish;
  end

endmodule
