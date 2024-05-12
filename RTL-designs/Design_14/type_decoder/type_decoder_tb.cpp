#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vtype_decoder.h"

vluint64_t sim_time = 0;

void opcode_read(Vtype_decoder* dut){
    if(sim_time == 0 && sim_time < 2){
        dut->opcode_i = 51;
    }
    else if(sim_time == 2 && sim_time < 4){
        dut->opcode_i = 19;
    }
    else if(sim_time == 4 && sim_time < 6){
        dut->opcode_i = 35;      
    }
    else if(sim_time == 6 && sim_time < 8){
        dut->opcode_i = 99;
    }
    else if(sim_time == 8 && sim_time < 10){
        dut->opcode_i = 23;
    }
    else if(sim_time == 10 && sim_time < 12){
        dut->opcode_i = 3;
    }
    else if(sim_time == 12 && sim_time < 14){
        dut->opcode_i = 55;
    }
    else if(sim_time == 14 && sim_time < 16){
        dut->opcode_i = 111;
    }
    else if(sim_time == 16 && sim_time < 18){
        dut->opcode_i = 103;
    }
}

int main(int argc,char** argv,char** env)
{
    Vtype_decoder *dut =new Vtype_decoder;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    while(sim_time<=18)
    {
        opcode_read(dut);
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS);
}