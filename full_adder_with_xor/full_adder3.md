# Entity: full_adder3
- **File**: full_adder3.v

## Diagram
![Diagram](full_adder3_schematic.png "RTL XOR-Based Primitive Layout")

## Ports

| Port name | Direction | Type | Description |
| --------- | --------- | ---- | ----------- |
| A         | input     | wire | Addend input bit A |
| B         | input     | wire | Addend input bit B |
| C         | input     | wire | Carry-in input bit C |
| SUM       | output    | wire | Combinational Sum output bit |
| COUT      | output    | wire | Combinational Carry-out output bit |

## Hardware Performance Matrix (PDA Analysis)

The implementation was compiled, optimized, and analyzed using AMD/Xilinx Vivado ML v2025.2 targeting an Artix-7 FPGA (`xc7a35tcsg324-1`). This snapshot represents the metrics calculated directly at the **Synthesized Design** stage under standard $25^\circ\text{C}$ room temperature conditions.

| Parameter | Measured Value | Functional Details & Silicon Observations |
| :--- | :--- | :--- |
| **Logic Area** | 1 Slice LUT | Synthesized and optimized down into a single physical lookup cell structure. |
| **I/O Pin Count** | 5 Bonded IOBs | Represents physical package pin allocation targets for: `A`, `B`, `C`, `SUM`, `COUT`. |
| **Worst-Case Delay ($T_{pd}$)** | 2.074 ns | *Synthesized Pre-Route Estimate:* Delay baseline measured from Input `B` to Output `COUT`. |
| **Logic Component Delay** | 1.400 ns | Internal lookup cell and primitive transistor switching time (67.5% of path). |
| **Routing Net Delay** | 0.674 ns | Unplaced/Unrouted structural interconnect network estimation (32.5% of path). |
| **Total On-Chip Power** | 0.927 W | Total estimated power signature under synthesized conditions. |
| **Dynamic Power** | 0.855 W | Active switching power component representing 92.2% of the overall power profile. |
| **Device Static Power** | 0.072 W | Baseline silicon substrate idle leakage current power draw (7.8% of power profile). |

---

## Key Engineering Insights

* **Synthesized Logic Density:** In the structural XOR/AND boolean arrangement, Vivado's logic translator successfully condenses the underlying logical network into **2 independent `LUT3` expressions**. Due to shared inputs across the full adder equations, the synthesis optimizer configures these functions to map onto **exactly 1 physical Slice LUT**. By utilizing the Artix-7's dual-output logic architecture, the engine routes both independent outputs from a single lookup table block site.
* **Pre-Route vs. Routed Delay Analysis:** Notice that the worst-case propagation path delay at this stage is **2.074 ns**, compared to the ~6.858 ns seen on your fully routed blocks. This is because a *Synthesized* design hasn't gone through physical Place & Route (P&R) yet; it uses an ideal, localized wire model estimate ($0.674\text{ ns}$ routing net delay) before the copper paths are stretched out across the physical distances of the actual FPGA die fabric.
* **I/O Pad Power Distribution:** Active dynamic power dissipation ($0.855\text{ W}$) is heavily dominated by the external board-level demands of driving high-capacitance physical interface pins. Internal logic cell operations require less than $3\%$ of the operational power loop.

---

## Physical Implementation Layouts

### A. Physical Package Pin Routing
The physical package die map displaying where inputs (`A`, `B`, `C`) and structural output pin boundaries are located across the Artix-7 microball matrix layout grid.
![Package Pin View](full_adder3_pin_mapping.png)

### B. FPGA Fabric Floorplan Utilization
Visualizes the targeted placement coordinate metrics highlighting the exact physical cell where the consolidated lookup table block runs on the silicon chip substrate.
![FPGA Die Floorplan](full_adder3_floorplan.png)

---

## Reproducibility & Raw Verification Data

The unedited raw text verification logs generated directly by Vivado's core hardware execution engines are fully available for review:
* 📄 [Propagation Delay & Timing Summary Report](full_adder3_timing_report.txt)
* 📄 [Thermal Power Distribution Report](full_adder3_power_report.txt)
* 📄 [Hardware Resource Utilization Report](full_adder3_utilization_report.txt)