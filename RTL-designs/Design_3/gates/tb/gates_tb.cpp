#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vgates.h"

#define MAX_TIME 20
vluint64_t sim_time = 0;

void input_values(Vgates* dut){
    if(sim_time == 0 && sim_time < 3){
        dut-> a_i = 0;
        dut-> b_i = 0;
    }
    else if(sim_time == 3){
        dut-> a_i = 0;
        dut-> b_i = 1; 
    }
    else if(sim_time == 4){
        dut-> a_i = 1;
        dut-> b_i = 0;        
    }
    else if(sim_time > 4 && sim_time < 6){
        dut-> a_i = 1;
        dut-> b_i = 1;
    }
}

int main(int argc,char** argv,char** env)
{
    Vgates *dut =new Vgates;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    while(sim_time<7)
    {
        input_values(dut);
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS);
}