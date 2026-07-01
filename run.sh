# ==============================================================================
# UNIFIED HARDWARE SIMULATION MAKEFILE
# ==============================================================================

# Toolchain configuration
SIM = iverilog
RUN = vvp
FLAGS = -g2001

# Directories
RTL_DIR = rtl
BENCH_DIR = bench
OUT_DIR = sim_build

# Default target when you just type 'make'
.PHONY: all clean
all: half_adder

# Ensure the build directory exists
init:
	@mkdir -p $(OUT_DIR)

# ------------------------------------------------------------------------------
# Target 1: Half Adder Module
# ------------------------------------------------------------------------------
half_adder: init
	@echo "🔨 Compiling Half Adder..."
	$(SIM) $(FLAGS) -o $(OUT_DIR)/half_adder.vvp $(RTL_DIR)/half_adder.v $(BENCH_DIR)/tb_half_adder.v
	@echo "🚀 Running Half Adder Simulation..."
	$(RUN) $(OUT_DIR)/half_adder.vvp
    
# ------------------------------------------------------------------------------
# Housekeeping: Clean up build artifacts
# ------------------------------------------------------------------------------
clean:
	@echo "🧹 Cleaning up simulation targets..."
	rm -rf $(OUT_DIR) *.vcd