**Universal Asynchronous Receiver Transmitter**


- Protocol for exchanging serial data between 2 devices
- Uses 2 wires TX and RX
- Can be simplex, half duplex or full duplex

Tech stuff
 - It is asynchronous (doesn't have common clock signal)
 - TX and RX must transmit at a same (known) speed               <img width="529" height="844" alt="image" src="https://github.com/user-attachments/assets/acfa4c95-ddee-4803-b4aa-4cac9a2ec1b1" />
 - Both devices should be configured with same transmission speed(baud rate)


<img width="868" height="266" alt="image" src="https://github.com/user-attachments/assets/7a4cf9b4-0d60-4b33-a33b-c3de5a9eb2af" />

**Lets say dev 1 wants to send data to device 2**
- The ideal stae will be high
- A start bit willl be sent **(logic 0)** . Now dev 2 unds tha somebody is comm over here.
- After this data is transferred.
- Now optionally a parity bit for error correction
- Finally stop bit **(logic 1)**

<img width="1145" height="267" alt="image" src="https://github.com/user-attachments/assets/7eed115c-90f5-4ff6-860d-4edd0e23fdd5" />
_____________________________________________________________________________________________________________________________________________

   **What is baud rate ?** - The speed at which data is transmitted
   
   **Why baud rates are fixed ?** - Baud rates are not fixed, it is standardised like 9600 etc.
                              - Normally baud rate = clock divider/frequeny
                     `        - Devices have run on a fixed clock freq like 1MHz, 8MHz etc
                                Standared baud rates are chosen because they result in clean integer divisions minimising timing errors.
                                ex - 1.8432 Mhz/192 = 9600
