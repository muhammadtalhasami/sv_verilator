module mem_bit#
(
    parameter ADDR       = 8,
    parameter DATA_WIDTH = 32,
    parameter DEPTH      = 256 
)
(
    input logic                     clk,
    input logic                     en,   
    input logic                     wr,
    input logic  [ADDR-1:0]          addr,
    input logic  [DATA_WIDTH-1:0]    wr_data,
    input logic  [DATA_WIDTH-1:0]    bit_mask,

    output logic [DATA_WIDTH-1:0]    r_data
);
    logic [DATA_WIDTH-1:0] mem[DEPTH-1:0];

    always_ff @(posedge clk) begin
        if(en)begin
            if(wr)begin
                mem[addr]<= wr_data & bit_mask;
            end
            else if(!wr)  begin
                r_data  <= mem[addr];
            end
        end 
    end

endmodule