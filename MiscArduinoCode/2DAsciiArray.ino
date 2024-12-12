// Define a 2D array with ASCII values
//global variable
char ascii_val[2][26] = { 
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
  {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90}
};

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  //display_ascii();
  
}

void display_ascii(){
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 26; col++) {
        
        Serial.print("ascii_val[");
        Serial.print(row);
        Serial.print("][");
        Serial.print(col);
        Serial.print("] = ");
        if (row ==0){
          Serial.println(ascii_val[row][col]);
          delay(70);
          }    
        else {
          Serial.println((int)ascii_val[row][col]);
          delay(130);
          }
      }
    Serial.println(); // New line after each row
  
  
    }
    return 0;
}
