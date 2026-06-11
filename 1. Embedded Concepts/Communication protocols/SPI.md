## Serial Peripheral Interface Protocol

**4 main concepts in SPI**
 - **Slave Select (SS):** In Slave Select, each slave device contains a dedicated SS pin.
   If the master will communicate with the specific slave. Multiple slave devices can be shared with the as same as MOSI, MISO, and SCK lines but it must have separated SS lines.
 
 - **Master Out Slave In (MOSI):** In Master Out Slave In, MOSI can share the data or information from the master to other slave devices.
  
 - **Master In Slave Out (MISO):** In Master In Slave Out, MISO can share the data or information from the slave device with the master.
 
 - **Serial Clock (SCK):** In Serial Clock, this clock signal is used by the master and the slave devices for coordinating the data transfer timings.


**Additional concepts**
  - CPOL and CPHA

    <img width="2209" height="1097" alt="image" src="https://github.com/user-attachments/assets/6f3e739c-3f52-42e6-9bd5-7fc9826884d5" />

    <img width="2109" height="972" alt="image" src="https://github.com/user-attachments/assets/2d21a491-8a88-4b92-9ac9-7a61843dfb96" />

