#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vup_counter.h"

#define SIM_DURATION 30 

int main(int argc, char** argv, char** env) {
    Vup_counter* test = new Vup_counter;

    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    test->trace(m_trace, 4);
    m_trace->open("waveform.vcd");

    test->clk = 0; // Initialize the clock to 0
    test->rst = 1;
    test->eval();
    m_trace->dump(0.25); // Dump initial state at 0.25ps

    for (float i = 0; i < SIM_DURATION; i += 0.5) {
        test->clk = !test->clk; // Toggle the clock at every iteration

        if (i == 0.25) // Set reset pulse at 0.25ps
            test->rst = 0;
        else if (i == 0.75) // Reset deasserted at 0.75ps
            test->rst = 1;

        test->eval();
        m_trace->dump(i + 0.25); // Dump at each rising edge of the clock

        printf("Time %.2f: Counter value = %d\n", i + 0.25, test->q);
    }

    m_trace->close();
    delete test;
    delete m_trace;
    return 0;
}
