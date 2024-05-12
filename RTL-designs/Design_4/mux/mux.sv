module mux
(
    input  logic a_i,
    input  logic b_i,
    input  logic sel_i,
    output logic c_o
);

    assign c_o =sel_i ? a_i :b_i ;
    
endmodule