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

# Open a log file for report output
set report_file [open "reports/sta_report.txt" w]

# Helper proc to print to both console and report file
proc log_puts {file msg} {
    puts $msg
    puts $file $msg
}

# 4. Critical Path Timing & Signal Integrity
log_puts $report_file "================ CRITICAL PATH & SIGNAL INTEGRITY ================"
puts $report_file [report_checks -path_delay max -fields {capacitance slew input_pins fanout} -digits 4]
report_checks -path_delay max -fields {capacitance slew input_pins fanout} -digits 4

# 5. Check Design Setup
log_puts $report_file "\n================ DESIGN RULE & CONSTRAINT CHECKS ================"
puts $report_file [check_setup -verbose]
check_setup -verbose

# 6. Probabilistic Power Analysis
log_puts $report_file "\n================ PROBABILISTIC DYNAMIC POWER ================"
set_power_activity -input -activity 0.2
puts $report_file [report_power -digits 4]
report_power -digits 4

close $report_file
