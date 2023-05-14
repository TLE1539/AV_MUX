# AV_MUX

Code to control an Arduino Nano that interfaces between a 
Raspberry Pi controller and two parallel input 8X1 MUXs (SparkFun 74HC4501)
for 8X2 analog video (AV) multiplexing applications

Communication Protocols
* Nano <-> rPi : UART
* Nano <-> MUX : 3 bit parallel bus

Description of Operation
Receives 2-digit channel selection code (XY) from Serial.
First digit (X) corresponds to the first MUX, second digit (Y) corresponds to the second MUX.
MUX channels are numbered 0 through 7.
(e.g) Input of "25" assigns MUX1 to channel 2 and MUX2 to channel 5

Reference code to program the rPi controller side of the system can be found at:
https://www.electronicwings.com/raspberry-pi/raspberry-pi-uart-communication-using-python-and-c
