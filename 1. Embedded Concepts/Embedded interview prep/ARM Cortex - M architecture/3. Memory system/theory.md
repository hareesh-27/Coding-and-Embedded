# Memory System in ARM Cortex-M4

The ARM Cortex-M4 is a 32-bit processor and provides a 4 GB address space. Since the processor has 32 address lines, it can generate addresses from:

```text
0x00000000
to
0xFFFFFFFF
```

This results in:

```text
2^32 = 4,294,967,296 addresses
≈ 4 GB address space
```

The 4 GB address space does not mean that the microcontroller contains 4 GB of physical memory. Instead, it defines the range of addresses that the processor can access.

The available address space is divided into different regions such as Flash memory, SRAM, peripheral memory, and system control space.

---

# Cortex-M4 Memory Map

The Cortex-M4 address space is divided into regions with specific purposes.

Simplified memory map:

```text
0x00000000 ───────── Code / Flash Region

0x20000000 ───────── SRAM Region

0x40000000 ───────── Peripheral Region

0xE0000000 ───────── System Control Space
                     (NVIC, SysTick, SCB)

0xFFFFFFFF
```

Each region occupies a range of addresses within the 4 GB address space.

---

# Flash Memory

Flash memory is non-volatile memory used to store the program code and constant data.

Characteristics:

- Non-volatile (data is retained after power-off)

---

# SRAM (Static Random Access Memory)

SRAM is volatile memory used during program execution.

Characteristics:

- Volatile (data is lost when power is removed)
- Faster than Flash memory
