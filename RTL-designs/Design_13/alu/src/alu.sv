module alu #(parameter DATA_WIDTH = 32) 
    (
    input   logic  [DATA_WIDTH-1:0]    a_i,
    input   logic  [DATA_WIDTH-1:0]    b_i,
    input   logic  [DATA_WIDTH-29:0]   op_i,

    output  logic [DATA_WIDTH-1:0]     res_o
    );
    always_comb begin

        if (op_i==4'b0000) begin
            res_o = a_i + b_i; //add 0
        end
        else if (op_i==4'b0001) begin
            res_o = a_i - b_i; //sub 1
        end
        else if (op_i==4'b0010) begin
            res_o = a_i << b_i; //shift left logical 2
        end
        else if (op_i==4'b0011) begin
            res_o = ($signed (a_i) < $signed (b_i))? 1 : 0; //set less then 3
        end 
        else if (op_i==4'b0100) begin
            res_o = (a_i < b_i)? 1 : 0; //set less then unsigned 4
        end          
        else if (op_i==4'b0101) begin
            res_o = a_i ^ b_i; //xor
        end
        else if (op_i==4'b0110) begin
            res_o = a_i >> b_i; //shift right logical
        end
        else if (op_i==4'b0111) begin
            res_o = a_i >>> b_i; //shift right arithematic
        end
        else if (op_i==4'b1000) begin
            res_o = a_i | b_i; //or
        end
        else if (op_i==4'b1001) begin
            res_o = a_i & b_i; //and
        end
        else begin
            res_o = 0;
        end
    end
endmodule