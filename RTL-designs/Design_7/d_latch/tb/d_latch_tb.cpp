#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vd_latch.h"

vluint64_t sim_time = 0;

void read_values(Vd_latch* dut){
    if(sim_time == 0 && sim_time < 2){
        dut->d = 0;
    }
    else if(sim_time == 2 && sim_time < 4){
        dut->d = 1;
    }
    else if(sim_time == 4 && sim_time < 6){
        dut->d = 2;
    }
    else if(sim_time == 6 && sim_time < 8 ){
        dut->d = 14;
    }
    else if(sim_time == 8 && sim_time < 10 ){
        dut->d = 10;
    }
    else if(sim_time == 10 && sim_time < 12 ){
        dut->d = 9;
    }
    else if(sim_time >= 12 ){
        dut->d = 15;
    }
}

int main(int argc,char** argv,char** env)
{
    Vd_latch *dut =new Vd_latch;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    dut -> clk = 0;

    while(sim_time<=14)
    {
        dut->clk = !dut->clk;
        read_values(dut);
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS);
}