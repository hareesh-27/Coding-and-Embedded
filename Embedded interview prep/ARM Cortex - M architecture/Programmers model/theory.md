## Load-Store Architecture in ARM Cortex-M4

ARM Cortex-M4 follows a load-store architecture, which means the CPU cannot directly perform arithmetic operations on data stored in memory. Instead, data must first be loaded from memory (RAM) into CPU registers, processed inside the processor, and then stored back to memory if required.

For example, consider the operation:

```c
int a = 10;
int b = 15;
int c = a + b;
```

Initially, the values 10 and 15 are stored in RAM. The processor first loads these values into registers (for example, R0 and R1). The ALU (Arithmetic Logic Unit) inside the Cortex-M4 CPU core then performs the addition and stores the result (25) in another register (for example, R2). If the program needs to preserve the result, it is then written back to RAM.

```text
RAM
 ↓ Load
R0 = 10
R1 = 15
 ↓
ALU performs addition
 ↓
R2 = 25
 ↓ Store (if required)
RAM
```

The reason for this approach is performance. Registers are located inside the CPU core and can be accessed much faster than RAM. By keeping frequently used data in registers, the processor avoids repeated memory accesses, resulting in faster execution and more efficient code.
