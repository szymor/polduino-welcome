void setup() {
  // put your setup code here, to run once:
  for (int pin = 0; pin <= 13; pin++) {
    pinMode(pin, INPUT);
  }
  for (int pin = A0; pin <= A5; pin++) {
    pinMode(pin, INPUT);
  }

}

void configureGPIO(int pin) {
  // Step 1: Set GPIO as output and in high (1) state
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(100); // Small delay to ensure the state is set

  // Step 2: Set GPIO as output and in low (0) state
  digitalWrite(pin, LOW);
  delay(100); // Small delay to ensure the state is set

  // Step 3: Set GPIO as input with pull-up
  pinMode(pin, INPUT_PULLUP);
  delay(100); // Small delay to ensure the state is set
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pin = 0; pin <= 13; pin++) {
    configureGPIO(pin);
  }
  for (int pin = A0; pin <= A5; pin++) {
    configureGPIO(pin);
  }
}
