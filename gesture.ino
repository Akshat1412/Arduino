long duration1, duration2;
int distance1, distance2;
unsigned long temp = 0, temp1 = 0;
void find_distance();
void find_distance()
{
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  duration1 = pulseIn(4, HIGH);
  distance1 = 0.017 * duration1;
  delay(200);
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  duration2 = pulseIn(8, HIGH);
  distance2 = 0.017 * duration2;
  delay(200);
}
void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  pinMode(12, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  find_distance();
  if (distance1 >= 10 && distance1 <= 30)
  {
    temp1 = millis();
    while (millis() < (temp1 + 300))
      find_distance();
    if (distance1 >= 10 && distance1 <= 30)
    {
      temp1 = distance1;
      while (distance1 < 40 || distance1 == 0)
      {
        find_distance();
        if ((temp1 + 5) < distance1)
        {

          Serial.println("on/off");
        }
        else if ((temp1 - 5) > distance1)
        {

          Serial.print("mute");
        }
      }
    }
    else {

      Serial.println("channel left");
    }
  }

  else if (distance2 >= 10 && distance2 <= 25)
  {
    temp = millis();
    while (millis() < (temp + 300))
      find_distance();
    if (distance2 >= 10 && distance2 <= 25)
    {
      temp = distance2;
      while (distance2 < 40 || distance2 == 0)
      {
        find_distance();
        if ((temp + 5) < distance2)
        {

          Serial.println("vol+");
        }
        else if ((temp - 5) > distance2)
        {

          Serial.print("vol-");
        }
      }
    }
    else {

      Serial.println("channel right");

    }
  }

  else
  {
    Serial.println(distance1);
    Serial.println(distance2);
  }
}
