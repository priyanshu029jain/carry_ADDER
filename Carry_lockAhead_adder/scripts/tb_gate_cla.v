`timescale 1ns/1ps

module tb_gate_cla;
    reg [3:0] A, B;
    reg Cin;
    wire [3:0] S;
    wire Cout;

    // Instantiate synthesized gate-level netlist
    Carry_lookAhead_adder uut (
        .A(A),
        .B(B),
        .Cin(Cin),
        .S(S),
        .Cout(Cout)
    );

    initial begin
        // Generate VCD waveform file
        $dumpfile("gate_cla.vcd");
        $dumpvars(0, tb_gate_cla);

        // Apply realistic test vectors
        A = 4'b0000; B = 4'b0000; Cin = 0; #10;
        A = 4'b0101; B = 4'b0011; Cin = 0; #10;
        A = 4'b1111; B = 4'b0001; Cin = 0; #10;
        A = 4'b1010; B = 4'b0101; Cin = 1; #10;
        A = 4'b1111; B = 4'b1111; Cin = 1; #10;
        $finish;
    end
endmodule
