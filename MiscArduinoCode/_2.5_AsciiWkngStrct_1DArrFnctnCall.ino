// Define a struct to hold an int and a char
struct Data {
    int intAsciiVal;
    char charVal;
};

// Declare a 2D array of the struct
Data StructArray[26];  // 26 rows and 2 columns

 

void setup() {
  Serial.begin(9600);
  load_ascii('A', 65); //load the struct with A-Z
  //load_ascii('a', 40); over writes the value
 
}

void loop() {
  
   display_val();
}

void display_val(){
    for (int i = 0; i < 26; i++) {
 
      Serial.print(StructArray[i].charVal);
      Serial.print('\t');
      Serial.println(StructArray[i].intAsciiVal);
      delay(250);  
    }
    Serial.println(' ');
}

void load_ascii(char alphbt, int ascii) {
  for (int row = 0; row < 26; row++) {
    StructArray[row].intAsciiVal = row + ascii;   // Correct ASCII value
    StructArray[row].charVal= row + alphbt;    // Correct character increment
  }
}

