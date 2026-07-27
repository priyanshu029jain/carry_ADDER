`timescale 1ns/1ps

// SkyWater 130nm 3-input Majority Gate
module sky130_fd_sc_hd__maj3_1 (
    output Y, X,
    input  A, B, C
);
    wire out;
    assign out = (A & B) | (B & C) | (A & C);
    assign Y = out;
    assign X = out;
endmodule

// SkyWater 130nm 2-input XNOR Gate
module sky130_fd_sc_hd__xnor2_1 (
    output Y,
    input  A, B
);
    assign Y = ~(A ^ B);
endmodule
