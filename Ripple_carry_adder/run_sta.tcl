# Point to your shared Sky130 library
set LIB_PATH "../Carry_lockAhead_adder/scripts/sky130.lib"

# 1. Read Liberty library and synthesized netlist
read_liberty $LIB_PATH
read_verilog rca_mapped.v
link_design Ripple_carry_adder

# 2. Read timing constraints
read_sdc rca.sdc

# 3. Generate and display Timing Report
puts "\n========================================="
puts "          MAX TIMING PATH REPORT         "
puts "========================================="
report_checks -path_delay max -fields {cap reg input netcell fanout}

# 4. Generate and display Power Report
puts "\n========================================="
puts "          POWER CONSUMPTION REPORT       "
puts "========================================="
report_power