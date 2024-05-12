module tristate_buffer(
    input                   en,
    input           [3:0]    a,
    output  logic   [3:0]    y
);

assign y = (en)? a: 4'bz;
endmodule