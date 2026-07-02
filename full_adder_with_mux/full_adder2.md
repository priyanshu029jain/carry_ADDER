# Entity: full_adder2
- **File**: full_adder2.v

## Diagram
![Diagram](full_adder2_schematic.png "RTL MUX-Based Primitive Layout")

## Ports

| Port name | Direction | Type | Description |
| --------- | --------- | ---- | ----------- |
| A         | input     | wire | Addend input bit A |
| B         | input     | wire | Addend input bit B |
| C         | input     | wire | Carry-in input bit C |
| SUM       | output    | wire | Combinational Sum output bit |
| COUT      | output    | wire | Combinational Carry-out output bit |

## Hardware Performance Matrix (PDA Analysis)

[cite_start]The implementation was compiled, placed, routed, and benchmarked using AMD/Xilinx Vivado ML v2025.2 [cite: 2] [cite_start]targeting an Artix-7 FPGA (`xc7a35tcsg324-1`) [cite: 7] [cite_start]under typical manufacturing process conditions [cite: 9] [cite_start]and standard $25^\circ\text{C}$ room temperature environments[cite: 79].

| Parameter | Measured Value | Functional Details & Silicon Observations |
| :--- | :--- | :--- |
| **Logic Area** | [cite_start]1 Slice LUT [cite: 173] | [cite_start]Leverages dual-output slice sharing; packs 2 logical `LUT3` expressions into 1 physical cell site[cite: 203, 263]. |
| **I/O Pin Count** | [cite_start]5 Bonded IOBs [cite: 225] | [cite_start]Connects physical package pins for external ports: `A`, `B`, `C`, `SUM`, `COUT`[cite: 130, 138]. |
| **Worst-Case Delay ($T_{pd}$)** | [cite_start]6.858 ns [cite: 131] | [cite_start]Maximum propagation path time tracked from external Input `A` to Output `COUT`[cite: 130]. |
| **Logic Component Delay** | [cite_start]3.945 ns [cite: 131] | [cite_start]Accumulative transistor primitive switching delay across logic cells (57.5% of total path)[cite: 131]. |
| **Routing Net Delay** | [cite_start]2.912 ns [cite: 131] | [cite_start]Interconnect copper trace wire propagation overhead across the fabric matrix (42.5% of total path)[cite: 131]. |
| **Total On-Chip Power** | [cite_start]0.972 W [cite: 11] | [cite_start]Total thermal power generated across the device architecture[cite: 11]. |
| **Dynamic Power** | [cite_start]0.900 W [cite: 15] | [cite_start]Active operational power profile (92.6% of overall consumption), driven by switching states[cite: 15]. |
| **Device Static Power** | [cite_start]0.072 W [cite: 16] | [cite_start]Baseline idle silicon substrate leakage power (7.4% of total power profile)[cite: 16]. |

---

## Key Engineering Insights

* [cite_start]**Mux-to-LUT Substrate Mapping:** Even though your structural logic handles multiplexer configurations that map back into **2 independent `LUT3` logic equations** [cite: 263][cite_start], Vivado's physical optimizer successfully bound them into **exactly 1 physical Slice LUT**[cite: 173]. [cite_start]The engine implements this via a feature called *LUT Combining*, leveraging the fact that both equations share common inputs (`A`, `B`, `C`)[cite: 135]. [cite_start]It instructs the hardware cell to run in **"using O5 and O6" dual-output mode** [cite: 203][cite_start], generating `SUM` and `COUT` concurrently from a single physical LUT slot [cite: 135, 143] to yield a layout footprint of $<0.01\%$ total device area[cite: 175].
* [cite_start]**Capacitive I/O Energy Footprint:** Over **97.4% of all active dynamic power** ($0.877\text{ W}$ out of $0.900\text{ W}$) is dissipated purely by the 5 package pin drivers (`IBUF` / `OBUF` primitives)[cite: 33, 262, 263]. [cite_start]Because internal signal net toggling only accounts for a tiny $0.019\text{ W}$[cite: 32], the thermal energy profile is almost exclusively determined by charging and discharging structural PCB line capacitances connected to the outside board layout.

---

## Physical Implementation Layouts

### A. Physical Package Pin Routing
The physical package die map displaying where inputs (`A`, `B`, `C`) and structural output pin boundaries are located across the Artix-7 microball matrix layout grid.
![Package Pin View](full_adder2_pin_mapping.png)

### B. FPGA Fabric Floorplan Utilization
Visualizes the targeted placement coordinate metrics highlighting the exact physical cell where the consolidated lookup table block runs on the silicon chip substrate.
![FPGA Die Floorplan](full_adder2_floorplan.png)

---

## Reproducibility & Raw Verification Data

The unedited raw text verification logs generated directly by Vivado's core hardware execution engines are fully available for review:
* 📄 [Propagation Delay & Timing Summary Report](full_adder2_timing_report.txt)
* 📄 [Thermal Power Distribution Report](full_adder_power_report.txt)
* 📄 [Hardware Resource Utilization Report](full_adder2_utilization_report.txt)