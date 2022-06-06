
int vib_pin=D4;
void setup() {
  pinMode(vib_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  int val;
  long data= vibrations();
  Serial.println(data);
  delay(200);
  
}

long vibrations(){
  long value=pulseIn(vib_pin,HIGH);
  return value;
  }
