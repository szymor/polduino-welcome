#define WARSAW_LED  (13)
#define SPEAKER     (10)
#define UART_RX     (0)
#define UART_TX     (1)

void generateSignal(int frequency, int durationMs) {
  int period = 1000000 / frequency; // Period in microseconds
  int halfPeriod = period / 2; // Half period

  unsigned long startTime = millis();
  while (millis() - startTime < durationMs) {
    digitalWrite(SPEAKER, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(SPEAKER, LOW);
    delayMicroseconds(halfPeriod);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(WARSAW_LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  generateSignal(1000, 1000); // Generate a 1kHz signal for 1 second for demonstration
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(WARSAW_LED, 0);
  delay(500);
  digitalWrite(WARSAW_LED, 1);
  delay(500);
}
