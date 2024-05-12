module gates (
    input           a_i,
    inout           b_i,
    output logic    not_o,
    output logic    and_o,
    output logic    nand_o,
    output logic    nor_o,
    output logic    or_o,
    output logic    xor_o,
    output logic    xnor_o
);

    assign not_o = ~a_i;
    assign and_o = a_i & b_i;
    assign nand_o = ~(a_i & b_i);
    assign nor_o = ~(a_i | b_i);
    assign or_o = a_i | b_i;
    assign xor_o = a_i ^ b_i;
    assign xnor_o = ~(a_i ^ b_i);

endmodule