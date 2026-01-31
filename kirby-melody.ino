#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047

int melody[] = {
  NOTE_G4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, 
  NOTE_G4, NOTE_A4, NOTE_G4, 
  NOTE_G4, NOTE_GS4, NOTE_A4, 
  NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B5, NOTE_C6
};

int noteDurations[] = {
  8, 16, 4, 4, 4, 4, 4, 8, 8, 4, 8, 8, 4, 4, 4, 4, 2, 16, 4
};

const int BUTTON = 2;
const int SPEAKER = 8;

void setup() {
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(SPEAKER,OUTPUT);
}

void KirbyMelody() {
  for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
    int buttonState = digitalRead(BUTTON);
    int noteDuration = 700 / noteDurations[i];
    tone(SPEAKER, melody[i],noteDuration);
    delay(noteDuration * 1.40);
    noTone(SPEAKER);

    if (buttonState == HIGH) {
      break;
    }
  }
}

void loop() {
  int buttonState = digitalRead(BUTTON);
  if (buttonState == LOW) {
    KirbyMelody();
  }
}