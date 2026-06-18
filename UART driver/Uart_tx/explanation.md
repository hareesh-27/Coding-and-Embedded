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

---

## **uart2_tx_init(void)**

<table>
<tr>
<td width="65%">

First we understand that we are working on **USART2** present in the **APB1 peripheral**.

USART2 is connected to the APB1 bus, so before configuring USART2 we must enable its clock using RCC.

</td>

<td width="35%">

<img src="https://github.com/user-attachments/assets/ea70410c-225e-4900-a395-3714cb3b2686" width="250">

</td>
</tr>
</table>



