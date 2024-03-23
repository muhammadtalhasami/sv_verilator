## INTRODUCTION
This repo is basically an implementation of and gate on system verilog and we use verilator tool to create its test bench

There are 2 testbench
```
1-  simple and_gate_tb.cpp

2-  while loop andw_gate_tb.cpp
```

## TEST CASES

we have 2 inputs a & b so we have 4 test cases with its output
```
a b o
0 0 0
0 1 0
1 0 0
1 1 1
```

## COMPILATION STEPS

For simple and_gate_tb.cpp
```
1- verilated -Wall -trace and_gate.sv -exe and_gate_tb.cpp

2- make -C obj_dir -f Vand_gate.mk Vand_gate

3- ./obj_dir/Vand_gate

4- gtkwave waveform.vcd
```

while loop andw_gate_tb.cpp

Just replace the and_gate_tb.cpp with andw_gate_tb.cpp in the first line rest of the flow is same
```
1- verilated -Wall -trace and_gate.sv -exe andw_gate_tb.cpp

2- make -C obj_dir -f Vand_gate.mk Vand_gate

3- ./obj_dir/Vand_gate

4- gtkwave waveform.vcd
```

**1-** verilated -Wall -trace and_gate.sv -exe and_gate_tb.cpp
```
verilated:- This is the command-line executable for Verilator.

-Wall:_  Turn on all C++ warnings. Not required, but useful when you’re just starting out

--trace:- Enable waveform tracing

and_gate.sv:- Your system verilog design module

-exe:- This option indicates that you want Verilator to generate an executable for simulation.

and_gate_tb.cpp:- Your cpp testbench file 
```

**2-** make -C obj_dir -f Vand_gate.mk Vand_gate
```
[ -C obj_dir ] tells [ make ] to work in the obj_dir directory.

We then pass the required makefile using -f Vand_gate.mk.

Lastly, we tell make to build the target Vand_gate,

which is the name of the compiled testbench executable.

If the testbench executable was built successfully, you will find a Vand_gate binary in obj_dir.
```

**3-** ./obj_dir/Vand_gate
```
Once built, simply run the Vand_gate binary to run the simulation:
```

**4-** gtkwave waveform.vcd
```
You can open the aforementioned Verilator waveform dump file using GTKwave:
```
