## INTRODUCTION


![Screenshot from 2024-04-01 01-57-34](https://github.com/muhammadtalhasami/sv_verilator/assets/141629485/b93c83bb-d087-46ee-a2c1-e63c580cc7f7)

![Screenshot from 2024-04-01 01-55-07](https://github.com/muhammadtalhasami/sv_verilator/assets/141629485/b93c83bb-d087-46ee-a2c1-e63c580cc7f7)

always_latch is equivalent to always @(clk, d) and is the pre­
ferred idiom for describing a latch in SystemVerilog. It evaluates
whenever clk or d changes. If clk is HIGH, d flows through
to q, so this code describes a positive level-sensitive latch.
Otherwise, q keeps its old value. SystemVerilog can generate a
warning if the always_latch block doesn’t imply a latch.

# HOW YOU CAN USE IT

```
clone my repo then run make
1- make

2- make waves
```

# CONTRIBUTION
