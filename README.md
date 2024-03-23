## INTRODUCTION
SystemVerilog is a hardware description and verification language used primarily in the design, verification, and implementation of digital systems, 
especially in the field of electronic design automation (EDA). 
It is an extension of the Verilog hardware description language (HDL) and 
encompasses additional features for design, verification, and testbench development.

## WHY SYSTEM_VERILOG NOT VERILOG
Verilog was the primary language to verify the functionality of designs that were small not were complex and had a less features
as the design complexity increases we need a better tool for the designs and verification. System verilog is far superior then
the verilog because of it ability too perform the constrained random stimuli, use OOP feature in testbench

## WHAT IS VERILATOR
Verilator is a tool that compiles Verilog and SystemVerilog sources to highly optimized (and optionally multithreaded) cycle-accurate C++ or SystemC code. 
The converted modules can be instantiated and used in a C++ or a SystemC testbench, for verification and/or modelling purposes.

## WHY WE USE VERILATOR
Verilator is essentially a Verilog/SystemVerilog simulator. It’s commercial-grade, super fast, free and open source, but it is not a direct replacement 
for Modelsim, Questa Sim, Synopsys VCS, Vivado Xsim, and other event-based simulators. Verilator is a cycle-based simulator, which means it does not 
evaluate time within a single clock cycle, and does not simulate exact circuit timing. Instead, the circuit state is typically evaluated once per clock-cycle, 
so any intra-period glitches cannot be observed, and timed signal delays are not supported. This has both benefits and drawbacks when comparing Verilator to other simulators.



