#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vmem_byte.h"

vluint64_t sim_time = 0;

void read_values(Vmem_byte* dut){
    if(sim_time == 0 && sim_time < 2){
        dut->en = 0;
    }
    else if(sim_time == 2 && sim_time < 4){
        dut->en = 1;
        dut->wr = 1;
        dut->wr_mask = 0;
        dut->wr_data  =1024;
    }
    else if(sim_time == 4 && sim_time < 6){
        dut->en = 1;
        dut->wr = 1;
        dut->wr_mask = 1;
        dut->wr_data  =1024;
    }
    else if(sim_time == 6 && sim_time < 8 ){
        dut->en = 1;
        dut->wr = 1;
        dut->wr_mask = 2;
        dut->wr_data  =1024;
    }
    else if(sim_time == 8 && sim_time < 10 ){
        dut->en = 1;
        dut->wr = 1;
        dut->wr_mask = 3;
        dut->wr_data  =1024;
    }
    else if(sim_time == 10 && sim_time < 12 ){
        dut->en = 0;
        dut->wr = 0;
    }
    else if(sim_time >= 12 ){
        dut->en = 1;
        dut->wr = 0;
    }
}

int main(int argc,char** argv,char** env)
{
    Vmem_byte *dut =new Vmem_byte;

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