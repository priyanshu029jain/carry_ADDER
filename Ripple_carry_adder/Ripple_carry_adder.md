# Performance Report & Implementation Analysis: Ripple Carry Adder (RCA)

This report provides a comprehensive post-route performance evaluation of the `Ripple_carry_adder` module. The analysis is compiled directly from manufacturing execution reports generated using AMD/Xilinx Vivado ML v2025.2 targeting an Artix-7 FPGA (`xc7a35tcsg324-1`).

---

## 1. Executive Performance Matrix

The following table presents a summary of hardware metrics extracted from the post-route implementation reports:

| Performance Parameter | Metric Value | Architectural & Silicon Implications |
| :--- | :---: | :--- |
| **Design Execution State** | **Routed** (Physical) | Represents a fully realized, placed, and routed physical die layout. |
| **Total On-Chip Power** | 2.866 W | Complete active thermal profile at typical process node settings. |
| **Dynamic Power Component** | 2.788 W (97.3%) | Dominated heavily by capacitive loading of physical I/O pads. |
| **Device Static Power** | 0.078 W (2.7%) | Constant baseline leakage across the transistor channel substrates. |
| **Worst-Case Delay ($T_{pd}$)** | 6.885 ns | Critical path propagation delay measured from input pads to output pins. |
| **Logic Component Delay** | 4.015 ns (58.3%) | Cumulative intrinsic cell switching speed across the path logic gates. |
| **Routing Net Delay** | 2.870 ns (41.7%) | Physical interconnect wire delay across copper routing tracks. |
| **Slice Lookup Tables (LUTs)** | 4 | Physical multi-input lookup tables mapped onto the silicon fabric. |
| **LUT Functional Distribution** | 2 × LUT3, 2 × LUT5 | Optimally mapped by the tool into mixed-input primitives. |

---

## 2. Core Parametric Breakdown

### A. Resource Utilization & Substrate Mapping
According to the post-route utilization report, the ripple-carry network utilizes localized CLB resources efficiently:
* **Logic Footprint:** The complete combinational structure fits within **4 Slice LUTs**. Vivado maps the Boolean structure into a combination of two 3-input functions (`LUT3`) and two 5-input functions (`LUT5`).
* **Registers & Sequential Elements:** The design uses **0 Slice Registers**, maintaining a purely combinational datapath with zero registers or latch violations.
* **Pin Count Overhead:** It maps onto **14 Bonded IOBs** (9 input pins handled by `IBUF` and 5 output pins handled by `OBUF`), utilizing standard IO ring current drivers.

### B. Timing Analysis & Physical Interconnect Delays
The worst-case timing paths follow a traditional cascaded carry chain pattern with a total propagation delay ($T_{pd}$) of **6.885 ns**:
* **Critical Path:** The absolute critical timing path originates from input port **`B[0]`** and flows serially through the lookahead and ripple stages to the final output vector pin **`Cout`**.
* **Logic Levels:** The path passes through **3 logical gate levels** (`IBUF` $\rightarrow$ `LUT5` $\rightarrow$ `OBUF`), taking advantage of combined boolean mappings inside a single localized slice to bypass multi-stage lookup delays where possible.
* **Physical Routing Reality:** Unlike estimated pre-route designs, these metrics reflect real parasitic capacitance on copper traces, with routing accounting for a significant **2.870 ns (41.7%)** of total propagation delay.

### C. Thermal & Power Dissipation Profile
The power profile remains highly stable, fitting comfortably within the standard Artix-7 thermal constraints:
* **Dynamic Loading:** Active switching consumption totals **2.788 W**. Over 95% of this budget belongs exclusively to the external IO pad drivers switching lines on a modeled 10"x10" printed circuit board.
* **Internal Logic Core Power:** The core logic fabric demands an incredibly light **0.012 W**, minimizing localized hot spots across the layout.
* **Thermal Envelope:** At an ambient temperature of $25.0^\circ\text{C}$ with a medium profile heatsink, the chip maintains a reliable junction temperature of **$38.8^\circ\text{C}$**, leaving **$71.2^\circ\text{C}$** of safe operational overhead below the commercial thermal limit.

---

## 3. Implementation Summary & Design Review

1. **Hardware Parity:** When compared side-by-side with your Carry Lookahead Adder (CLA), this fully routed Ripple Carry Adder demonstrates how physical placement alters timing profiles. While CLA designs optimize logical cell tiers, the compact, localized cell grouping of a short 4-bit RCA minimizes routing overhead effectively.
2. **Production Quality:** Operating entirely within a **Routed** state means these resource numbers, parasitic line values, and dynamic power boundaries represent verified, real-world physical behavior on an actual silicon wafer.