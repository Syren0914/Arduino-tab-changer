#define TRIG_PIN 12
#define ECHO_PIN 13

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.0343 / 2;

  // Send message if someone is close
  if (distance > 0 && distance < 100) { // person detected within 100 cm
    Serial.println("DETECTED");
  } else {
    Serial.println("CLEAR");
  }

  delay(500);  // adjust as needed
}