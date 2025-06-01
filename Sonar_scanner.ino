#include <Servo.h>

Servo myservo;

int trig = 6;
int echo = 5;

int g = 13;
int y = 12;
int r = 11;
int buzzer = 3;

long duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // myservo.write(0);
  for (int deg = 0; deg <= 180; deg++) {
    myservo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delayMicroseconds(1);
    digitalWrite(trig, HIGH);
    delayMicroseconds(1);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    if (distance > 40) {
      Serial.println("No object close by");
      digitalWrite(g, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(r, LOW);
      noTone(buzzer);
    } else if (distance > 10 && distance < 40) {
      Serial.println("Object close by");
      digitalWrite(g, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      tone(buzzer, 100);
    } else if (distance < 10) {
      Serial.println("Object is very close");
      digitalWrite(g, LOW);
      digitalWrite(y, LOW);
      digitalWrite(r, HIGH);
      tone(buzzer, 500);
    }
  }

  for (int deg = 180; deg >= 0; deg--) {
    myservo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delayMicroseconds(1);
    digitalWrite(trig, HIGH);
    delayMicroseconds(1);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    if (distance > 40) {
      Serial.println("No object close by");
      digitalWrite(g, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(r, LOW);
      noTone(buzzer);
    } else if (distance > 10 && distance < 40) {
      Serial.println("Object close by");
      digitalWrite(g, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      tone(buzzer, 100);
    } else if (distance < 10) {
      Serial.println("Object is very close");
      digitalWrite(g, LOW);
      digitalWrite(y, LOW);
      digitalWrite(r, HIGH);
      tone(buzzer, 500);
    }
  }
}
