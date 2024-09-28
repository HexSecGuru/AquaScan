#define TRIG_PIN 23
#define ECHO_PIN 22
#define BUZZER_PIN 21
#define TANK_HEIGHT 400.0  // Height of the tank in centimeters
#define TARGET_DISTANCE 80.0  // Distance to water when buzzer should beep (80 cm)

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);  // Make sure the buzzer is off initially
}

void loop() {
  // Send a pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the time for the echo to return
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance from the sensor to the water surface in centimeters
  float distanceToWater = (duration / 2.0) * 0.0344;

  // Print the distance to the water
  Serial.print("Distance to Water: ");
  Serial.print(distanceToWater);
  Serial.println(" cm");

  // Check if the distance is less than or equal to the target distance (80 cm)
  if (distanceToWater <= TARGET_DISTANCE) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on the buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);  // Turn off the buzzer
  }

  delay(1000);  // Update every second
}