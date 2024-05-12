#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vhalf_adder.h"

vluint64_t sim_time = 0;

void read_values(Vhalf_adder* dut){
    if(sim_time == 0 && sim_time < 2){
        dut->a= 0;
        dut->b= 0;
    }
    else if(sim_time == 2 && sim_time < 4){
        dut->a= 0;
        dut->b= 1;
    }
    else if(sim_time == 4 && sim_time < 6){
        dut->a= 1;
        dut->b= 0;
    }
    else if(sim_time == 6 && sim_time < 8 ){
        dut->a= 1;
        dut->b= 1;
    }
}

int main(int argc,char** argv,char** env)
{
    Vhalf_adder *dut =new Vhalf_adder;

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