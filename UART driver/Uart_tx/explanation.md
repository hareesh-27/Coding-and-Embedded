## Code explained

We need to remember that we are operating in **Asynchronous mode**, so it behaves like UART
  - First we understand that we are working on USART2 present in **APB1 peripheral**.
  - <img width="358" height="570" alt="image" src="https://github.com/user-attachments/assets/ea70410c-225e-4900-a395-3714cb3b2686" />
  - No the most important part. Our UART uses GPIO pins for TX and RX. We need to find those pins (for TX in this case) and configure them
  - <img width="1764" height="1312" alt="image" src="https://github.com/user-attachments/assets/adf74b2b-e253-4a3a-80d4-4b849dbf2093" />
    - From this diagram we understand that USART2_TX uses PA2 means GPIOA Port 2 and AF07.

Now lets see UART's initialisation function - **uart_tx_init(void)**
There is a step by step framework which makes this driver work correctly

- Inside uart_tx_init function, first we need to **configure uart gpio pins**
  - Enable clock acces to GPIOA coz uart_tx uses **PA**2 in **alternate function mode** for transmitting data
  - Set PA2 to alternate function mode
  - After setting PA2 to alternate function, set PA2's type to UART_TX (AF07)

- Next we need to configure USART Module itself
  - Enable clock access to USART2
  - Config UART Baud rate
  - Config Transfer direction
  - Finally enable UART module
  

----------
**Enabling clock access to GPIOA**
<img width="1284" height="276" alt="image" src="https://github.com/user-attachments/assets/627a925a-7cf6-4f55-879c-c1a4528a0f9d" />

#define GPIOAEN (1U<<0)

RCC->AHB1ENR |=GPIOAEN;

**Setting PA2 to alternate function mode**
<img width="1322" height="498" alt="image" src="https://github.com/user-attachments/assets/c6919f10-a3e6-44d2-8810-dac159815c5a" />

GPIOA->MODER ~=(1U<<4);
GPIOA->MODER |=(1U<<5);

**Setting alternate function type to PA7**
<img width="1358" height="844" alt="image" src="https://github.com/user-attachments/assets/73698cfd-2459-49ef-b095-068e368ddd8a" />

GPIOA->AFR[0] |=(1U<<8);
GPIOA->AFR[0] |=(1U<<9);
GPIOA->AFR[0] |=(1U<<10);
GPIOA->AFR[0] ~=(1U<<11);

----------------
**Enabling clock access to USART2**
<img width="1326" height="538" alt="image" src="https://github.com/user-attachments/assets/e0a9f0ec-dfe5-47d8-bf0e-839276483d3e" />

#define UARTEN  (1U<<17)

RCC->APB1ENR |=UARTEN;

**Configuring UART Baud rate**
This is something dine with the help of a separate functions
