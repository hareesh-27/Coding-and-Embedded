#include "uart.h"

#define GPIOAEN        (1U<<0)
#define UART2EN        (1U<<17)

#define CR1_RE         (1U<<2)
#define CR1_UE         (1U<<13)

#define SR_RXNE        (1U<<5)

#define SYS_FREQ       16000000
#define APB1_CLK       SYS_FREQ

#define UART_BAUDRATE  115200

static void uart_set_baudrate(USART_TypeDef *USARTx,
                              uint32_t PeriphClk,
                              uint32_t BaudRate);

static uint16_t compute_uart_bd(uint32_t PeriphClk,
                                uint32_t BaudRate);

/******************************************************
 * UART2 RX Initialization
 ******************************************************/
void uart2_rx_init(void)
{
    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set PA3 to Alternate Function Mode */
    GPIOA->MODER &= ~(1U<<6);
    GPIOA->MODER |=  (1U<<7);

    /* Set PA3 Alternate Function to AF07 (USART2_RX) */
    GPIOA->AFR[0] |= (1U<<12);
    GPIOA->AFR[0] |= (1U<<13);
    GPIOA->AFR[0] |= (1U<<14);
    GPIOA->AFR[0] &= ~(1U<<15);

    /* Enable clock access to USART2 */
    RCC->APB1ENR |= UART2EN;

    /* Configure baud rate */
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

    /* Enable Receiver */
    USART2->CR1 = CR1_RE;

    /* Enable USART2 */
    USART2->CR1 |= CR1_UE;
}

/******************************************************
 * Read one character from UART2
 ******************************************************/
char uart2_read(void)
{
    /* Wait until receive data register is not empty */
    while(!(USART2->SR & SR_RXNE)){}

    /* Return received character */
    return USART2->DR;
}

static void uart_set_baudrate(USART_TypeDef *USARTx,
                              uint32_t PeriphClk,
                              uint32_t BaudRate)
{
    USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk,
                                uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
