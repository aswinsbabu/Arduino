#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// TFT pins for Arduino UNO
#define cs   10
#define dc   9
#define rst  8
Adafruit_ST7735 TFTscreen = Adafruit_ST7735(cs, dc, rst);

// Joystick pins
#define VRX A0
#define VRY A1
#define SW  2

// Screen size
#define SCREEN_W 128
#define SCREEN_H 160

// Snake variables
#define GRID_SIZE 8
#define MAX_SNAKE_LEN 100
int snakeX[MAX_SNAKE_LEN];
int snakeY[MAX_SNAKE_LEN];
int snakeLength = 3;
int dirX = GRID_SIZE;
int dirY = 0;

// Apple
int appleX, appleY;

// Timing
unsigned long lastMoveTime = 0;
const unsigned long moveInterval = 200;  // Snake speed (ms)

void setup() {
  TFTscreen.initR(INITR_BLACKTAB);
  TFTscreen.fillScreen(ST77XX_BLACK);

  pinMode(SW, INPUT_PULLUP);

  // Initialize snake position
  for (int i = 0; i < snakeLength; i++) {
    snakeX[i] = SCREEN_W / 2 - i * GRID_SIZE;
    snakeY[i] = SCREEN_H / 2;
  }

  spawnApple();
}

void loop() {
  handleInput();
  if (millis() - lastMoveTime > moveInterval) {
    moveSnake();
    lastMoveTime = millis();
  }
}

// Handle joystick input
void handleInput() {
  int xVal = analogRead(VRX);
  int yVal = analogRead(VRY);

  if (xVal < 400 && dirX == 0) { dirX = -GRID_SIZE; dirY = 0; }
  if (xVal > 600 && dirX == 0) { dirX = GRID_SIZE;  dirY = 0; }
  if (yVal < 400 && dirY == 0) { dirX = 0; dirY = -GRID_SIZE; }
  if (yVal > 600 && dirY == 0) { dirX = 0; dirY = GRID_SIZE; }
}

// Move snake
void moveSnake() {
  // Clear last tail
  TFTscreen.fillRect(snakeX[snakeLength-1], snakeY[snakeLength-1], GRID_SIZE, GRID_SIZE, ST77XX_BLACK);

  // Shift body
  for (int i = snakeLength-1; i > 0; i--) {
    snakeX[i] = snakeX[i-1];
    snakeY[i] = snakeY[i-1];
  }

  // Move head
  snakeX[0] += dirX;
  snakeY[0] += dirY;

  // Check collision with wall
  if (snakeX[0] < 0 || snakeX[0] >= SCREEN_W || snakeY[0] < 0 || snakeY[0] >= SCREEN_H) {
    gameOver();
    return;
  }

  // Check collision with itself
  for (int i = 1; i < snakeLength; i++) {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
      gameOver();
      return;
    }
  }

  // Draw head (Green)
  TFTscreen.fillRect(snakeX[0], snakeY[0], GRID_SIZE, GRID_SIZE, TFTscreen.color565(0, 255, 0));

  // Check if apple eaten
  if (snakeX[0] == appleX && snakeY[0] == appleY) {
    if (snakeLength < MAX_SNAKE_LEN) snakeLength++;
    spawnApple();
  }
}

// Spawn apple at random position
void spawnApple() {
  appleX = random(0, SCREEN_W / GRID_SIZE) * GRID_SIZE;
  appleY = random(0, SCREEN_H / GRID_SIZE) * GRID_SIZE;
  TFTscreen.fillRect(appleX, appleY, GRID_SIZE, GRID_SIZE, TFTscreen.color565(255, 0, 0)); // Red apple
}

// Game Over routine
void gameOver() {
  TFTscreen.fillScreen(ST77XX_BLACK);
  TFTscreen.setTextColor(TFTscreen.color565(255, 0, 0));
  TFTscreen.setTextSize(2);
  TFTscreen.setCursor(15, SCREEN_H/2 - 10);
  TFTscreen.print("Game Over!");
  delay(2000);
  resetGame();
}

// Reset game
void resetGame() {
  snakeLength = 3;
  dirX = GRID_SIZE;
  dirY = 0;
  for (int i = 0; i < snakeLength; i++) {
    snakeX[i] = SCREEN_W / 2 - i * GRID_SIZE;
    snakeY[i] = SCREEN_H / 2;
  }
  TFTscreen.fillScreen(ST77XX_BLACK);
  spawnApple();
}
