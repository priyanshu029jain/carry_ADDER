`include "Ripple_carry_adder/Ripple_carry_adder.v"

module Carry_select_adder(
    input  [3:0] A,
    input  [3:0] B,
    input        Cin,
    output [3:0] S,
    output       Cout
);

    // RCA with Cin = 0
    wire [3:0] sum0;
    wire cout0;
    Ripple_carry_adder RCA0 (
        .A    (A),
        .B    (B),
        .Cin  (1'b0),
        .S    (sum0),
        .Cout (cout0)
    );

    // RCA with Cin = 1
    wire [3:0] sum1;
    wire cout1;
    Ripple_carry_adder RCA1 (
        .A    (A),
        .B    (B),
        .Cin  (1'b1),
        .S    (sum1),
        .Cout (cout1)
    );

    // Gate-level multiplexers for each sum bit
    wire nCin;
    not n0(nCin, Cin);

    // S[0]
    wire s0a, s0b;
    and a0(s0a, sum0[0], nCin);
    and a1(s0b, sum1[0], Cin);
    or  o0(S[0], s0a, s0b);

    // S[1]
    wire s1a, s1b;
    and a2(s1a, sum0[1], nCin);
    and a3(s1b, sum1[1], Cin);
    or  o1(S[1], s1a, s1b);

    // S[2]
    wire s2a, s2b;
    and a4(s2a, sum0[2], nCin);
    and a5(s2b, sum1[2], Cin);
    or  o2(S[2], s2a, s2b);

    // S[3]
    wire s3a, s3b;
    and a6(s3a, sum0[3], nCin);
    and a7(s3b, sum1[3], Cin);
    or  o3(S[3], s3a, s3b);

    // Cout multiplexer
    wire c0a, c1a;
    and a8(c0a, cout0, nCin);
    and a9(c1a, cout1, Cin);
    or  o4(Cout, c0a, c1a);

endmodule