#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vup_counter.h" // Include the header file for the Verilog module

#define FINISH_TIME 20
vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {
    // Instantiate the module
    Vup_counter* test = new Vup_counter;

    // Enable tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    test->trace(m_trace, 0);
    m_trace->open("waveform.vcd");

    // Initialize clock and reset
    test->clk = 1;
    test->rst = 1;

    // Initial evaluation
    test->eval();
    m_trace->dump(sim_time);

    // Simulation loop
    while (sim_time < FINISH_TIME) {
        sim_time++;

        // Toggle clock
        test->clk = !test->clk;

        // Toggle reset after some cycles
        if (sim_time == 1)
            test->rst = 0;

        // Evaluate the module
        test->eval();
        m_trace->dump(sim_time);
    }

    // Close VCD trace and clean up
    m_trace->close();
    delete test;
    return 0;
}
