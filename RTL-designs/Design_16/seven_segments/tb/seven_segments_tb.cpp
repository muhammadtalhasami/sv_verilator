#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Vseven_segments.h"

vluint64_t sim_time = 0;

void read_values(Vseven_segments* dut){
    if(sim_time == 0 && sim_time < 2){
        dut->data= 0;
    }
    else if(sim_time == 2 && sim_time < 4){
        dut->data= 1;
    }
    else if(sim_time == 4 && sim_time < 6){
        dut->data= 2;
    }
    else if(sim_time == 6 && sim_time < 8 ){
        dut->data= 3;
    }
    else if(sim_time == 8 && sim_time < 10 ){
        dut->data= 4;
    }
    else if(sim_time == 10 && sim_time < 12 ){
        dut->data= 5;
    }
    else if(sim_time == 12 && sim_time < 14 ){
        dut->data= 6;
    }
    else if(sim_time == 14 && sim_time < 16 ){
        dut->data= 7;
    }
    else if(sim_time == 16 && sim_time < 18 ){
        dut->data= 8;
    }
    else if(sim_time == 18 && sim_time < 20 ){
        dut->data= 9;
    }
}

int main(int argc,char** argv,char** env)
{
    Vseven_segments *dut =new Vseven_segments;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    while(sim_time<=20)
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