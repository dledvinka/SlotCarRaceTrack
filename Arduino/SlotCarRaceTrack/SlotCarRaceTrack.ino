/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int LED = 5;
int brightness = 0;    // how bright the LED is
int STEPS = 10;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(LED, OUTPUT);
  Serial.begin(19200);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int posY = analogRead(A0);
  int posX = analogRead(A1);

  int posYMapped = map(posY, 0, 1023, -STEPS, STEPS);
  int posXMapped = map(posX, 0, 1023, -STEPS, STEPS);

  int pos = max(abs(posYMapped), abs(posXMapped));
  int brightness = map(pos, 0, STEPS, 0, 255);
  
  // print out the value you read:
  Serial.println(String("X = ") + posX + String(", Y = ") + posY);
  Serial.println(String("MX = ") + posXMapped + String(", MY = ") + posYMapped);
  Serial.println(String("Brightness = ") + brightness);
  analogWrite(LED, brightness);
  delay(25);        // delay in between reads for stability
  
}
