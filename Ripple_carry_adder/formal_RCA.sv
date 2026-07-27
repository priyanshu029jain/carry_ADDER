//`include "Ripple_carry_adder/Ripple_carry_adder.v"

module formal_RCA (
    input  wire [3:0] A,
    input  wire [3:0] B,
    input  wire        Cin,
    output wire [3:0] S,
    output wire        Cout
);

    // Instantiate the pure RCA design-under-test (DUT)
    Ripple_carry_adder dut (
        .A(A),
        .B(B),
        .Cin(Cin),
        .S(S),
        .Cout(Cout)
    );

    // Formal Assertions
    always @(*) begin
        assert ({Cout, S} == A + B + Cin);
    end

endmodule