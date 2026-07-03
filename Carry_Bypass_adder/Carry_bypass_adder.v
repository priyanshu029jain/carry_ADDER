`include "Ripple_carry_adder/Ripple_carry_adder.v"

module Carry_bypass_adder(
    input  wire [3:0] A,
    input  wire [3:0] B,
    input  wire       Cin,
    output wire [3:0] S,
    output wire       Cout
);

    // Ripple carry adder block
    wire ripple_cout;
    Ripple_carry_adder RCA (
        .A    (A),
        .B    (B),
        .Cin  (Cin),
        .S    (S),
        .Cout (ripple_cout)
    );

    // Propagate signals for skip logic
    wire p0, p1, p2, p3, block_prop;
    xor (p0, A[0], B[0]);
    xor (p1, A[1], B[1]);
    xor (p2, A[2], B[2]);
    xor (p3, A[3], B[3]);

    // Block propagate = p0 & p1 & p2 & p3
    and (block_prop, p0, p1, p2, p3);

    // Carry skip logic:
    // If block propagates, Cout = Cin
    // Else Cout = ripple_cout
    wire skip_carry, ripple_carry;
    and a0(skip_carry, block_prop, Cin);
    and a1(ripple_carry, ~block_prop, ripple_cout);
    or  o0(Cout, skip_carry, ripple_carry);

endmodule