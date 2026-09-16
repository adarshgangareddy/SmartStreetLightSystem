const int LDR_PIN = 7;

const int IR_SENSOR_1_PIN = 2;
const int IR_SENSOR_2_PIN = 3;
const int IR_SENSOR_3_PIN = 4;
const int IR_SENSOR_4_PIN = 5;

const int LED_1_PIN = 6;
const int LED_2_PIN = 9;
const int LED_3_PIN = 10;
const int LED_4_PIN = 11;

const int DIM_BRIGHTNESS = 60;
const int FULL_BRIGHTNESS = 255;

void setup() {
  pinMode(LDR_PIN, INPUT);

  pinMode(IR_SENSOR_1_PIN, INPUT);
  pinMode(IR_SENSOR_2_PIN, INPUT);
  pinMode(IR_SENSOR_3_PIN, INPUT);
  pinMode(IR_SENSOR_4_PIN, INPUT);

  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
}

void loop() {
  const bool isNight = digitalRead(LDR_PIN) == LOW;

  if (!isNight) {
    analogWrite(LED_1_PIN, 0);
    analogWrite(LED_2_PIN, 0);
    analogWrite(LED_3_PIN, 0);
    analogWrite(LED_4_PIN, 0);
    return;
  }

  analogWrite(LED_1_PIN, digitalRead(IR_SENSOR_1_PIN) == LOW ? FULL_BRIGHTNESS : DIM_BRIGHTNESS);
  analogWrite(LED_2_PIN, digitalRead(IR_SENSOR_2_PIN) == LOW ? FULL_BRIGHTNESS : DIM_BRIGHTNESS);
  analogWrite(LED_3_PIN, digitalRead(IR_SENSOR_3_PIN) == LOW ? FULL_BRIGHTNESS : DIM_BRIGHTNESS);
  analogWrite(LED_4_PIN, digitalRead(IR_SENSOR_4_PIN) == LOW ? FULL_BRIGHTNESS : DIM_BRIGHTNESS);
}
