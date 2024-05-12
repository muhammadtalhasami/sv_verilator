module tx_rx# (parameter N=4)
(
    input logic clk,
    input logic rst,
    input logic tx,
    input logic busy
);

    logic ready_o;
    logic valid_o;
    logic [N-1:0]data_o;

    tx u_tx0(
    .clk(clk),
    .rst(rst),
    .tx(tx),
    .ready_i(ready_o),
    .valid_o(valid_o),
    .data_o(data_o)
    );

    rx u_rx0(
    .clk(clk),
    .busy(busy),
    .valid_i(valid_o),
    .data_i(data_o),
    .ready_o(ready_o)
    );

endmodule