module tx #(parameter N = 4)
(
    input logic clk,
    input logic rst,
    input logic tx,
    input logic ready_i,
    
    output logic valid_o,
    output logic [N-1:0]data_o
);

    localparam IDLE     =  2'b00 ;
    localparam TX       =  2'b01 ;   
    localparam VALID    =  2'b10 ;

    logic [1:0] state;
    logic [1:0] next_state;

    //SEQUENTIAL BLOCK
    always_ff @(posedge clk) begin
        if(rst)begin
            state <= 2'b00;
        end
        else begin
            state <= next_state;
        end    
    end

    //COMBINATIONAL BLOCK
    always_comb begin
        case (state)
            IDLE:begin
                next_state = TX;
                valid_o    = 1'b0; 
            end
            TX:begin
                next_state = (tx)? VALID:TX;
                valid_o    = 1'b0; 
            end
            VALID:begin
                next_state = (ready_i)? TX:VALID;
                valid_o    = 1'b1;
                data_o     = 4'b0101; 
            end
                default: next_state = IDLE;
        endcase
    end
endmodule

