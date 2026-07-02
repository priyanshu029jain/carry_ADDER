module full_adder2(
    input A,
    input B,
    input C,
    output SUM,
    output COUT
    );

    wire w1, w2, w3;
    
    xor x1 (w1, A, B);
    xor x2 (SUM, C, w1);
    
    //mux
    and a1 (w2, ~w1, B);
    and a2 (w3, w1, C);
    or o2 (COUT, w2, w3);
endmodule