1. Enable GPIOA clock.
2. Configure PA2 as Alternate Function mode.
3. Select AF07 so PA2 becomes USART2_TX.
4. Enable USART2 clock.
5. Configure baud rate by loading BRR.
6. Enable transmitter (TE bit).
7. Enable USART module (UE bit).
8. Wait for TXE flag (Data Register empty).
9. Write character to DR.
10. USART hardware transmits the character through PA2.
11. PC terminal displays the received character.
