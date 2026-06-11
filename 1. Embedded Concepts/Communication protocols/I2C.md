## **Inter integrated circuit**

- It has 2 lines SDA and SCL, serial data line and serial clock line respectively
- These 2 lines are used for communication
- Initial state of both lines are high with the help of 2 pullup resistors.(Not mandatory though)
- Works in master-slave method

<img width="1093" height="847" alt="image" src="https://github.com/user-attachments/assets/e55e7a74-f909-469e-875c-0ce2b0e76ac0" />

**2 cases** here,
             **- **Master sends data to slave****
             **- Master reads data from slave**
----------------------------------------------------------------------------------------------------------------------------------------------

**Master sends data to slave**
  - Normally, SDA and SCL both are high. First a start bit is sent **logic 0**

<img width="2294" height="372" alt="image" src="https://github.com/user-attachments/assets/dc12b3dd-49f2-4e54-936b-dbc8fa2d6b62" />


  - 1st, master will send start bit **logic 0** by pulling SDA low.
  - Now, master sends the address of the slave that it wants to communicate with on the SDA line.
  - Next, master sends read/write bit. Our case, it is write bit so **logic 0**
  - After this, slave give acknowledgement by giving ack bit. **logic 0** means it is ready for comm
  - Now, data will be sent by master to slave
  - Another ack bit by slave to confirm data transfer
  - Finally stop bit **logic 0** by master. After this both SDA and SCL goes high
--------------------------------------------------------------------------------------------------------------------------------------------------

## I2C arbitration and stretching

### I2C arbitration
This happens when **2 devices** try to take control over the bus.

![I2C Arbitration](https://github.com/user-attachments/assets/c596de12-b287-49ba-84ac-01c2887a5460)

- Here 2 devices try to control the bus  
- Before explaining I2C arbitration, we need to remember that I2C is a **wired AND logic**  
  - Initially both SDA and SCL are HIGH  
  - Devices cannot drive HIGH, only pull LOW or release  
  - If device B pulls LOW → line becomes LOW (**wired AND**)  

- So, the device which sends **0** controls the line  
- This is called **arbitration**
----------------------------------------------------------------------------------------------------------------------------------------------------------

## I2C Clock Stretching

- Clock stretching is used when the **slave is not ready** to continue communication.

<img width="2035" height="1186" alt="image" src="https://github.com/user-attachments/assets/faa87ca0-4d53-48fe-bc97-84d4aad7cac7" />

- In I2C:
  - Master generates the clock (**SCL**)  
  - But slave can **hold SCL LOW**

- Working:
  - Master tries to make SCL HIGH  
  - Slave keeps SCL LOW → clock is paused  
  - Master must **wait**  
  - Once slave releases SCL → communication continues  

- Reason:
  - Slave needs time to:
    - Process data  
    - Prepare next byte  
    - Perform internal operations  

- Important points:
  - Only **SCL is stretched**, not SDA  
  - Based on **wired AND logic**  
    - If any device pulls LOW → line stays LOW  
  - Master cannot force SCL HIGH  

- Result:
  - No data loss ✅  
  - Synchronization maintained ✅  

- In short:
  - Slave temporarily **controls timing**
 
  ------------------------------------------------------------------------------------------------------
  ## What happens to SCL in I2C protocol?
   - **Idle State**: When the bus is idle, SCL is pulled HIGH by resistors.
   - **Start/Stop Conditions**: SCL must be high when the SDA line transitions, signaling the start or end of transmission.
   - **Data Synchronization:** For every bit of data transferred on the SDA line, the master generates one pulse on the SCL line.
                               Data is typically valid when SCL is high and changes when SCL is low.

