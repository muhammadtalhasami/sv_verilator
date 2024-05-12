#include <verilated.h>
#include <verilated_vcd_c.h>
#include <Vmux.h>

#define MAX_TIME 3
vluint64_t sim_tim =0;

int main(int argc ,char** argv ,char** env){
    Vmux *dut = new Vmux;

    Verilated::traceEverOn(true);
    VerilatedVcdC * m_trace= new VerilatedVcdC;
    dut ->trace(m_trace,0);
    m_trace->open("waveform.vcd");

    dut->a_i=0;
    dut->b_i=0;
    dut->sel_i=0;
    dut->eval();
    m_trace->dump(sim_tim);
    sim_tim++;

    dut->a_i=0;
    dut->b_i=0;
    dut->sel_i=1;
    dut->eval();
    m_trace->dump(sim_tim);
    sim_tim++;

    dut->a_i=1;
    dut->b_i=0;
    dut->sel_i=1;
    dut->eval();
    m_trace->dump(sim_tim);
    sim_tim++;

    dut->a_i=0;
    dut->b_i=1;
    dut->sel_i=0;
    dut->eval();
    m_trace->dump(sim_tim);
    sim_tim++;

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);

}

