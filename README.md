# 4-Bit Adder Architectures — RTL to Silicon

A study of binary adder architectures, built up from a half adder to four 4-bit multi-bit adders. Every design is written in **gate-level Verilog**. Each one is simulated, drawn in Logisim, and synthesized for an FPGA (Xilinx Artix-7). Selected designs are also taken further:

- **Verification:** self-checking testbenches, Verilator code coverage, and SymbiYosys formal proofs.
- **ASIC flow:** Yosys synthesis and OpenSTA timing/power analysis on the **SkyWater Sky130** standard-cell library.

---

## Repository layout

```text
carry_ADDER/
├── half_adder/                   Half adder (XOR + AND)
├── full_adder_with_half_adder/   Full adder #1 — two half adders + OR
├── full_adder_with_mux/          Full adder #2 — XOR sum, mux-selected carry
├── full_adder_with_xor/          Full adder #3 — 3-input XOR + majority carry
├── Ripple_carry_adder/           4-bit RCA (4 × full_adder3)
├── Carry_select_adder/           4-bit CSLA (2 × RCA + output muxes)
├── Carry_lockAhead_adder/        4-bit CLA (parallel generate/propagate carries)
├── Carry_Bypass_adder/           4-bit carry-bypass / skip adder (RCA + skip logic)
├── full_adder.md                 Comparison of the three full-adder designs
└── run.sh                        Helper script for Icarus Verilog simulation
```

Each design folder follows the same pattern:

| File / folder | Contents |
|---|---|
| `<design>.v` | Gate-level RTL |
| `tb_<design>.v` | Icarus Verilog testbench |
| `tb_<design>.cpp` | Verilator C++ testbench (RCA, CLA, CBA) |
| `<design>.md` | Write-up of the implementation and its PPA (power, performance, area) |
| `<design>.circ`, `.jpg` | Logisim schematic and its export |
| `<design>.svg` | RTL schematic |
| `images/` | Waveform, synthesized schematic, floorplan, pin mapping |
| `reports/` | Vivado timing, power, and utilization reports |

---

## Designs

### Building blocks

| Module | Structure | Sum | Carry |
|---|---|---|---|
| `half_adder` | 1 XOR, 1 AND | `A ^ B` | `A & B` |
| `full_adder1` | 2 half adders + OR | `A ^ B ^ C` | `HA1.C \| HA2.C` |
| `full_adder2` | 2 XOR + 2:1 mux | `A ^ B ^ C` | `(A^B) ? C : B` |
| `full_adder3` | 3-input XOR + majority | `A ^ B ^ C` | `AB + AC + BC` |

`full_adder3` is the building block used by all the multi-bit adders.

### 4-bit adders

All four share the same interface: `A[3:0]`, `B[3:0]`, `Cin` → `S[3:0]`, `Cout`.

| Adder | Idea | Critical path |
|---|---|---|
| **Ripple Carry (RCA)** | Chain 4 full adders; each carry feeds the next stage | Grows linearly with bit width (Cin → c1 → c2 → c3 → Cout) |
| **Carry Select (CSLA)** | Compute the sum twice in parallel (Cin = 0 and Cin = 1), then pick one with a mux driven by Cin | One RCA + one mux |
| **Carry Look-Ahead (CLA)** | `Gi = Ai·Bi`, `Pi = Ai⊕Bi`; every carry is a two-level sum of products of G/P/Cin | Constant depth (wide AND/OR gates) |
| **Carry Bypass (CBA)** | RCA plus skip logic: if `P0·P1·P2·P3 = 1`, `Cout = Cin`; otherwise `Cout = ripple carry` | Ripple path, with the carry able to skip the block |

> **Note on the CBA:** with only one 4-bit block, the skip path gives the same `Cout` as the ripple path, and the sum still ripples. The skip logic only pays off when several blocks are chained, e.g. 4 × 4-bit for a 16-bit adder.

---

## Results

### FPGA — Xilinx Artix-7 `xc7a35tcsg324-1`, Vivado 2025.2 (post-synthesis)

| Design | Slice LUTs | Worst-case delay | Total on-chip power |
|---|---:|---:|---:|
| Half adder | 1 | 6.869 ns | 0.734 W |
| Full adder #1 (half adders) | 1 | 6.858 ns | 0.972 W |
| Full adder #2 (mux) | 1 | 6.858 ns | 0.972 W |
| Full adder #3 (XOR/majority) | 1 | 2.074 ns\* | 0.999 W |
| Ripple Carry | 4 | 6.885 ns | 2.944 W |
| Carry Select | 5 | 6.879 ns | 2.766 W |
| Carry Look-Ahead | 4 | 5.950 ns | 3.049 W |
| Carry Bypass | 4 | 5.950 ns | 3.048 W |

\* Measured without I/O buffer delay. The other delays are pad-to-pad, and most of their power comes from I/O buffers, so these numbers compare the designs with each other rather than measure the logic alone. Full details are in each design's `.md` and `reports/`.

### ASIC — Sky130 (`sky130_fd_sc_hd`, tt_025C_1v80), Yosys + OpenSTA

| Design | Mapped cells | Area | Data arrival | Constraint |
|---|---|---:|---:|---|
| Ripple Carry | 4 × `maj3_1`, 4 × `xor3_1` | 135.13 µm² | 2.49 ns (incl. 1 ns input delay) | 10 ns clock, slack **+6.51 ns** |
| Carry Look-Ahead | `maj3`, `xnor2`, … (see synthesis report) | — | 2.06 ns | 10 ns virtual clock, slack **+7.94 ns** |

Sky130 has `maj3` and `xor3` cells, so each full adder maps to just two cells. This makes the 4-bit RCA very compact.

Reports are in [Ripple_carry_adder/area_report.txt](Ripple_carry_adder/area_report.txt), [Ripple_carry_adder/power_timing_report.txt](Ripple_carry_adder/power_timing_report.txt) and [Carry_lockAhead_adder/scripts/reports/](Carry_lockAhead_adder/scripts/reports/).

---

## Verification

| Design | Simulation | Code coverage | Formal |
|---|---|---|---|
| Half / full adders | Directed vectors | — | — |
| Ripple Carry | Exhaustive 512 vectors, self-checking scoreboard | Verilator + lcov | SymbiYosys `prove` ✅ |
| Carry Select | Directed vectors (`$monitor`) | — | — |
| Carry Look-Ahead | Exhaustive 512 vectors, self-checking scoreboard; gate-level sim of the Sky130 netlist | Verilator + lcov | SymbiYosys `prove` ✅ |
| Carry Bypass | 200 random + directed corner cases, self-checking scoreboard | Verilator (in progress) | — |

The formal property checks the adder against the arithmetic result for **every** input:

```verilog
always @(*) assert ({Cout, S} == A + B + Cin);
```

---

## Getting started

### Tools

| Purpose | Tool |
|---|---|
| Simulation | [Icarus Verilog](https://steveicarus.github.io/iverilog/) + GTKWave |
| Lint / coverage | [Verilator](https://www.veripool.org/verilator/) + lcov |
| Formal | [SymbiYosys](https://github.com/YosysHQ/sby) with the Yices SMT solver |
| ASIC synthesis | [Yosys](https://github.com/YosysHQ/yosys) |
| Static timing / power | [OpenSTA](https://github.com/The-OpenROAD-Project/OpenSTA) |
| FPGA synthesis | Xilinx Vivado |
| Schematic | Logisim Evolution |

### Simulate (Icarus Verilog)

Run these from the repository root; the `` `include `` paths are relative to it.

```bash
# Carry look-ahead (self-contained)
iverilog -o CLA.vvp Carry_lockAhead_adder/tb_CLA.v && vvp CLA.vvp

# Ripple carry
iverilog -o RCA.vvp full_adder_with_xor/full_adder3.v Ripple_carry_adder/tb_RCA.v && vvp RCA.vvp

# Carry select
iverilog -o CSLA.vvp full_adder_with_xor/full_adder3.v Carry_select_adder/tb_CSLA.v && vvp CSLA.vvp

# Carry bypass
iverilog -o CBA.vvp full_adder_with_xor/full_adder3.v Ripple_carry_adder/Ripple_carry_adder.v \
         Carry_Bypass_adder/Carry_bypass_adder.v Carry_Bypass_adder/tb_CBA.v && vvp CBA.vvp

# View waveforms
gtkwave CLA.vcd
```

`sh run.sh <folder>` runs the same flow automatically, but for now it only works for self-contained testbenches such as `Carry_lockAhead_adder`.

A passing self-checking run ends with:

```text
=======================================================
TEST COMPLETION SUMMARY
=======================================================
Total Tests Run: 512
Tests Passed:    512
Tests Failed:    0
RESULT: 🏆 PASS! All inputs tested, zero errors.
```

### Code coverage (Verilator)

```bash
cd Ripple_carry_adder
verilator --cc --exe --build --coverage -Wno-fatal \
    ../full_adder_with_xor/full_adder3.v Ripple_carry_adder.v tb_RCA.cpp \
    --top-module Ripple_carry_adder
./obj_dir/VRipple_carry_adder
verilator_coverage --write-info logs/coverage.info logs/coverage.dat
genhtml logs/coverage.info -o coverage_html
```

### Formal proof (SymbiYosys)

```bash
cd Ripple_carry_adder && sby -f formal_rca.sby      # RCA
cd Carry_lockAhead_adder && sby -f cla_formal.sby   # CLA
```

### ASIC synthesis and STA (Sky130)

```bash
cd Ripple_carry_adder
yosys -s synth.ys | tee area_report.txt             # writes rca_mapped.v
sta run_sta.tcl | tee power_timing_report.txt

cd ../Carry_lockAhead_adder/scripts
yosys -s synth_asic.ys
sta run_sta.tcl
```

The Sky130 Liberty file used by both flows is at `Carry_lockAhead_adder/scripts/sky130.lib`.

---

## Roadmap

- [ ] Replace `` `include `` with per-design `.f` file lists so iverilog, Verilator, Yosys and SBY can share them
- [ ] Make `run.sh` work for every design
- [ ] Self-checking testbench and formal proof for the Carry Select adder
- [ ] Formal proof and finished Verilator coverage for the Carry Bypass adder
- [ ] Sky130 ASIC flow for the CSLA and CBA
- [ ] Scale the adders to 16 bits to show the real differences between the architectures

---

## Author

**Priyanshu Jain** — IIITM Gwalior
