module type_decoder 
    (
    input  logic [6:0]opcode_i,
    
    output logic r_type_o,
    output logic i_type_o, 
    output logic load_o,
    output logic store_o,
    output logic branch_o, 
    output logic jal_o,
    output logic jalr_o,
    output logic lui_o,
    output logic auipc_o
    );
    always_comb begin 
        r_type_o = 1'b0;
        i_type_o = 1'b0;
        store_o = 1'b0;
        load_o = 1'b0;
        branch_o = 1'b0;
        auipc_o = 1'b0; 
        jal_o = 1'b0; 
        jalr_o = 1'b0; 
        lui_o = 1'b0; 
        case(opcode_i)
            7'b0110011:begin 
                r_type_o = 1'b1;
            end 
            7'b0010011:begin 
                i_type_o = 1'b1;
            end
            7'b0100011:begin 
                store_o = 1'b1;
            end
            7'b0000011:begin
                load_o = 1'b1;
            end
            7'b1100011:begin 
                branch_o = 1'b1;
            end
            7'b0010111:begin 
                auipc_o = 1'b1;
            end
            7'b1101111:begin 
                jal_o = 1'b1;
            end
            7'b1100111:begin 
                jalr_o = 1'b1;
            end
            7'b0110111:begin 
                lui_o = 1'b1;
            end

            default:begin 
                r_type_o = 1'b0;
                i_type_o = 1'b0;
                store_o= 1'b0;
                load_o = 1'b0;
                branch_o = 1'b0;
                auipc_o = 1'b0;
                jal_o = 1'b0; 
                jalr_o = 1'b0; 
                lui_o = 1'b0; 
            end
        endcase
    end  
endmodule