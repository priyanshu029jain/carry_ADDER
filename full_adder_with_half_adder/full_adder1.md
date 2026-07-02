# Entity: full_adder1 
- **File**: full_adder1.v

## Diagram
![Diagram](full_adder1_schematic.png "RTL Primitive Layout")

## Ports

| Port name | Direction | Type | Description |
| --------- | --------- | ---- | ----------- |
| A         | input     | wire | [cite_start]Addend input bit A [cite: 130, 141] |
| B         | input     | wire | Addend input bit B |
| C         | input     | wire | [cite_start]Carry-in input bit C [cite: 147, 150] |
| SUM       | output    | wire | [cite_start]Combinational Sum output bit (A ⊕ B ⊕ C) [cite: 139, 146] |
| COUT      | output    | wire | [cite_start]Combinational Carry-out output bit [cite: 130, 137] |

## Signals

| Name | Type | Description |
| ---- | ---- | ----------- |
| w1   | wire | Internal Sum wire from HA1 to HA2 |
| w2   | wire | Internal Carry wire from HA1 to final OR gate reduction |
| w3   | wire | Internal Carry wire from HA2 to final OR gate reduction |

## Instantiations

- **HA1**: `half_adder` — Computes the initial partial sum ($w_1$) and partial carry ($w_2$) of inputs `A` and `B`.
- **HA2**: `half_adder` — Computes the final `SUM` output and secondary partial carry ($w_3$) by combining $w_1$ and `C`.

---

## Hardware Performance Matrix (PDA Analysis)

[cite_start]The implementation was compiled, routed, and analyzed using AMD/Xilinx Vivado ML v2025.2 targeting an Artix-7 FPGA (`xc7a35tcsg324-1`) under typical manufacturing and standard environmental conditions ($25^\circ\text{C}$ ambient temperature, $0\text{ pF}$ load)[cite: 2, 7, 8, 9, 79].

| Parameter | Measured Value | Functional Details & Silicon Observations |
| :--- | :--- | :--- |
| **Logic Area** | [cite_start]1 Slice LUT [cite: 31, 175] | [cite_start]Mapped down into 1 physical look-up cell zone via dual-output combining[cite: 31, 203]. |
| **I/O Pin Count** | [cite_start]5 Bonded IOBs [cite: 33, 225] | [cite_start]Tracks hardware footprint for external ports: `A`, `B`, `C`, `SUM`, `COUT`[cite: 33, 225]. |
| **Worst-Case Delay ($T_{pd}$)** | [cite_start]6.858 ns [cite: 131] | [cite_start]Maximum combinational critical path propagation time tracked from Input `A` to Output `COUT`[cite: 129, 130, 131]. |
| **Logic Component Delay** | [cite_start]3.945 ns [cite: 131] | [cite_start]Active transistor propagation switching overhead across logic layers (57.5% of total path)[cite: 131]. |
| **Routing Net Delay** | [cite_start]2.912 ns [cite: 131] | [cite_start]Physical copper wire interconnect propagation overhead across the device routing fabric (42.5% of total path)[cite: 131]. |
| **Total On-Chip Power** | [cite_start]0.972 W [cite: 11, 35] | [cite_start]Combined thermal and operational power draw across the silicon die substrate[cite: 11, 35]. |
| **Dynamic Power** | [cite_start]0.900 W [cite: 14, 15] | [cite_start]Active switching power distribution (92.6% of total profile)[cite: 14, 15]. |
| **Device Static Power** | [cite_start]0.072 W [cite: 16, 34] | [cite_start]Core leakage power dissipation under idle resting substrate conditions (7.4% of total profile)[cite: 16, 34]. |

---

## Key Engineering Insights

* [cite_start]**Advanced LUT Optimization (LUT Combining):** Even though a structural architecture composed of two separate half-adders and an OR logic gate fundamentally relies on 2 distinct logic primitives (`LUT3` cells) [cite: 263][cite_start], Vivado's mapping optimizer successfully squeezed them both into **exactly 1 physical Slice LUT**[cite: 31, 175]. [cite_start]It takes advantage of the Artix-7 dual-output configuration (`using O5 and O6`) [cite: 203][cite_start], which allows two distinct equations with shared inputs to share a single slice site[cite: 183, 195]. This yields an ultra-compact logic density footprint ($<0.01\%$ total device area)[cite: 31, 175].
* [cite_start]**High-Current I/O Pad Dominance:** Consistent with small combinational logic blocks, over **97.4% of the dynamic power footprint** ($0.877\text{ W}$ out of $0.900\text{ W}$) is dissipated strictly inside the external input/output pad buffer blocks (`IBUF` and `OBUF`)[cite: 33, 15]. [cite_start]Internal logic switching power ($0.005\text{ W}$) is essentially negligible[cite: 31]. [cite_start]The energy profile is almost exclusively driven by charging and discharging the larger board-level capacitances tied to the physical package pins[cite: 33].

---

## Physical Implementation Layouts

### A. Physical Package Pin Routing
The physical package die map displaying where inputs (`A`, `B`, `C`) and structural output pin boundaries are located across the Artix-7 microball matrix layout grid.
![Package Pin View](full_adder1_pin_mapping.png)

### B. FPGA Fabric Floorplan Utilization
Visualizes the targeted placement coordinate metrics highlighting the exact physical cell where the consolidated lookup table block runs on the silicon chip substrate.
![FPGA Die Floorplan](full_adder1_floorplan.png)

---

## Reproducibility & Raw Verification Data

The unedited raw text verification logs generated directly by Vivado's core hardware execution engines are fully available for review:
* 📄 [Propagation Delay & Timing Report](full_adder1_timing_report.txt)
* 📄 [Thermal Power Distribution Report](full_adder1_power_report.txt)
* 📄 [Hardware Resource Utilization Report](full_adder1_utilization_report.txt)