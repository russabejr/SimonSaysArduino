// LED and button pin mappings
const int ledPins[4] = {12, 13, 4, 5};      // LEDs
const int buttonPins[4] = {6, 7, 8, 9};     // Buttons

const int maxRounds = 100;                 // Max sequence length
int sequence[maxRounds];                  // Stores the random sequence
int currentRound = 0;                     // How far the player has gotten

// Time settings (in ms)
const int ledOnTime = 500;
const int ledOffTime = 200;
const int inputDelay = 50;

void setup() {
  // Initialize LED pins
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
  }

  // Initialize button pins
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(0)); // Seed randomness
}

void loop() {
  waitForStart();

  currentRound = 1;

  while (true) {
    generateNextColor();
    playSequence();
    if (!getUserInput()) {
      loseAnimation();
      break;
    }
    delay(500); // Short pause between rounds
    currentRound++;
  }
}

// Waits for any button press to start the game
void waitForStart() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        delay(200); // Debounce delay
        return;
      }
    }
  }
}

// Adds a new random LED to the sequence
void generateNextColor() {
  sequence[currentRound - 1] = random(0, 4);
}

// Plays the current sequence
void playSequence() {
  delay(500); // Delay before sequence plays
  for (int i = 0; i < currentRound; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], LOW);
    delay(ledOnTime);
    digitalWrite(ledPins[led], HIGH);
    delay(ledOffTime);
  }
}

// Waits for user input and checks if it's correct
bool getUserInput() {
  for (int i = 0; i < currentRound; i++) {
    int input = waitForButtonPress();
    if (input != sequence[i]) {
      return false;
    }
  }
  return true;
}

// Waits until one of the buttons is pressed, returns index
int waitForButtonPress() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        // Light up the LED to give feedback
        digitalWrite(ledPins[i], LOW);
        delay(ledOnTime);
        digitalWrite(ledPins[i], HIGH);
        delay(inputDelay);
        // Wait for button release
        while (digitalRead(buttonPins[i]) == LOW);
        delay(inputDelay);
        return i;
      }
    }
  }
}

// Plays the losing animation (right to left flashing)
void loseAnimation() {
  for (int i = 0; i < 3; i++) {
    for (int j = 3; j >= 0; j--) {
      digitalWrite(ledPins[j], LOW);
      delay(100);
      digitalWrite(ledPins[j], HIGH);
    }
  }
  delay(1000);
}
