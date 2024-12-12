// Define a struct to hold an int and a char
struct Data {
    int intValue;
    char charValue;
};

// Declare a 2D array of the struct
Data array[2][2];

void setup() {
    Serial.begin(9600);

    // Assign values
    array[0][0] = {42, 'A'};
    array[0][1] = {27, 'B'};
    array[1][0] = {33, 'C'};
    array[1][1] = {99, 'D'};

    // Print values
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            Serial.print("array[");
            Serial.print(i);
            Serial.print("][");
            Serial.print(j);
            Serial.print("]: int = ");
            Serial.print(array[i][j].intValue);
            Serial.print(", char = ");
            Serial.println(array[i][j].charValue);
        }
    }
}

void loop() {
    // Nothing to do in loop
}