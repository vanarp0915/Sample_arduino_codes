//Project14-Nanorama- Arduino Nano bot- using RC controller sensor   


//Motor Driver Pin Connections to Arduino Nano 
int AIN1 = 4;
int AIN2 = 2;
int PWMA = 5;
int BIN1 = 7;
int BIN2 = 8;
int PWMB= 6;
int STBY = 13;
//RC controller pin connection
const int CH1 = 9;//pitch - controls foward/backward and speed
const int CH2 = 10; //roll - controls left and right


// Parameters
const int deadzone = 20;  // Anything between -20 and 20 is stop


void setup() {
  //Serial.begin(9600); 
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  
  digitalWrite(STBY, HIGH);
}


void loop() {


  // Reading channel inputs
  int x = pulseIn(CH1, HIGH, 25000);
  int y = pulseIn(CH2, HIGH, 25000);
  /*Serial.print("ch1_pitch : ");  
  Serial.println(x);  
  Serial.print("ch2_roll: ");  
  Serial.println(y);*/


  // Convert to PWM value
  y = pulseToPWM(y);
  x = pulseToPWM(x);


  // using the arcade drive algo based on https://www.youtube.com/watch?v=Bx0y1qyLHQ4
  int left = y + x;
  int right = y - x;
  drive(left, right);
  delay(5);
}




void drive(int speed_a, int speed_b) {
  // Limit speed between -255 and 255
  speed_a = constrain(speed_a, -255, 255);
  speed_b = constrain(speed_b, -255, 255);


  // Set direction for motor A
  if ( speed_a == 0 ) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  } else if ( speed_a > 0 ) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }


  // Set direction for motor B
  if ( speed_b == 0 ) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  } else if ( speed_b > 0 ) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }


  analogWrite(PWMA, abs(speed_a));
  analogWrite(PWMB, abs(speed_b));
}


// Convert RC pulse value to motor PWM value
int pulseToPWM(int pulse) {
  
  // If we're receiving numbers, convert them to motor PWM
  if ( pulse > 1000 ) {
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255, 255);
  } else {
    pulse = 0;
  }


  // Anything in deadzone should stop the motor
  if ( abs(pulse) <= deadzone ) {
    pulse = 0;
  }


  return pulse;
}
