module up_counter# (parameter N=4)
    (
    input  logic        clk,
    input  logic        rst,
    output logic[N-1:0] q
    );

    always_ff @(posedge clk)begin
    if(rst) begin
        q <= 0;
    end
    else begin
        q <= q+1;
    end
    end
endmodule
