#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vtristate_buffer.h"

vluint64_t sim_time = 0;

void read_values(Vtristate_buffer* dut){
    if(sim_time == 0 && sim_time < 2){
        dut->en = 0;
    }
    else if(sim_time == 2 && sim_time < 4){
        dut->en = 1;
        dut->a = 10;
    }
    else if(sim_time == 4 && sim_time < 6){
        dut->en = 0;
        dut->a = 7;
    }
    else if(sim_time >= 6){
        dut->en = 1;
        dut->a = 7;
    }
}

int main(int argc,char** argv,char** env)
{
    Vtristate_buffer *dut =new Vtristate_buffer;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    while(sim_time<=8)
    {
        read_values(dut);
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS);
}