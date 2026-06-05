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

---

# Programmer's Model of ARM Cortex-M4

The Programmer's Model describes the set of registers visible to the programmer and how the processor uses them during program execution. These registers are located inside the Cortex-M4 CPU core and are not memory-mapped. They are used for data storage etc.

## Register Set

The Cortex-M4 programmer's model consists of:

```text
R0-R12  → General Purpose Registers
R13     → Stack Pointer (SP)
R14     → Link Register (LR)
R15     → Program Counter (PC)
xPSR    → Program Status Register
```

---

## R0-R12: General Purpose Registers

These registers are used to:

- Store variables
- Hold function arguments
- Store intermediate calculation results
- Perform arithmetic and logical operations

Example:

```c
int a = 10;
int b = 15;
int c = a + b;
```

The compiler may use:

```text
R0 = 10
R1 = 15
R2 = R0 + R1
```

These registers are heavily used by the ALU during program execution.

---

## R13: Stack Pointer (SP)

The Stack Pointer stores the address of the current top of the stack.

```text
SP = Address of Top of Stack
```

The stack is used to store:

- Local variables
- Saved registers
- Return addresses
- Interrupt context information

During function calls and interrupts, the processor automatically updates the Stack Pointer.

Example:

```c
void func()
{
    int x = 10;
}
```

The local variable x is typically stored on the stack, and SP points to the current top of the stack.

---

## R14: Link Register (LR)

The Link Register stores the return address during a function call.

When a function is called:

```c
func();
```

the processor saves the address of the next instruction in LR before jumping to the function.

```text
LR = Return Address
```

When the function completes, the processor uses LR to return to the calling function.

---

## R15: Program Counter (PC)

The Program Counter contains the address of the next instruction to be executed.

```text
PC = Address of Next Instruction
```

As instructions execute, the PC automatically updates. During function calls, branches, and interrupts, the PC changes to point to the new execution location.

---

## Special Note (8086 vs Cortex-M4)

This is slightly different from what you may have learnt in 8086.

In 8086:

- Program Counter (IP) stores the next instruction address
- Stack stores the return address during function calls

In Cortex-M4:

- PC stores the next instruction address
- LR (Link Register) stores the return address

The stack comes into play when there are nested function calls, interrupts, or when LR needs to be preserved.

---

## xPSR: Program Status Register

The xPSR stores processor status information.

It consists of:

```text
APSR → Condition Flags
IPSR → Current Exception Number
EPSR → Execution State Information
```

The most important APSR flags are:

```text
N → Negative Flag
Z → Zero Flag
C → Carry Flag
V → Overflow Flag
```

Example:

```text
5 - 5 = 0
```

Result:

```text
Z = 1
```

indicating that the operation produced zero.
