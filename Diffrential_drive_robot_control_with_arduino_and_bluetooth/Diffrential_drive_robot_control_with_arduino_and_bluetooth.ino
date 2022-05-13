int mp1a=2;
int mp1b=4;
int mp1c=5;
int mp1d=8;  
//int en1a=11;
//int en1b=10;
//int mp2a=12;
//int mp2b=7;
//int en2b=9;

char msg ;

void setup()
{
   pinMode(2,OUTPUT);
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(8,OUTPUT);
   Serial.begin(9600);
}

void moveBackward()
{
//  SetSpeed(90);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
}
void moveForward()
{
  //SetSpeed(100);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(8, LOW);
}
void spotRight()
{
//    SetSpeed(90);

  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(8, LOW);
}
//void SetSpeed(int Speed)
//{
//analogWrite(5, Speed);  
//}

void spotLeft()
{
//      SetSpeed(90);

  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);                                //right in 36 37      
}
void Stop()
{
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(8, LOW);
}
void arcright()
{
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(8, LOW);
}
void arcleft()
{
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(8, LOW);
}
void barcright()
{
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
}
void barcleft()
{
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(8, LOW);
}

void loop()
 {
  if (Serial.available() > 0)
  {
    msg = Serial.read();


    if (msg == 'F')
    {
      moveForward();
      Serial.print("forward");

    }
    else if (msg == 'B')
    {
      moveBackward();

    }
    else if (msg == 'L')
    {
      spotLeft();

    }
    else if (msg == 'R')
    {
      spotRight();
    }
       else if(msg =='I')
    {
      arcright();
    }
        else if(msg =='G')
    {
      arcleft();
    }
    else if(msg =='J')
    {
      barcright();
    }
        else if(msg =='H')
    {
      barcleft();
    }    
    else
    {
     Stop();
    }
  }
}
