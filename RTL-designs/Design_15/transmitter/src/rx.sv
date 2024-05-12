module rx#(parameter N=4)
(
    input logic clk,
    input logic valid_i,
    input logic [N-1:0]data_i,
    input logic busy,

    output logic ready_o  
);

/* verilator lint_off UNUSED */
logic [N-1:0] rx;
/* verilator lint_on UNUSED */


    always_ff@(posedge clk)begin
        if(busy)begin
            ready_o <= 0;
        end
        else if(valid_i) begin
            ready_o <=  1;
            if(ready_o)begin
                rx <= data_i;
            end
        end
        else begin
            ready_o <= 0;
        end
    end

endmodule