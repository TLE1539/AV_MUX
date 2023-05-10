# AV_MUX

Code to control an Arduino Nano that interfaces between a 
Raspberry Pi controller and two parallel input 8X1 MUXs (SparkFun 74HC4501)
for 8X2 analog video (AV) multiplexing applications

Communication Protocols
* Nano <-> rPi : UART
* Nano <-> MUX : 3 bit parallel bus

Reference code to program the rPi controller side of the system can be found at:
https://www.electronicwings.com/raspberry-pi/raspberry-pi-uart-communication-using-python-and-c
