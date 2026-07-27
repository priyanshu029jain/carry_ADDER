# Define a 10ns clock (100 MHz operating frequency)
create_clock -name clk -period 10.0

# Set input and output delays relative to the clock
set_input_delay -clock clk 1.0 [get_ports {A[*] B[*] Cin}]
set_output_delay -clock clk 1.0 [get_ports {S[*] Cout}]