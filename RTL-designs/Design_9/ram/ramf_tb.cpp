#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vram.h"

#define MAX_TIME 20

vluint64_t sim_time = 0;

void perform_write(Vram* dut) {
    dut->en = 0;
    dut->wr = 0;
    dut->add++;
    dut->w_data = dut->w_data++;
}

void perform_read(Vram* dut) {
    dut->wr = 1;
}

int main(int argc, char** argv, char** env) {
    Vram* dut = new Vram;

    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 0);
    m_trace->open("waveform.vcd");

    dut->clk = 0;
    dut->en = 1;

    while (sim_time < MAX_TIME) {
        dut->clk = !dut->clk;
        dut->eval();
        m_trace->dump(sim_time);

        if (dut->clk == 0) {
            if (dut->en == 1) {
                perform_write(dut);
            } else if(dut-> wr == 1) {
                perform_read(dut);
            }
        }
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
