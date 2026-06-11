## Volatile Keyword

Volatile keyword tells the computer to check the value of a variable directly from the memory.

For ex:

```c
int x = 10;
```

Without volatile, the data is stored in a register (present in CPU) for faster access. The computer does'nt check the value of x from the memory.  
(The computer caches it).

With

```c
volatile int x = 10;
```

the value is checked everytime from the memory because it may change.

In a normal program, the only thing that can change x is something like

```c
x = 20;
```

But in Embedded systems, something external like camera hardware/a sensor can change it. Since the computers register doesnt know this, it keeps showing the wrong value.

volatile forces the CPU to fetch the value from the actual memory address every time, ensuring we always have the most recent data from the device.

---

```c
int x = 0;

while (x == 0)
{
    // The compiler 'caches' x in a register.
    // It assumes x will always be 0 because nothing
    // inside this loop changes it.
}
```

---

## 🔹 Case 1

```c
volatile int *x = 0;
```

✅ Meaning:

👉 Pointer to a volatile int

- Data (*x) is volatile
- Pointer (x) is normal

### 🔹 What it means:

- Value at address can change anytime
- Compiler won’t optimize reads of *x

✔️ You can change x normally  
✔️ Must always re-read *x

<img width="1605" height="1157" alt="image" src="https://github.com/user-attachments/assets/2718a014-4922-47a4-b82a-307773b14cfe" />

---

## 🔹 Case 2

```c
int *volatile x = 0;
```

✅ Meaning:

👉 Volatile pointer to int

- Data is normal
- Pointer (x) is volatile

### 🔹 What it means:

- Address stored in x may change unexpectedly
- Compiler won’t optimize x

✔️ *x is stable  
✔️ x itself can change anytime

<img width="1661" height="1178" alt="image" src="https://github.com/user-attachments/assets/74d466ee-c13d-4a91-8931-73f320e00cad" />

---

## 🔹 Case 3

```c
volatile int *volatile x = 0;
```

✅ Meaning:

👉 Volatile pointer to volatile int

- Data is volatile
- Pointer is also volatile

### 🔹 What it means:

- Address can change anytime
- Value at that address can also change anytime

<img width="1721" height="1305" alt="image" src="https://github.com/user-attachments/assets/f52f4d33-dc28-4237-b349-2abf1088fc7e" />
