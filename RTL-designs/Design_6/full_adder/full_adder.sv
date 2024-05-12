`include "half_adder.sv"
module full_adder (
    input logic a,
    input logic b,
    input logic cin,

    output logic sum,
    output logic cout
);
    logic s0;
    logic c0;
    logic c1;

    //instance 1
    half_adder u_half_adder0(
        .a(a),
        .b(b),
        .sum(s0),
        .cout(c1)
    );

    //instance 2
    half_adder u_half_adder1(
        .a(s0),
        .b(cin),
        .sum(sum),
        .cout(c0)
    );

    assign cout = c0 | c1;
endmodule