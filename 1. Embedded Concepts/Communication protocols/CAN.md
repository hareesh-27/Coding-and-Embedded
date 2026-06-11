## CAN - Controller Area Network

Can was initialyy developed by bosch mainly for automotive applications to address the issue of complex wiring. But later is used in wide reas.
-------------------------------------------------------------------------------------------------------------------------------------------------

CAN is a 2 wire protocol.
 - It has 2 buses : CANH and CANL
 - It is an asynchronous protocol
 - Each device on the CAN bus is called as node. The dev which sends data TX, receive RX.
 - CAN is a **multimaster** and **multicast** protocol
       - **multimaster** : Any node can behave/work as a master
       - **multicast :**  If TX sends data, at a time all other nodes receives data. The node which doesnt want the data filters it.
 - It is a messaged based protocol. Each message has an priority num (identifier)
 - There are 2 types of CAN - Stanndard and extended. 11 bit and 29 bit identifier respecfively
 - Each message is in the form of frames.
      - Data frame
      - Error frame
      - Remote frame
      - Overload frame


  <img width="1196" height="293" alt="image" src="https://github.com/user-attachments/assets/c7cc3273-ce06-4094-8940-ea2f72b45ee0" />


  <img width="1365" height="230" alt="image" src="https://github.com/user-attachments/assets/7341e378-d2be-4f31-bbd0-b40bc7e33b4e" />

  **Expl:**

   <img width="2025" height="1239" alt="image" src="https://github.com/user-attachments/assets/24d112d0-b604-41c6-b449-f650d760ebf6" />


   - In CAN frame there are multiple fields
      - SOF :Start of frame
      - Arbiteration field: 11 bit identifier and RTR (Remote transmission request)
      - Control field: IDE, r0, DLC (Data Length Code)
      - Data
      - CRC
      - ACK
      - EOF
    
  ## SOF  
Start of Frame  
- This is always 0.  
- 0 is the dominant bit in CAN  

## Arbitration Field  
It contains 11-bit Identifier and RTR  

- **Identifier**: Indicates the priority of the message.  
  - Lower value (more 0s) → higher priority  
- **RTR**: Indicates whether the frame is a remote frame  
  - 1 → Remote frame  
  - 0 → Data frame  

## Control Field  
It contains IDE, r0 and DLC  

- **IDE**: Identifier Extension bit  
  - Indicates whether the identifier is 11-bit or 29-bit  
  - Dominant (0) → 11-bit identifier  
- **r0**: Reserved bit for future use  
  - Kept for future features without modifying protocol  
- **DLC**: Data Length Code  
  - Indicates the length of actual data  

## Data  
- If data length is 2 bytes, then DLC = 2 (0010)  

## CRC  
Cyclic Redundancy Check  
- Used to detect errors in received data  

## ACK  
Acknowledgement bit  
- Receiver makes this bit dominant (0) after successful reception  

## EOF  
- 7 continuous recessive bits (1s) indicate end of frame  

