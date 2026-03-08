Below is a **concise but deep revision sheet for Computer Architecture**, designed for **systems engineer / low-level / performance-focused interviews**. The goal is to refresh the **mental model of how software maps to hardware and how CPUs execute instructions efficiently**.

---

# Computer Architecture – Revision Sheet

---

# 1. Instruction Set Architecture (ISA)

The **Instruction Set Architecture (ISA)** is the **interface between software and hardware**.

It defines:

* Instructions CPU can execute
* Registers available
* Data types
* Addressing modes
* Memory model
* Instruction format

Example ISAs:

* x86-64
* ARM
* RISC-V

---

### Example Instruction

```asm
ADD R1, R2, R3
```

Meaning:

```
R1 = R2 + R3
```

ISA tells the CPU:

* instruction encoding
* register operands
* semantics of ADD

---

### ISA vs Microarchitecture

| Concept           | Meaning                 |
| ----------------- | ----------------------- |
| ISA               | What instructions exist |
| Microarchitecture | How CPU implements them |

Two CPUs may implement the **same ISA differently** but run the **same programs**.

---

# 2. Big Endian vs Little Endian

Endianness determines **how multi-byte data is stored in memory**.

Example value:

```
0x12345678
```

---

### Big Endian

Most significant byte stored first.

Memory layout:

```
Address   Value
1000      12
1001      34
1002      56
1003      78
```

Used by:

* some network protocols
* older architectures

Network byte order = **big endian**.

---

### Little Endian

Least significant byte stored first.

```
Address   Value
1000      78
1001      56
1002      34
1003      12
```

Used by:

* x86-64
* most modern CPUs

---

### Why It Matters

* binary file formats
* networking
* memory dumps
* cross-platform communication

---

# 3. What is a Register?

A **register** is a **small, extremely fast storage location inside the CPU**.

Characteristics:

* directly accessible by ALU
* fastest memory in system
* limited quantity

Example registers:

```
RAX
RBX
RCX
RDX
```

Typical uses:

| Register Type        | Purpose                |
| -------------------- | ---------------------- |
| General purpose      | store temporary values |
| Program Counter      | next instruction       |
| Stack Pointer        | top of stack           |
| Instruction Register | current instruction    |

---

### Example Execution

```
LOAD R1, [100]
LOAD R2, [104]
ADD R3, R1, R2
```

Registers hold operands for ALU operations.

---

# 4. From Application Program to Chip Layout

This shows **how software eventually becomes hardware operations**.

```
Application Program
      ↓
High Level Language
      ↓
Compiler
      ↓
Assembly Code
      ↓
Machine Code
      ↓
Instruction Execution
      ↓
Logic Gates
      ↓
Transistors
      ↓
Chip Layout
```

Example flow:

```
C code
  ↓
x86 assembly
  ↓
binary instructions
  ↓
executed by CPU hardware
```

---

# 5. CPU–Memory Interaction

CPU executes programs stored in memory.

Basic process:

```
Fetch → Decode → Execute
```

---

### Components Inside CPU

Typical CPU contains:

```
Control Unit
ALU
Registers
Cache
Branch predictor
Instruction decoder
Pipeline units
```

---

### CPU–Memory Interaction Flow

```
CPU requests instruction
        ↓
Memory returns instruction
        ↓
CPU decodes instruction
        ↓
Operands loaded
        ↓
ALU executes
        ↓
Result stored
```

---

### Memory Hierarchy

```
Registers
L1 Cache
L2 Cache
L3 Cache
RAM
Disk
```

Closer to CPU = **faster but smaller**.

---

# 6. RISC vs CISC

Two philosophies of CPU design.

---

### RISC (Reduced Instruction Set Computer)

Principles:

* simple instructions
* fixed instruction length
* load/store architecture

Example:

* ARM
* RISC-V

Example instruction:

```
ADD R1, R2, R3
```

---

### CISC (Complex Instruction Set Computer)

Principles:

* complex instructions
* variable length instructions
* memory operations inside instructions

Example:

* x86-64

Example instruction:

```
ADD [MEM], R1
```

---

### Comparison

| Feature                | RISC              | CISC               |
| ---------------------- | ----------------- | ------------------ |
| Instruction complexity | Simple            | Complex            |
| Instruction count      | Higher            | Lower              |
| Hardware complexity    | Lower             | Higher             |
| Performance            | Pipeline friendly | Harder to pipeline |

Modern CPUs often **internally translate CISC into RISC-like micro-ops**.

---

# 7. Multi-Core System Hardware

A modern processor contains **multiple cores**.

Each core can execute instructions independently.

---

### Multi-Core Layout

```
CPU Package
   ├── Core 1
   ├── Core 2
   ├── Core 3
   └── Core 4
```

Each core contains:

```
ALU
Registers
L1 cache
Pipeline
```

Shared resources:

```
L3 Cache
Memory controller
Interconnect
```

---

### Data Flow

```
Core → L1 → L2 → L3 → RAM
```

---

### Benefits

* parallel computation
* higher throughput
* better multitasking

---

# 8. Actions in Data Processing Instructions

Data processing instructions perform **operations on data**.

Typical operations:

```
ADD
SUB
AND
OR
XOR
SHIFT
COMPARE
```

---

### Example

```
ADD R1, R2, R3
```

Steps:

1. read registers R2, R3
2. send values to ALU
3. perform addition
4. store result in R1

---

### ALU Operations

Arithmetic:

```
+
-
*
/
```

Logical:

```
AND
OR
NOT
XOR
```

---

# 9. Why Clock is Needed

The **clock synchronizes operations inside the CPU**.

Without a clock, hardware components would not know **when to move to the next step**.

Clock acts like a **heartbeat of the processor**.

Example:

```
Clock Tick
    ↓
Fetch instruction
    ↓
Clock Tick
    ↓
Decode instruction
```

---

### Example Clock Speed

```
3 GHz CPU
```

Means:

```
3 billion cycles per second
```

---

# 10. Clock Cycles and Performance

Execution time of a program:

```
Execution Time =
Instruction Count × CPI × Clock Cycle Time
```

Where:

```
CPI = cycles per instruction
```

---

### Tradeoffs

| Factor            | Meaning                      |
| ----------------- | ---------------------------- |
| Instruction count | program complexity           |
| CPI               | microarchitecture efficiency |
| Clock rate        | hardware speed               |

---

Example:

```
Instruction count = 1B
CPI = 2
Clock = 3GHz
```

Execution time:

```
(1e9 × 2) / (3e9) = 0.66 seconds
```

---

# 11. Single Cycle Processor

In a **single-cycle processor**, every instruction completes in **one clock cycle**.

Steps inside one cycle:

```
Fetch
Decode
Execute
Memory
Writeback
```

All happen **in one cycle**.

---

### Advantage

Simple design.

---

### Disadvantage

Clock must be **long enough for the slowest instruction**.

Example slow instruction:

```
Load from memory
```

This limits clock frequency.

---

# 12. Multicycle Processor

Each instruction executes in **multiple clock cycles**.

Example:

```
Cycle 1 → Fetch
Cycle 2 → Decode
Cycle 3 → Execute
Cycle 4 → Memory
Cycle 5 → Writeback
```

---

### Advantage

Different instructions take **different number of cycles**.

Faster clock possible.

---

### Example

```
ADD → 4 cycles
LOAD → 5 cycles
```

---

# 13. Pipelined Processor

Pipelining improves **instruction throughput**.

Idea:

Execute **multiple instructions simultaneously in different stages**.

Pipeline stages:

```
IF  → Instruction Fetch
ID  → Instruction Decode
EX  → Execute
MEM → Memory
WB  → Writeback
```

---

### Pipeline Example

```
Cycle 1: I1 Fetch
Cycle 2: I1 Decode | I2 Fetch
Cycle 3: I1 Execute | I2 Decode | I3 Fetch
```

Like an **assembly line**.

---

### Benefit

Higher **instructions per second**.

---

# 14. Data Hazards and Control Hazards

Pipelining introduces hazards.

---

# Data Hazard

Occurs when instruction depends on previous result.

Example:

```
I1: ADD R1, R2, R3
I2: SUB R4, R1, R5
```

I2 needs result of I1.

Solution:

* pipeline stall
* forwarding

---

### Forwarding Example

ALU output forwarded directly to next stage.

Avoids waiting for register write.

---

# Control Hazard

Occurs due to **branch instructions**.

Example:

```
BEQ R1, R2, LABEL
```

CPU doesn't know next instruction until branch resolves.

Pipeline may fetch wrong instructions.

---

# 15. Branch Prediction

To avoid pipeline stalls, CPU predicts branch outcomes.

Two possibilities:

```
Branch Taken
Branch Not Taken
```

---

### Static Prediction

Always assume:

```
branch not taken
```

Simple but inaccurate.

---

### Dynamic Prediction

CPU learns from history.

Uses **branch predictor hardware**.

Example structure:

```
Branch History Table
Pattern History Table
```

---

### Example Predictor

2-bit predictor states:

```
Strongly Taken
Weakly Taken
Weakly Not Taken
Strongly Not Taken
```

---

### Why Branch Prediction Matters

Deep pipelines mean:

```
wrong prediction → pipeline flush
```

Penalty:

```
10–20 cycles
```

Good branch prediction significantly improves performance.

---

# Quick Interview Summary

Key mental models:

```
ISA → software/hardware interface
Registers → fastest storage
Clock → synchronizes operations
Pipeline → improves throughput
Hazards → pipeline conflicts
Branch prediction → avoids pipeline stalls
```

Core performance formula:

```
Execution Time =
Instruction Count × CPI × Clock Cycle Time
```

---