#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vadd.h"

#define MAX_SIM_TIME 3
vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {
    Vadd *dut = new Vadd;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 0);
    m_trace->open("waveform.vcd");

    while (sim_time <= MAX_SIM_TIME) {


        dut->a_i = 0;
        dut->b_i = 0;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;

        dut->a_i = 0;
        dut->b_i = 1;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;

        dut->a_i = 1;
        dut->b_i = 0;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;


        dut->a_i = 1;
        dut->b_i = 1;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
