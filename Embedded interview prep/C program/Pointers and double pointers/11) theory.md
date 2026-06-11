# Single Pointer vs Double Pointer

We need double pointers if we want to modify a pointer.

With single pointers we can modify the data.

---

## Modifying Data Using Single Pointer

```c
#include <stdio.h>

void changeValue(int *p)
{
    printf("Inside function p = %p\n", p);
    *p = 20;
}

int main()
{
    int x = 10;
    int *ptr = &x;

    printf("&x  = %p\n", &x);
    printf("ptr = %p\n", ptr);

    changeValue(ptr);

    printf("x = %d\n", x);

    return 0;
}
```

### Output

```text
Before: x = 10
After : x = 20
```

---

## Modifying Pointer Using Double Pointer

```c
#include <stdio.h>

void makeNull(int **p)
{
    *p = NULL;
}

int main()
{
    int x = 10;
    int *ptr = &x;

    printf("Before: ptr = %p\n", ptr);

    makeNull(&ptr);

    printf("After : ptr = %p\n", ptr);

    return 0;
}
```

### Output (addresses will differ)

```text
Before: ptr = 0x7ffd1234
After : ptr = (nil)
```

---

## Why We Cannot Modify a Pointer Using a Single Pointer

```c
#include <stdio.h>

void makeNull(int *p)
{
    p = NULL;
}

int main()
{
    int x = 10;
    int *ptr = &x;

    printf("Before: ptr = %p\n", ptr);

    makeNull(ptr);

    printf("After : ptr = %p\n", ptr);

    return 0;
}
```

### Output

```text
Before: ptr = 1000
After : ptr = 1000
```

### The reason is because p receives a copy of ptr.

Suppose:

```text
x   = 10
&x  = 1000

ptr = 1000
```

When we call:

```c
makeNull(ptr);
```

the value of ptr is copied into p.

```text
ptr ------> 1000

p   ------> 1000
```

Now inside the function:

```c
p = NULL;
```

only changes the local copy p.

```text
ptr ------> 1000

p   ------> NULL
```

When the function returns, p is destroyed and ptr remains unchanged.

Therefore:

```text
Before: ptr = 1000
After : ptr = 1000
```

---

## Why Double Pointer Works

When we call:

```c
makeNull(&ptr);
```

we pass the address of ptr.

Suppose:

```text
x      = 10
&x     = 1000

ptr    = 1000
&ptr   = 2000
```

Then:

```text
p = 2000
```

Inside the function:

```c
*p = NULL;
```

means:

```text
contents at address 2000 = NULL
```

Since address 2000 belongs to ptr:

```text
ptr = NULL
```

Now the original pointer is modified.

```text
Before: ptr = 1000
After : ptr = NULL
```

---

## Key Takeaway

```text
int *p
↓
Can modify DATA

*p = value
```

```text
int **p
↓
Can modify POINTER

*p = NULL
```

Therefore:

- Single pointer → modify the value being pointed to
- Double pointer → modify the pointer itself
