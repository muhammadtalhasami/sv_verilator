#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vram.h"

#define MAX_TIME 20
vluint64_t sim_time = 0;

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

        dut->eval();    // no read write o[eration perform reason en 1
        m_trace->dump(sim_time);

        if (dut->clk == 0) {
            if(dut-> en==1){ 
                dut->en = 0;// write operation perform en =0
                dut->wr = 0;
                dut->add = 0;
                dut->w_data = 1; //write data
                dut->r_data = 0;
            }
            else if (dut->add == 0 && dut->wr == 0) { //write data
                dut->add =1;
                dut->w_data = 2;
            } else if (dut->add == 1 && dut->wr == 0) {//write datat
                dut->add =2;
                dut->w_data = 3;A
            } else if (dut->add == 2 && dut->wr == 0) {//write datat
                dut->add =3;                
                dut->w_data = 4;
            } else if (dut->add == 3 && dut->wr == 0) {//read datat
                dut->wr = 1; //wr 1 read data from address 0
                dut->add =0;
            }else if (dut->add == 0 && dut->wr == 1) { //read data
                dut->add =1;
            }else if (dut->add == 1 && dut->wr == 1) { //read data
                dut->add =2;
            }
            else if (dut->add == 2 && dut->wr == 1) { //read data
                dut->add =3;
            }    
           else if (dut->add == 3 && dut->wr == 1) {//write datat
                dut->wr = 0;
                dut->add =3;
            }                   
        }
        sim_time++;  
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
