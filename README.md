
# Ultrasonic Water Level Alert System

This Arduino-based project uses an **HC-SR04 ultrasonic sensor** to monitor the water level inside a tank. If the water drops below a defined threshold (e.g. 80 cm from the sensor), a **buzzer** will automatically activate to alert the user.

> Simple. Accurate. Reliable. Perfect for home automation, agriculture, and IoT water monitoring.

---

## Features

- **Distance Measurement** using ultrasonic sensor
- **Low Water Level Alert** with buzzer
- Calibrated for tanks up to **400 cm height**
- **Real-time** data output via Serial Monitor
- Built with **ESP32**, but easily portable to Arduino/AVR

---

## Hardware Required

- **1x ESP32** or Arduino board  
- **1x HC-SR04** ultrasonic sensor  
- **1x Active Buzzer**  
- **Jumper wires**  
- **Power source**

---

## Wiring Guide

| Component   | ESP32 Pin  |
|-------------|------------|
| HC-SR04 VCC | 5V or 3.3V |
| HC-SR04 GND | GND        |
| HC-SR04 TRIG| GPIO 23    |
| HC-SR04 ECHO| GPIO 22    |
| Buzzer (+)  | GPIO 21    |
| Buzzer (–)  | GND        |

---

## Code

<pre>

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
  </pre>

---

How It Works

1. The ultrasonic sensor sends a high-frequency sound wave and calculates how long it takes for the echo to return.


2. The distance is calculated using the speed of sound in air.


3. If the water level is lower than 80 cm, the buzzer activates.


4. Otherwise, it stays silent.




---

Use Cases

Overhead Water Tanks

Agricultural Irrigation

Smart Homes

Rainwater Collection Systems



---

License

This project is licensed under the MIT License.


---

Author

HexSec — @codejoaker13
Cybersecurity Researcher & DIY Creator
Follow on GitHub: HexSecGuru


