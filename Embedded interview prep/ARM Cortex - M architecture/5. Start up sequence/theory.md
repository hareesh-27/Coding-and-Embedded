# Vector Table, Reset Handler and Startup Sequence in ARM Cortex-M4

## Introduction

When an STM32 microcontroller based on the ARM Cortex-M4 core is powered on or reset, the processor does not immediately begin executing the `main()` function. Instead, it follows a predefined startup sequence that prepares the system for normal program execution.

The startup process begins with the Vector Table and eventually leads to the execution of `main()`.

---

## Vector Table

The Vector Table is a table stored in memory that contains important startup information and the addresses of exception handlers and interrupt service routines (ISRs).

The first entries of the Vector Table are:

```text
Entry 0 → Initial Stack Pointer Value

Entry 1 → Reset_Handler Address

Entry 2 → NMI_Handler Address

Entry 3 → HardFault_Handler Address

...

Remaining Entries → ISR Addresses
```

The Vector Table is not executable code. It contains data that the processor uses during startup and interrupt handling.

---

## Initial Stack Pointer

The first entry of the Vector Table contains the initial value of the Stack Pointer (SP).

Example:

```text
VectorTable[0]
=
0x20020000
```

During reset, the Cortex-M4 reads this value and loads it into the Stack Pointer register.

```text
SP = 0x20020000
```

This value usually corresponds to the top of SRAM because the stack grows downward in memory.

The processor must initialize the stack before executing any program code.

---

## Reset Handler

The second entry of the Vector Table contains the address of the Reset Handler.

Example:

```text
VectorTable[1]
=
Address of Reset_Handler
```

During reset, the processor reads this address and loads it into the Program Counter (PC).

```text
PC = Reset_Handler Address
```

The Reset Handler is the first code executed after reset.

---

## Startup Sequence

The Cortex-M4 startup sequence follows these steps:

```text
Power ON / Reset
↓
Read VectorTable[0]
↓
Initialize SP
↓
Read VectorTable[1]
↓
Load PC with Reset_Handler Address
↓
Execute Reset_Handler
```

At this point, normal instruction execution begins.

---

## Responsibilities of Reset_Handler

The Reset Handler prepares the system before the application starts.

Its main responsibilities include:

### .data Initialization

Initialized global and static variables are stored in Flash memory.

Example:

```c
int x = 10;
```

Before program execution, the Reset Handler copies these values from Flash to SRAM.

```text
Flash
 ↓
SRAM
```

This process is called **.data initialization**.

---

### .bss Initialization

Uninitialized global and static variables must start with a value of zero.

Example:

```c
int counter;
```

The Reset Handler clears these variables and initializes them to zero.

This process is called **.bss initialization**.

---

### System Initialization

The Reset Handler typically calls:

```c
SystemInit();
```

This function performs hardware initialization such as:

```text
Clock Configuration
PLL Configuration
FPU Configuration
```

---

### Calling main()

After all initialization is complete, the Reset Handler calls:

```c
main();
```

At this point, the Program Counter (PC) is updated to the address of `main()`, and normal application execution begins.

##

---

## Complete Startup Flow

```text
Power ON / Reset
↓
Read Vector Table Entry 0
↓
Initialize Stack Pointer (SP)
↓
Read Vector Table Entry 1
↓
Load Program Counter (PC) with Reset_Handler Address
↓
Execute Reset_Handler
│
├── Initialize .data section
├── Initialize .bss section
├── Perform System Initialization
│
└── Call main()
↓
Application Execution Begins
```

---

## Summary

The startup sequence of the ARM Cortex-M4 begins when the processor reads the first two entries of the Vector Table. The first entry provides the initial Stack Pointer value, while the second entry provides the address of the Reset Handler. The Reset Handler initializes memory and hardware resources before calling `main()`. Only after this initialization process is complete does the application begin normal execution.

Data is in flah after compiling and we dont want data to be ther we want in sram
