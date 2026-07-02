`include "full_adder_with_xor/full_adder3.v"

module Ripple_carry_adder(
    input  wire [3:0] A,
    input  wire [3:0] B,
    input  wire       Cin,
    output wire [3:0] S,
    output wire       Cout
);

    // Internal carry wires
    wire c1, c2, c3;

    // First full adder (LSB)
    full_adder3 FA1 (
        .A    (A[0]),
        .B    (B[0]),
        .C    (Cin),
        .SUM  (S[0]),
        .COUT (c1)
    );

    // Second full adder
    full_adder3 FA2 (
        .A    (A[1]),
        .B    (B[1]),
        .C    (c1),
        .SUM  (S[1]),
        .COUT (c2)
    );

    // Third full adder
    full_adder3 FA3 (
        .A    (A[2]),
        .B    (B[2]),
        .C    (c2),
        .SUM  (S[2]),
        .COUT (c3)
    );

    // Fourth full adder (MSB)
    full_adder3 FA4 (
        .A    (A[3]),
        .B    (B[3]),
        .C    (c3),
        .SUM  (S[3]),
        .COUT (Cout)
    );

endmodule