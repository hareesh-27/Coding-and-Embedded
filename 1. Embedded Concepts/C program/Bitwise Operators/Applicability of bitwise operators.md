## Applicability of Bitwise Operators

* Set bits
* Clear bits
* Toggle bits
* Test bits

---

## Setting Bits

Let’s say we want to **set the 4th and 7th bits** of:

```
00111110
```

* Use a mask value:

```
10010000   (0x90)
```

* Use **OR (|)** operation:

```
00111110
10010000
--------
10111110
--------
```

---

## Clearing Bits

Let’s say we want to **clear the 4th and 7th bits** of:

```
00111110
```

* Use a mask value (invert of target bits):

```
01101111
```

* Use **AND (&)** operation:

```
00111110
01101111
--------
00101110
--------
```

---

## Toggling Bits

Let’s say we want to **toggle the 4th and 7th bits** of:

```
00111110
```

* Use a mask value:

```
10010000
```

* Use **XOR (^)** operation:

```
00111110
10010000
--------
10101110
--------
```
