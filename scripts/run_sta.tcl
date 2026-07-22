# 1. Read Sky130 Liberty model and netlist
read_liberty sky130.lib
read_verilog gate_level_cla.v
link_design Carry_lookAhead_adder

# 2. Set realistic driving cells and load constraints
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_1 [all_inputs]
set_load 0.05 [all_outputs]

# 3. Create virtual clock anchor (10ns period = 100MHz reference)
create_clock -name vclk -period 10.0
set_input_delay -clock vclk 0.0 [all_inputs]
set_output_delay -clock vclk 0.0 [all_outputs]

# 4. Critical Path Timing & Signal Integrity
puts "\n================ CRITICAL PATH & SIGNAL INTEGRITY ================"
report_checks -path_delay max -fields {capacitance slew input_pins fanout} -digits 4

# 5. Check Design Setup
puts "\n================ DESIGN RULE & CONSTRAINT CHECKS ================"
check_setup -verbose

# 6. Probabilistic Power Analysis
puts "\n================ PROBABILISTIC DYNAMIC POWER ================"
# Set activity on all inputs to 20% transitions per clock cycle
set_power_activity -input -activity 0.2
report_power -digits 4
