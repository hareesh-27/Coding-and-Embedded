**What is Structure?**  

A structure is the user-defined data type in C++. Structure creates the data type which can hold the multiple data types.

---

## Declaring Structure Variables

Structure variables can be declared in two different ways :

### **Declared while declaring the structure**

```c
struct point
{
    int x;
    int y;
} p1, p2;
```

In the above struct declaration, the point is the name of the structure. p1,p2 are the variables of the type struct point.  
Here variables p1, and p2 are declared while structure declaration itself.

---

### **A declaration like Basic Data types:**

```c
struct point
{
    int x;
    int y;
};

int main()
{
    struct point p1, p2;
}
```

In the above Code, p1, and p2 are the struct variables. They are not declared while structure declaration. They are declared after structure declaration.

---

## **Padding in structures**

Extra unused bytes inserted by the compiler between (or after) structure members to ensure proper memory alignment for efficient access.

---

## **The diff bw structure and union is the memory**

- In structure each members have seperate memory  
- while in union its a shared memory. So oveeride is possible

<img width="1052" height="592" alt="image" src="https://github.com/user-attachments/assets/8c207d56-45c6-4fbc-b6d5-dcbadf08832c" />

---

## **Union Override Example**

```c
#include <stdio.h>

union Data
{
    int i;
    float f;
};

int main()
{
    union Data d;

    d.i = 10;

    printf("After storing int:\n");
    printf("d.i = %d\n", d.i);

    d.f = 5.5;

    printf("\nAfter storing float:\n");
    printf("d.f = %f\n", d.f);

    // Reading int after float overwrote memory
    printf("d.i = %d\n", d.i);

    return 0;
}
```

## Question 1

```c
struct A
{
    char c;
    int i;
};
```

### Step-by-step

#### char c

- size = 1 byte
- alignment = 1

Placed at:

Byte 0

---

#### int i

- size = 4 bytes
- alignment = 4

int must start at address divisible by 4.

Current position after c:

Byte 1

Not divisible by 4.

So compiler adds 3 padding bytes.

Memory:

```text
0 1 2 3 4 5 6 7
c p p p i i i i
```

Total size = 8 bytes.

---

# Question 2

```c
struct B
{
    char c1;
    char c2;
    int i;
};
```

#### c1

1 byte at byte 0

#### c2

1 byte at byte 1

Current position = byte 2

#### int i

Needs alignment 4.

Byte 2 not divisible by 4.

Add 2 padding bytes.

Memory:

```text
0 1 2 3 4 5 6 7
c c p p i i i i
```

Total size = 8 bytes.

Padding = 2 bytes.

---

# Question 3

```c
struct C
{
    char c;
    double d;
    int i;
};
```

#### char c

1 byte at byte 0

#### double d

- size = 8
- alignment = 8

Next position = byte 1

Need multiple of 8.

Add 7 padding bytes.

double placed from byte 8–15.

#### int i

Placed at byte 16–19.

Largest alignment = 8.

Structure size must be multiple of 8.

Current size = 20.

Add 4 end padding bytes.

Memory:

```text
0        8        16      23
c ppppppp dddddddd iiii pppp
```

Total size = 24 bytes.

---

# Question 4

```c
struct D
{
    int i;
    char c;
};
```

#### int i

Bytes 0–3

#### char c

Byte 4

Current size = 5

But structure size must be multiple of largest alignment.

Largest alignment = 4.

So add 3 end padding bytes.

Memory:

```text
0 1 2 3 4 5 6 7
i i i i c p p p
```

Total size = 8 bytes.

---

# Question 5

```c
struct E
{
    char a;
    int b;
    char c;
};
```

#### char a

Byte 0

#### int b

Needs alignment 4.

Current position = byte 1.

Add 3 padding bytes.

b at bytes 4–7.

#### char c

Byte 8

Current size = 9.

Largest alignment = 4.

Add 3 end padding bytes.

Memory:

```text
0 1 2 3 4 5 6 7 8 9 10 11
a p p p b b b b c p  p  p
```

Total size = 12 bytes.
