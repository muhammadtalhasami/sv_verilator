module d_latch(
    input                   clk,
    input           [3:0]   d,
    output  logic   [3:0]   q
);

always_latch begin
    if(clk)begin
    q<=d;
    end
end

endmodule