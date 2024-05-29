const int noteFrequencies[] = {
  130, 138, 146, 155, 164, 174, 185, 196, 207, 220, 233, 246, // Frequencies for octave 3
  261, 277, 293, 311, 329, 349, 370, 392, 415, 440, 466, 493, // Frequencies for octave 4
  523, 554, 587, 622, 659, 698, 740, 784, 830, 880, 932, 987  // Frequencies for octave 5
};

enum MusicalNote {
  NOTE_C3, NOTE_C3S, NOTE_D3, NOTE_D3S, NOTE_E3, NOTE_F3, NOTE_F3S, NOTE_G3, NOTE_G3S, NOTE_A3, NOTE_A3S, NOTE_B3,
  NOTE_C4, NOTE_C4S, NOTE_D4, NOTE_D4S, NOTE_E4, NOTE_F4, NOTE_F4S, NOTE_G4, NOTE_G4S, NOTE_A4, NOTE_A4S, NOTE_B4,
  NOTE_C5, NOTE_C5S, NOTE_D5, NOTE_D5S, NOTE_E5, NOTE_F5, NOTE_F5S, NOTE_G5, NOTE_G5S, NOTE_A5, NOTE_A5S, NOTE_B5,
  REST
};

#define WARSAW_LED  (13)
#define SPEAKER     (10)
#define UART_RX     (0)
#define UART_TX     (1)

#define N32   (100)
#define N16   (2 * N32)
#define N8    (2 * N16)
#define N4    (2 * N8)
#define N2    (2 * N4)
#define N1    (2 * N2)

#define BEAM  (0x80)

void generateSignal(int frequency, int durationMs) {
  int period = 1000000 / frequency; // Period in microseconds
  int halfPeriod = period / 2; // Half period

  digitalWrite(WARSAW_LED, LOW);
  unsigned long startTime = millis();
  unsigned long diff = 0;
  while (diff < durationMs) {
    if (diff > 100)
      digitalWrite(WARSAW_LED, HIGH);

    digitalWrite(SPEAKER, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(SPEAKER, LOW);
    delayMicroseconds(halfPeriod);

    diff = millis() - startTime;
  }

  digitalWrite(WARSAW_LED, HIGH);
}

void playMelody(MusicalNote melody[], int noteDurations[], int size) {
  // Play each note in the melody
  for (int i = 0; i < size / sizeof(melody[0]); i++) {
    int note = melody[i] & (~BEAM);
    int beam = melody[i] & BEAM;
    int duration = noteDurations[i];
    if (note == REST)
      delay(duration);
    else
      generateSignal(noteFrequencies[note], duration - (beam ? 0 : 50));
    if (!beam)
      delay(50); // Short pause between notes
  }
}

void playVerse() {
  // Define the melody and note durations for a verse of the national anthem of Poland
  MusicalNote melody[] = {
    NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_A4 | BEAM, NOTE_G4, NOTE_F4 | BEAM, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, REST,
    NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_A4 | BEAM, NOTE_G4, NOTE_F4 | BEAM, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_G4, NOTE_B3, NOTE_D4, NOTE_C4, REST
  };
  
  int noteDurations[] = {
    N8 + N16, N16, N4, N4, N8 + N16, N16, N8, N8, N8, N8,
    N8 + N16, N16, N4 + N8, N8, N4, N4, N4,
    N8 + N16, N16, N4, N4, N8 + N16, N16, N8, N8, N8, N8,
    N8 + N16, N16, N4 + N8, N8, N4, N4, N4
  };

  playMelody(melody, noteDurations, sizeof(melody));
}

void playChorus() {
  // Define the melody and note durations for the chorus of the national anthem of Poland
  MusicalNote melody[] = {
    NOTE_D4, NOTE_D4, NOTE_F4, NOTE_F4 | BEAM, NOTE_E4, NOTE_E4,
    NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_E4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_B4 | BEAM, NOTE_A4, NOTE_A4,
    NOTE_G4, NOTE_G4, NOTE_F4, NOTE_B3, NOTE_D4, NOTE_C4, REST
  };
  
  int noteDurations[] = {
    N4, N4 + N8, N8, N8, N8, N2,
    N8 + N16, N16, N4, N8, N8, N4, N2,
    N8, N8, N4 + N8, N8, N8, N8, N2,
    N8, N8, N4 + N8, N8, N4, N4, N4
  };

  playMelody(melody, noteDurations, sizeof(melody));
}

void setup() {
  // put your setup code here, to run once:
  pinMode(WARSAW_LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  playVerse();
  playChorus();
  playChorus();
}

void loop() {
  // heartbeat
  digitalWrite(WARSAW_LED, HIGH);
  delay(50);
  digitalWrite(WARSAW_LED, LOW);
  delay(1450);
}
