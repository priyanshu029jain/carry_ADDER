# 1. Read Sky130 Liberty model and netlist
read_liberty sky130.lib
read_verilog gate_level_cla.v
link_design Carry_lookAhead_adder

# 2. Set realistic input driving cells and output loads
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_1 [all_inputs]
set_load 0.05 [all_outputs]

# 3. Create a dummy virtual clock (100 MHz / 10ns period) to anchor timing
create_clock -name vclk -period 10.0

# 4. Constrain inputs and outputs relative to the virtual clock
set_input_delay -clock vclk 0.0 [all_inputs]
set_output_delay -clock vclk 0.0 [all_outputs]

# 5. Report Critical Path Delay (Max propagation delay)
puts "\n================ CRITICAL PATH TIMING ================"
report_checks -path_delay max -fields {capacitance slew input_pins fanout} -digits 4

# 6. Report Power Breakdown
puts "\n================ POWER CONSUMPTION ================"
report_power -digits 4
