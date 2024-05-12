#include<verilated.h>
#include<verilated_vcd_c.h>
#include"Valu.h"

#define MAX_TIME 20
vluint64_t sim_time = 0;

void op_sel(Valu* dut){
    if(sim_time == 0){
        dut->op_i = 0;
    }
    else{
        dut-> op_i++;
    }
}

void operands_values(Valu* dut){
    if(sim_time == 0 && sim_time < 3){
        dut-> a_i = 10;
        dut-> b_i = 9;
    }
    else if(sim_time == 3){
        dut-> a_i = -10;
        dut-> b_i = -3; 
    }
    else if(sim_time == 4){
        dut-> a_i = 10;
        dut-> b_i = 3;        
    }
    else if(sim_time > 4 && sim_time < 6){
        dut-> a_i = 10;
        dut-> b_i = 9;
    }
    else if(sim_time == 6 && sim_time <8){
        dut-> a_i = 204;
        dut-> b_i = 3;
    }
    else if(sim_time ==8 && sim_time < 10){
        dut-> a_i = 10;
        dut-> b_i = 9;
    }
}

int main(int argc,char** argv,char** env)
{
    Valu *dut =new Valu;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace=new VerilatedVcdC;
    dut->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    while(sim_time<11)
    {
        operands_values(dut);
        op_sel(dut);
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit (EXIT_SUCCESS);
}