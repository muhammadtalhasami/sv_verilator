#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vtx_rx.h"

#define MAX_TIME 20
vluint64_t sim_time = 0;

void operands_values(Vtx_rx* dut){
    if(sim_time > 0 && sim_time < 3){
        dut-> rst = 1;
    }
    else if(sim_time > 3 && sim_time<5){
        dut-> rst  =   0;
        dut-> busy =   0; 
        dut-> tx =   1;
    }
    else if(sim_time > 5){
        dut-> busy =   0; 
        dut-> tx =   0;
    }
}

int main(int argc,char** argv,char** env)
{
    Vtx_rx *dut =new Vtx_rx;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    dut -> clk = 1;

    while(sim_time<MAX_TIME)
    {
        dut->clk = ! dut->clk;
        dut->eval();
        m_trace->dump(sim_time);
        operands_values(dut);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS);
}