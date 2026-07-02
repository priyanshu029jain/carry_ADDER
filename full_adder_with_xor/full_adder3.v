module full_adder3(
    input A,
    input B,
    input C,
    output SUM,
    output COUT
    );
    wire w1,w2,w3;
    
    xor x(SUM, A,B,C);
    
    and a1(w1, A,B);
    and a2(w2, A,C);
    and a3(w3, C,B);
    or o1(COUT, w1,w2,w3);
    
endmodule