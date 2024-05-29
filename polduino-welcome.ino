const int noteFrequencies[] = {
  130, 138, 146, 155, 164, 174, 185, 196, 207, 220, 233, 246, // Frequencies for octave 3
  261, 277, 293, 311, 329, 349, 370, 392, 415, 440, 466, 493, // Frequencies for octave 4
  523, 554, 587, 622, 659, 698, 740, 784, 830, 880, 932, 987  // Frequencies for octave 5
};

enum MusicalNote {
  NOTE_C3, NOTE_C3S, NOTE_D3, NOTE_D3S, NOTE_E3, NOTE_F3, NOTE_F3S, NOTE_G3, NOTE_G3S, NOTE_A3, NOTE_A3S, NOTE_B3,
  NOTE_C4, NOTE_C4S, NOTE_D4, NOTE_D4S, NOTE_E4, NOTE_F4, NOTE_F4S, NOTE_G4, NOTE_G4S, NOTE_A4, NOTE_A4S, NOTE_B4,
  NOTE_C5, NOTE_C5S, NOTE_D5, NOTE_D5S, NOTE_E5, NOTE_F5, NOTE_F5S, NOTE_G5, NOTE_G5S, NOTE_A5, NOTE_A5S, NOTE_B5
};

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
}

void loop() {
}
