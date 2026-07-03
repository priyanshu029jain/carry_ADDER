# Performance Report & Implementation Analysis: Carry Bypass Adder (CBA)

This report provides a comprehensive post-synthesis performance evaluation of the `Carry_skip_adder` module. The analysis is compiled directly from manufacturing execution reports generated using AMD/Xilinx Vivado ML v2025.2 targeting an Artix-7 FPGA (`xc7a35tcsg324-1`).

---

## 1. Executive Performance Matrix

The following table presents a summary of hardware metrics extracted from the post-synthesis reports:

| Performance Parameter | Metric Value | Architectural & Silicon Implications |
| :--- | :---: | :--- |
| **Design Execution State** | **Synthesized** (Pre-Route) | Represents an unplaced, optimized logic layout mapping. |
| **Total On-Chip Power** | 3.049 W | Complete active thermal profile at typical process node settings. |
| **Dynamic Power Component** | 2.970 W (97.4%) | Strongly dominated by predicted I/O buffer toggling currents. |
| **Device Static Power** | 0.078 W (2.6%) | Baseline transistor substrate leakage at $25^\circ\text{C}$. |
| **Worst-Case Delay ($T_{pd}$)** | 5.950 ns | Critical path measured under slow process corner constraints. |
| **Logic Component Delay** | 3.883 ns (65.3%) | Real gate switching execution delay across 3 logic levels. |
| **Routing Net Delay** | 2.066 ns (34.7%) | Synthesized routing estimation using generic localized interconnect vectors. |
| **Slice Lookup Tables (LUTs)** | 4 | Number of physical multi-input logic generators utilized. |
| **LUT Functional Distribution** | 4 × LUT5 | Fully mapped into explicit 5-input boolean primitives. |

---

## 2. Core Parametric Breakdown

### A. Resource Utilization & Substrate Mapping
According to the utilization report, the carry bypass network fits efficiently onto the specialized resources of the Artix-7 fabric:
* **Logic Footprint:** The complete structure maps into **4 Slice LUTs** (specifically utilizing four 5-input logic generators, or `LUT5` primitives). 
* **Registers & Muxes:** The module operates purely as a combinational layout, drawing **0 Slice Registers**, **0 latches**, and **0 multiplexer primitives**, avoiding sequential overhead.
* **Pin Count Overhead:** It utilizes **14 Bonded IOBs** (composed of 9 Input Buffers `IBUF` and 5 Output Buffers `OBUF`), providing a standard interface for handling the multi-bit input operands and flags.

### B. Timing Analysis & Critical Path Routing
The timing profile reveals an unconstrained worst-case propagation delay ($T_{pd}$) of **5.950 ns**:
* **Critical Path:** The absolute worst-case combinational path initiates at the input port **`A[2]`** and propagates directly through the slice lookup logic to resolve the **`S[2]`** sum output vector pin.
* **Logic Levels:** The network spans across **3 physical logic levels** (`IBUF` $\rightarrow$ `LUT3` $\rightarrow$ `OBUF`) within the synthesis abstraction layer.
* **Pre-Route Estimation:** Because this evaluation comes from a *Synthesized* state rather than fully *Routed* hardware, physical placement coordinates on the die fabric are unassigned. Wire parasitics are modeled using uniform, estimated placement constraints ($\approx 0.674\text{ ns}$ for initial unplaced nets).

### C. Thermal & Power Dissipation Profile
The module establishes a classic dynamic thermal profile reflecting its combinational layout structure:
* **I/O Dominance:** At the pre-route stage, over 97% of active electrical consumption is dynamic ($2.970\text{ W}$). This is highly localized within the external I/O pad loops due to modeled capacitive charging currents on PCB lines.
* **Core Logic Fabric Power:** The internal logic bypass network consumes an estimated **0.024 W** across active slice cells. 
* **Thermal Envelope:** Under typical process conditions and ambient operational limits ($25.0^\circ\text{C}$), the total circuit raises the expected junction temperature to **$39.6^\circ\text{C}$**, leaving a maximum ambient thermal headroom of up to **$70.4^\circ\text{C}$**.

---

## 3. Implementation Synthesis Conclusions

1. **Architectural Benefits:** The synthesis engine demonstrates that the `Carry_skip_adder` successfully groups bit evaluation blocks into compact, unrolled parallel boolean structures. This provides a clean trade-off between standard ripple-carry routing chains and massive select multiplexer groupings.
2. **Benchmark Baselines:** Because this module is analyzed at the synthesis stage, its current timing ($5.950\text{ ns}$) and internal power numbers ($0.024\text{ W}$) should be compared with other architectures (like the Carry Lookahead Adder) that are also evaluated at the pre-route stage to maintain benchmark parity.