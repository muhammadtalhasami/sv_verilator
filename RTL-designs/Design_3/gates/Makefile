MODULE=gates
SRC_DIR= src
TB_DIR = tb
.PHONY:sim
sim: waveform.vcd

.PHONY:waves
waves: waveform.vcd
	gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE)
	@./obj_dir/V$(MODULE)

./obj_dir/V$(MODULE): .stamp.verilate
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(SRC_DIR)/$(MODULE).sv $(TB_DIR)/$(MODULE)_tb.cpp
	verilator -Wall --trace -cc $(SRC_DIR)/$(MODULE).sv --exe $(TB_DIR)/$(MODULE)_tb.cpp

.PHONY:lint
lint: $(SRC_DIR)/$(MODULE).sv
	verilator --lint-only $(SRC_DIR)/$(MODULE).sv

.PHONY: clean
clean:
	rm -rf ./obj_dir
	rm -rf waveform.vcd
