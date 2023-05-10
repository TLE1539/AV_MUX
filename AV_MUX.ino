/**
 * Code to control an Arduino Nano that interfaces between a 
 * Raspberry Pi controller and two parallel input 8X1 MUXs (SparkFun 74HC4501)
 * for 8X2 analog video (AV) multiplexing applications
 * 
 * Communication Protocols
 * Nano <-> rPi : UART
 * Nano <-> MUX : 3 bit parallel bus
 * 
 * Reference code to program the rPi controller side of the system can be found at:
 * https://www.electronicwings.com/raspberry-pi/raspberry-pi-uart-communication-using-python-and-c
 */

// MUX1 AV channel selection control pins
#define MUX1_S0 4
#define MUX1_S1 3
#define MUX1_S2 2

// MUX2 AV channel selection control pins
#define MUX2_S0 7
#define MUX2_S1 6
#define MUX2_S2 5

int8_t cmd1 = 1; // (TEMP) Example of first channel selected within rPi for MUX1 (0b00000001)
int8_t cmd2 = 5; // (TEMP) Example of fourth channel selected within rPi for MUX2 (0b00000101)
int8_t cmd3 = (cmd2 << 3) | cmd1; // (TEMP) Example of logic to be used within rPi to stitch command message together, will need to convert to char datatype before transmitting (0b00101001 -> ')')

void assignCommand(int8_t cmd){
  digitalWrite(MUX1_S0, cmd & 1); // read bit 1 (LSB)
  digitalWrite(MUX1_S1, cmd & 2); // read bit 2
  digitalWrite(MUX1_S2, cmd & 4); // read bit 3
  digitalWrite(MUX2_S0, cmd & 8); // read bit 4
  digitalWrite(MUX2_S1, cmd & 16); // read bit 5
  digitalWrite(MUX2_S2, cmd & 32); // read bit 6 (MSB), ignore bit 7 and bit 8
}

void setup() {
  pinMode(MUX1_S0, OUTPUT);
  pinMode(MUX1_S1, OUTPUT);
  pinMode(MUX1_S2, OUTPUT);
  pinMode(MUX2_S0, OUTPUT);
  pinMode(MUX2_S1, OUTPUT);
  pinMode(MUX2_S2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    cmd3 = Serial.read();
  }
  assignCommand(cmd3);
  delay(250);
}
