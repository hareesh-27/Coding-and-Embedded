## Code explained

We need to remember that we are operating in **Asynchronous mode**, so it behaves like UART.

- First we understand that we are working on USART2 present in **APB1 peripheral**.
- <img width="358" height="570" alt="image" src="https://github.com/user-attachments/assets/ea70410c-225e-4900-a395-3714cb3b2686" />
- Now the most important part. Our UART uses GPIO pins for TX and RX. We need to find those pins (for TX in this case) and configure them.
- <img width="1764" height="1312" alt="image" src="https://github.com/user-attachments/assets/adf74b2b-e253-4a3a-80d4-4b849dbf2093" />

  - From this diagram we understand that USART2_TX uses PA2 means GPIOA Port 2 and AF07.

---

Now lets see UART's initialisation function - **uart_tx_init(void)**

There is a step by step framework which makes this driver work correctly.

- Inside uart_tx_init function, first we need to **configure uart gpio pins**

  - Enable clock acces to GPIOA coz uart_tx uses **PA2** in **alternate function mode** for transmitting data
  - Set PA2 to alternate function mode
  - After setting PA2 to alternate function, set PA2's type to UART_TX (AF07)

- Next we need to configure USART Module itself

  - Enable clock access to USART2
  - Config UART Baud rate
  - Config Transfer direction
  - Finally enable UART module

---

## **Enabling clock access to GPIOA**

<img width="1284" height="276" alt="image" src="https://github.com/user-attachments/assets/627a925a-7cf6-4f55-879c-c1a4528a0f9d" />

```c
#define GPIOAEN (1U<<0)

RCC->AHB1ENR |= GPIOAEN;
```

---

## **Setting PA2 to alternate function mode**

<img width="1322" height="498" alt="image" src="https://github.com/user-attachments/assets/c6919f10-a3e6-44d2-8810-dac159815c5a" />

```c
GPIOA->MODER &= ~(1U<<4);
GPIOA->MODER |=  (1U<<5);
```

---

## **Setting alternate function type to PA2**

<img width="1358" height="844" alt="image" src="https://github.com/user-attachments/assets/73698cfd-2459-49ef-b095-068e368ddd8a" />

```c
GPIOA->AFR[0] |= (1U<<8);
GPIOA->AFR[0] |= (1U<<9);
GPIOA->AFR[0] |= (1U<<10);
GPIOA->AFR[0] &= ~(1U<<11);
```

---

## **Enabling clock access to USART2**

<img width="1326" height="538" alt="image" src="https://github.com/user-attachments/assets/e0a9f0ec-dfe5-47d8-bf0e-839276483d3e" />

```c
#define UARTEN  (1U<<17)

RCC->APB1ENR |= UARTEN;
```

---

## **Configuring UART Baud rate**

This is something done with the help of a separate function.

- We name the function as **compute_uart_bd**
- It takes two arguments. PeriphClk of type uint32_t and BaudRate of type uint32_t.
- The return type of this function is uint16_t.
- We'll give the value of PeriphClk and BaudRate too at the start of the program.
- Inside function we calculate:

```c
(PeriphClk + (BaudRate/2U))/BaudRate
```

and return the value.

- We will store this value in UART Baud Rate Register with the help of another function called **uart_set_baudrate()**

### **uart_set_baudrate()**

- We allow this function to work with any UART module (standard procedure).
- Because of this reason we have arguments which are USART_TypeDef *USARTx, PeriphClk and BaudRate.
- Inside function we store the value of calculated baud rate in USART Baud Rate register:

```c
USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
```

---

Now we will call these 2 functions - **compute_uart_bd** and **uart_set_baudrate()** from our **uart_tx_init(void)** function.

### **compute_uart_bd**

Arguments:

```c
USART2
```

because we are dealing with USART2.

### **PeriphClk**

The default STM32 clock is 16 MHz.

```c
#define SYS_FREQ     16000000
#define APB1CLK      SYS_FREQ
```

### **BaudRate**

```c
#define UART_BAUDRATE  115200
```

---

## **Configuring Transfer direction**

<img width="1340" height="382" alt="image" src="https://github.com/user-attachments/assets/9db55728-1ca8-45cc-9135-6d69bc20082d" />

We need to set 3rd bit to 1.

```c
#define CR1_TE   (1U<<3)

USART2->CR1 = CR1_TE;
```

---

## **Enabling UART module**

<img width="1292" height="370" alt="image" src="https://github.com/user-attachments/assets/c0781958-b007-4de6-ad3b-e831d243844b" />

Need to set 13th bit to 1.

```c
#define CR1_UE  (1U<<13)

USART2->CR1 |= CR1_UE;
```

Finally UART initialisation has been done.

---

## Now we focus on transmitting data

Here we take help of **uart2_write(int ch)** function.

- One of the main aspect here is to make sure whether the UART transmit data register is empty or not.
- Only when it is empty we can store values in it.
- After that we write to this register.

The concept of this function is simple.

We need to do:

```c
USART2->DR = ch & 0xFF;
```

(only 8 bits need to be transferred)

But we need to check whether the Data Register is empty or not.

<img width="1344" height="368" alt="image" src="https://github.com/user-attachments/assets/c40ea2f7-b434-4a9a-98f9-f9f857830fbd" />

<img width="1104" height="216" alt="image" src="https://github.com/user-attachments/assets/d1db00f3-0b25-45e3-8ded-f70a56f91fa1" />

```c
#define SR_TXE  (1U<<7)

while(!(USART2->SR & SR_TXE))
{
}
```

---

## Finally main function

We call:

```c
uart_tx_init();
```

```c
while(1)
{
    uart2_write('Y');
}
```
