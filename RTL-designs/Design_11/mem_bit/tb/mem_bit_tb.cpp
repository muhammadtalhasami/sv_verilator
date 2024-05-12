#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vmem_bit.h"

#define FINISH_TIME 30
vluint64_t sim_time = 0;

void get_values(Vmem_bit *dut)
{
    if(sim_time<3)
    {
        dut-> en = 0;
    }
    else if(sim_time==3 && sim_time <6)
    {
        dut-> en        =  1;
        dut-> wr        =  1;
        dut-> addr      = 20;
        dut-> wr_data   =  7; //0111
        dut-> bit_mask  =  5; //0101
    }
    else if(sim_time==6 && sim_time<9)
    {
        dut-> wr        =  0;
        dut-> addr      = 20;
    }
    else if(sim_time==9 && sim_time <12)
    {
        dut-> en        =  0;
        dut-> wr        =  1;
        dut-> addr      = 30;
        dut-> wr_data   =  4; //0100
        dut-> bit_mask  =  1; //0001
    }
    else if(sim_time==12 && sim_time <15)
    {
        dut-> en        =  1;
        dut-> wr        =  1;
        dut-> addr      = 30;
        dut-> wr_data   =  4; //0111
        dut-> bit_mask  =  1; //0101
    }
    else if(sim_time==15 && sim_time <18)
    {
        dut-> wr        =  0;
        dut-> addr      = 30;
    }
}

int main(int argc,char** argv,char** env)
{
    Vmem_bit *dut = new Vmem_bit;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    dut-> clk = 0;

    while(sim_time<FINISH_TIME)
    {
        dut->clk = !dut-> clk;
        get_values(dut);
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS); 
}