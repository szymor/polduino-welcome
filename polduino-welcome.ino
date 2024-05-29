#define WARSAW_LED  (13)
#define SPEAKER     (10)
#define UART_RX     (0)
#define UART_TX     (1)

void setup() {
  // put your setup code here, to run once:
  pinMode(WARSAW_LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(WARSAW_LED, 0);
  delay(500);
  digitalWrite(WARSAW_LED, 1);
  delay(500);
}
