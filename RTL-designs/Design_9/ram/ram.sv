module ram 
(
    input   logic         clk,
    input   logic         wr,
    input   logic [1:0]   add,
    input   logic         en,
    input   logic [4:0] w_data,

    output  logic [4:0] r_data

);

    logic[4:0] mem [0:3];

    always_ff@(posedge clk)begin
        if(!en)begin
            if(!wr)begin
                mem[add]<=w_data;
            end
            else if(wr) begin
                r_data<=mem[add];
            end
        end
    end
endmodule