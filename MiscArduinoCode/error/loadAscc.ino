// Define a 2D array with ASCII values
//global variable
char ascii_val[26][2];//empty array with 26 row and 2 col

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  Serial.print("Begining operation..........");
  load_ascii();
}

void loop() {
  
  display_ascii();
  
}
void load_ascii()
  ascii_val[0][0]= 'A'; 
  ascii_val[0][1]= 65;
  for (int row = 0; row < 25; row++) {
    ascii_val[row+1][0]=ascii_val[row][0]+1;
    ascii_val[row+1][1]=ascii_val[row][1]+1;
    
  }
}
    

        
 
void display_ascii(){
  
    
    for (int col = 0; col < 2; col++) {
      for (int row = 0; row < 26; row++) {
        
        Serial.print("ascii_val[");
        Serial.print(row);
        Serial.print("][");
        Serial.print(col);
        Serial.print("] = ");
        
        Serial.println(ascii_val[row][col]);
        delay(70);
        }    
    
    Serial.println(); // New line after each row
  
  
    }
    return 0;
}
