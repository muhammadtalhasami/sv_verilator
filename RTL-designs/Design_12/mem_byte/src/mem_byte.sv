module mem_byte#
(
parameter DATAWIDTH =32 ,
parameter ADDRESS   =8 ,
parameter DEPTH     =256
)
(
    input                           clk,   
    input                           en,
    input                           wr,
    input           [3:0]           wr_mask,
    input           [ADDRESS-1:0]   addr,
    input           [DATAWIDTH-1:0] wr_data,
    output logic    [DATAWIDTH-1:0] r_data
);

logic [DATAWIDTH-1:0] mem [DEPTH-1:0];


always_ff @(posedge clk) begin
    if(en)begin
        if(wr)begin
            if(wr_mask[0])begin
            mem[addr][7:0]<=wr_data[7:0];
            end
            if(wr_mask[1])begin
            mem[addr][15:8]<=wr_data[15:8];
            end
            if(wr_mask[2])begin
            mem[addr][23:16]<=wr_data[23:16];
            end
            if(wr_mask[3])begin
            mem[addr][31:24]<=wr_data[31:24];
            end
        end
        else if(!wr)begin
            r_data  <= mem[addr][31:0];
        end
    end
end
endmodule