

// the setup function runs once when you press reset or power the board

char ascii_val[2][26]={ {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
} ,
                       {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90
}
                       };   //2Darray[row][col]

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
   
}

// the loop function runs over and over again forever
void loop() {
for (int row = 0; row < 27; row++) {
    for (int col = 0; col < 2; col++) {
      if (col%2==0){
        Serial.print(ascii_val[row][col]);
        delay(500);
      }
      else {
        Serial.print((int)ascii_val[row][col]);
        Serial.print('\n');
         delay(500);
      
      } 
    }
  }
}

void popAscii(){
    
}
