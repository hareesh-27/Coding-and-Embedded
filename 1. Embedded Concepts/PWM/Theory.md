## PWM

The basic idea of PWM is **controlling the amount of power delivered to a load**

 - One way to control the amount of power delivered to a circuit is turning the voltage ON and OFF
     - In other words : **Providing voltage in the form of pulses**
     - The amplitude (height) remains constant
 
 - We control the amount of time its ON and OFF
     - In other words : **Changing the pulse width**
     - By changing the width, avg voltage is changed
     - Longer ON time means more power delivered to the source and vice versa
This process of changing the pulse width is called PWM

**Two parameters in PWM**
 - Duty Cycle
 - Switching Frequency

## Duty Cycle
Duty Cycle is the percentage of time when signal is ON
                                                             <img width="817" height="1045" alt="image" src="https://github.com/user-attachments/assets/b49df2c6-bd54-4ff1-9f00-df3c342299d2" />

<img width="1711" height="779" alt="image" src="https://github.com/user-attachments/assets/6be5854a-7db9-4f0d-b658-c1f285994b0f" />

V(avg) = D * V(max)
We can see hw the formula came from  the above diagram
  - The area of rectangle (we find area of rectangle coz -> its ON in that region). So area of rectangle = 80% * 5 = 0.80*5
  - => V(avg) = D * V(max)


## Switching Frequency
This says how fast the PWM goes from ON to OFF to ON                                     <img width="842" height="550" alt="image" src="https://github.com/user-attachments/assets/7a1d5d22-0ae6-48b5-925a-9d4da37a753e" />

f = 1/Ton + Toff
