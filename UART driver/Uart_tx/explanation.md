## Code explained

```c
#include <stdint.h>
#include "stm32f4xx.h"
```

These 2 are header files

- stdint provides uint32_t, uint16_t. Basically uints
- stm32f4xx.h is the CMSIS file downloaded from st.com which is provided by ST/CMSIS. It contains register structures, peripheral base addresses, bit definitions, and macros like USART2 and GPIOA, allowing us to access registers using the -> operator.

---

Next we will come to **main function** where we **initialise uart**
So the first line inside main function is initialising uart -
```c
uart2_tx_init(void);
```

## **uart2_tx_init(void)**

There is a step by step process to make uart_tx work succesfully. Also we need to rember that we are operating in **Asynchronous mode**, so it behaves lik UART

First we understand that we are working on USART2 present in APB1 peripheral.

<img width="358" height="570" alt="image" src="https://github.com/user-attachments/assets/ea70410c-225e-4900-a395-3714cb3b2686" />
