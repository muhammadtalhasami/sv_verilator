#include<verilated.h>
#include<verilated_vcd_c.h>
#include<Vup_counter.h>

#define FINISH_TIME 20
vluint64_t sim_tim = 0;


int main(int argc, char** argv,char** env){
    Vup_counter *test = new Vup_counter;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    test -> trace(m_trace,4);
    m_trace->open("waveform.vcd");

    // while(sim_tim< FINISH_TIME)
    // {
        test -> clk = 1;
        test -> rst = (sim_tim<1)?1:0;
        test -> eval();
        m_trace->dump(sim_tim);
        sim_tim+=0.5;

        test -> clk = 0;
        test -> rst = 0;
        test -> eval();
        m_trace->dump(sim_tim);
        sim_tim+=0.5;

        test -> clk = 1;
        test -> eval();
        m_trace->dump(sim_tim);
        sim_tim+=0.5;


        test -> clk = 0;
        test -> eval();
        m_trace->dump(sim_tim);
        sim_tim+=0.5;
    // }

    m_trace->close();
    delete test;
    exit(EXIT_SUCCESS); 
}