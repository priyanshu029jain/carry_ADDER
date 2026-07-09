#!/bin/bash

# Check if the user provided a folder name
if [ -z "$1" ]; then
    echo "❌ Error: Please specify which adder you want to simulate."
    echo "💡 Usage:  sh run.sh <folder_name>"
    echo "📌 Example: sh run.sh Carry_lockAhead_adder"
    echo ""
    echo "Available modules:"
    ls -d */ | sed 's/\///g' # Lists all subdirectories cleanly
    exit 1
fi

TARGET_DIR=$1

# Check if the requested directory actually exists
if [ ! -d "$TARGET_DIR" ]; then
    echo "❌ Error: Directory '$TARGET_DIR' not found."
    exit 1
fi

echo "📂 Navigating to $TARGET_DIR..."

# Find the testbench and design file dynamically inside the target folder
# This matches files ending with _adder.v or .v, and tb_*.v
DESIGN_FILE=$(find "$TARGET_DIR" -maxdepth 1 -name "*.v" ! -name "tb_*.v" | head -n 1)
TB_FILE=$(find "$TARGET_DIR" -maxdepth 1 -name "tb_*.v" | head -n 1)

if [ -z "$DESIGN_FILE" ] || [ -z "$TB_FILE" ]; then
    echo "❌ Error: Could not find both design and testbench files inside '$TARGET_DIR'."
    exit 1
fi

echo "🔨 Compiling with iverilog..."
echo "🔸 RTL: $DESIGN_FILE"
echo "🔸 TB:  $TB_FILE"

# Compile inside the target directory to keep outputs contained
iverilog -o "$TARGET_DIR/CLA.vvp" "$TB_FILE"

if [ $? -eq 0 ]; then
    echo "🚀 Running simulation..."
    vvp "$TARGET_DIR/CLA.vvp"
    echo "✅ Simulation finished successfully!"
else
    echo "❌ Compilation failed!"
    exit 1
fi