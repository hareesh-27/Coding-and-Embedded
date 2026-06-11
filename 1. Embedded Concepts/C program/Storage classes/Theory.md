## Storage Classes

**Storage classes** define the scope and lifetime of a variable. They also tell us where it is stored.

**4 types - auto, register, static, extern**

---

## **auto -**

This is the default storage class. No need to explicitly mention auto.  
Default value is garbage value.  

- Scope - Within block(local)

```c
void func() {
    int x = 10;   // auto variable
    printf("Inside func: %d\n", x);   // ✅ POSSIBLE
}

void display() {
    printf("Inside display: %d\n", x);   // ❌ NOT POSSIBLE (x not visible here)
}

int main() {
    func();
    printf("Inside main: %d\n", x);   // ❌ NOT POSSIBLE (x not visible here)
    return 0;
}
```

---

## **register -**

Same as auto but the only difference is the complier tries to store it in a register of a microprocesser for faster access.  
Default value is garbage value.

```c
void func() {
    register int x = 10;   // auto variable
    printf("Inside func: %d\n", x);   // ✅ POSSIBLE
}

void display() {
    printf("Inside display: %d\n", x);   // ❌ NOT POSSIBLE (x not visible here)
}

int main() {
    func();
    printf("Inside main: %d\n", x);   // ❌ NOT POSSIBLE (x not visible here)
    return 0;
}
```

---

## **static -**

This has the property of preserving its value even out of scope.  
Default value is 0.

```c
void func() {
    static int x = 0;

    x++;
    printf("Inside func: %d\n", x);   // ✅ POSSIBLE
}

void display() {
    printf("Inside display: %d\n", x);   // ❌ NOT POSSIBLE (x not visible here)
}

int main() {
    func(); // 1
    func(); // 2
    func(); // 3

    printf("Inside main: %d\n", x);   // ❌ NOT POSSIBLE (x not visible here)
    return 0;
}
```

---

## **extern -**

Extern is used to access global variable declared somewhere else (in another file / same file later)

New memory is not created.

Example:

```c
extern int x;
```

This tells the complier that, hey x is declared somewhere else plz use that.

Default value is 0.

```c
extern int x;   // referring to x from file1

int main() {
    printf("%d\n", x);   // ✅ POSSIBLE
    return 0;
}
```
