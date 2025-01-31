
/*
 * function doGet(e) {
  var sheet = SpreadsheetApp.openById('YOUR_SPREADSHEET_ID').getSheetByName('Sheet1'); 
  if (!sheet) {
    return ContentService.createTextOutput("Error: Sheet not found");
  }

  var candidate = e.parameter.candidate;
  var voteCount = e.parameter.voteCount;

  if (candidate && voteCount) {
    sheet.appendRow([new Date(), candidate, voteCount]);
    return ContentService.createTextOutput("Success");
  } else {
    return ContentService.createTextOutput("Error: Missing parameters");
  }
}
*/


#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "Narishimas";
const char* password = "7020367194";

// Pin configuration for buttons, LEDs, and buzzer
const int buttonPins[] = {D5, D6, D7};  // 3 buttons for candidates
const int ledPins[] = {D3, D4, D0};     // 3 LEDs for candidates
const int buzzerPin = D8;               // Buzzer pin
const String candidateNames[] = {"UDF", "BJP", "LDF"};
int voteCounts[] = {0, 0, 0};           // Initial vote count for each candidate

int lastButtonStates[3] = {HIGH, HIGH, HIGH};
unsigned long lastDebounceTimes[3] = {0, 0, 0};
const unsigned long debounceDelay = 200;

//LiquidCrystal_I2C lcd(0x27, 16, 2);

// Google Apps Script URL
const String googleSheetUrl = "https://script.google.com/macros/s/AKfycbx4YcotGvPV4aVmPACl5h0_w3zw79iBoaq-bFmP_Iq7_UTEybbajn0cR_ekLsGWchLRBQ/exec"; // Replace YOUR_SCRIPT_ID

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  //lcd.begin();
  //lcd.setBacklight(1);
  //lcd.clear();
  //lcd.print("Connecting...");
  int wifiAttempts = 0;

  while (WiFi.status() != WL_CONNECTED && wifiAttempts < 30) {
    delay(1000);
    Serial.print(".");
    wifiAttempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    //lcd.clear();
    //lcd.print("Wi-Fi Connected");
    Serial.println("\nWi-Fi Connected");
  } else {
    //lcd.clear();
    //lcd.print("Wi-Fi Failed!");
    Serial.println("\nWi-Fi Connection Failed");
    while (true); // Stop if Wi-Fi fails
  }

  delay(2000);
  //lcd.clear();
  //lcd.print("      EVM");

  // Configure button, LED, and buzzer pins
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Ensure LEDs are off initially
  }

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); // Ensure buzzer is off initially
}

void loop() {
  // Check each button for votes
  for (int i = 0; i < 3; i++) {
    int buttonState = digitalRead(buttonPins[i]);
    
    // Detect button press with debounce
    if (buttonState != lastButtonStates[i] && (millis() - lastDebounceTimes[i] > debounceDelay)) {
      lastDebounceTimes[i] = millis(); // Update debounce timer
      
      if (buttonState == LOW) {  // Button is pressed
        activateBuzzer(); // Turn on the buzzer

        voteCounts[i]++; // Increment vote count
        Serial.print("Vote Count for ");
        Serial.print(candidateNames[i]);
        Serial.print(": ");
        Serial.println(voteCounts[i]);

        // Indicate vote on //lcd and LED
        //lcd.clear();
        //lcd.print("Voted for:");
        //lcd.setCursor(0, 1);
        //lcd.print(candidateNames[i]);
        digitalWrite(ledPins[i], HIGH); // Turn on LED
        delay(1000);                   // Hold display for 1 second
        digitalWrite(ledPins[i], LOW); // Turn off LED

        deactivateBuzzer(); // Turn off the buzzer

        // Send vote to Google Sheets
        sendVoteToGoogleSheet(candidateNames[i], voteCounts[i]);

        // Reset //lcd message
        //lcd.clear();
        //lcd.print("      EVM");
      }
    }
    lastButtonStates[i] = buttonState; // Update button state
  }

  delay(100); // Short delay before next loop iteration
}

void activateBuzzer() {
  digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
}

void deactivateBuzzer() {
  digitalWrite(buzzerPin, LOW); // Turn off the buzzer
}

void sendVoteToGoogleSheet(String candidate, int voteCount) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClientSecure client;  // HTTPS client
    client.setInsecure();     // Bypass SSL verification (simplifies testing)

    // Construct the request URL with candidate and vote count
    String url = googleSheetUrl + "?candidate=" + candidate + "&voteCount=" + String(voteCount);
    Serial.print("Sending request to: ");
    Serial.println(url);

    // Make HTTP GET request
    http.begin(client, url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String response = http.getString();
      Serial.println("Response: " + response);
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }

    http.end(); // Close the connection
  } else {
    Serial.println("Wi-Fi not connected. Data not sent.");
    //lcd.clear();
    //lcd.print("Wi-Fi Error!");
    delay(1000);
    //lcd.clear();
    //lcd.print("      EVM");
  }
}
