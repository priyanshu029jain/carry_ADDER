`include "half_adder/half_adder.v"

module full_adder1(
    input A,
    input B,
    input C,
    output SUM,
    output COUT
    );

    wire w1,w2,w3;
    
    half_adder HA1 ( 
    .A(A),
    .B(B),
    .C(w2),
    .S(w1)
    );
    
    half_adder HA2 ( 
    .A(w1),
    .B(C),
    .C(w3),
    .S(SUM)
    );
    
    or o1 (COUT, w2, w3);

endmodule