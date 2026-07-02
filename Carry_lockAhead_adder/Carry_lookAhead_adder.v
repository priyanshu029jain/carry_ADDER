module Carry_lookAhead_adder(
    input  [3:0] A,
    input  [3:0] B,
    input        Cin,
    output [3:0] S,
    output       Cout
);

    // Generate (G) and Propagate (P)
    wire [3:0] G, P;
    and g0(G[0], A[0], B[0]);
    and g1(G[1], A[1], B[1]);
    and g2(G[2], A[2], B[2]);
    and g3(G[3], A[3], B[3]);

    xor p0(P[0], A[0], B[0]);
    xor p1(P[1], A[1], B[1]);
    xor p2(P[2], A[2], B[2]);
    xor p3(P[3], A[3], B[3]);

    // Carry signals computed in parallel
    wire c1, c2, c3;

    // c1 = G0 + P0*Cin
    wire p0c;
    and a0(p0c, P[0], Cin);
    or  o0(c1, G[0], p0c);

    // c2 = G1 + P1*G0 + P1*P0*Cin
    wire p1g0, p1p0c;
    and a1(p1g0, P[1], G[0]);
    and a2(p1p0c, P[1], P[0], Cin);
    or  o1(c2, G[1], p1g0, p1p0c);

    // c3 = G2 + P2*G1 + P2*P1*G0 + P2*P1*P0*Cin
    wire p2g1, p2p1g0, p2p1p0c;
    and a3(p2g1, P[2], G[1]);
    and a4(p2p1g0, P[2], P[1], G[0]);
    and a5(p2p1p0c, P[2], P[1], P[0], Cin);
    or  o2(c3, G[2], p2g1, p2p1g0, p2p1p0c);

    // Cout = G3 + P3*G2 + P3*P2*G1 + P3*P2*P1*G0 + P3*P2*P1*P0*Cin
    wire p3g2, p3p2g1, p3p2p1g0, p3p2p1p0c;
    and a6(p3g2, P[3], G[2]);
    and a7(p3p2g1, P[3], P[2], G[1]);
    and a8(p3p2p1g0, P[3], P[2], P[1], G[0]);
    and a9(p3p2p1p0c, P[3], P[2], P[1], P[0], Cin);
    or  o3(Cout, G[3], p3g2, p3p2g1, p3p2p1g0, p3p2p1p0c);

    // Sum outputs: Si = Pi ^ Ci
    xor s0(S[0], P[0], Cin);
    xor s1(S[1], P[1], c1);
    xor s2(S[2], P[2], c2);
    xor s3(S[3], P[3], c3);

endmodule
