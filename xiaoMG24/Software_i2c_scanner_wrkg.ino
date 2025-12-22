// Software I2C Scanner for Seeed Studio XIAO MG24
// This sketch implements I2C using bit-banging (software I2C)
// You can use ANY GPIO pins for SDA and SCL

// Define your custom I2C pins here
#define SOFT_SDA_PIN D4  // Change to any GPIO pin
#define SOFT_SCL_PIN D5  // Change to any GPIO pin

// I2C timing delays (microseconds)
#define I2C_DELAY 5      // Standard mode ~100kHz

// Function declarations
void i2c_init();
void i2c_start();
void i2c_stop();
bool i2c_write_byte(uint8_t byte);
uint8_t i2c_read_byte(bool ack);
void sda_high();
void sda_low();
void scl_high();
void scl_low();
bool read_sda();
void i2c_delay();

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }
  
  Serial.println("\n===============================");
  Serial.println("Software I2C Scanner for XIAO MG24");
  Serial.println("===============================\n");
  
  // Initialize software I2C
  i2c_init();
  
  Serial.print("Software I2C pins:\n");
  Serial.print("SDA: D");
  Serial.println(SOFT_SDA_PIN);
  Serial.print("SCL: D");
  Serial.println(SOFT_SCL_PIN);
  Serial.println("\nScanning...\n");
}

void loop() {
  int nDevices = 0;

  Serial.println("Starting I2C scan...");

  // Scan all possible I2C addresses (1-127)
  for(uint8_t address = 1; address < 127; address++) {
    // Try to communicate with device at this address
    i2c_start();
    
    // Send address with write bit (bit 0 = 0)
    bool ack = i2c_write_byte((address << 1) | 0);
    
    i2c_stop();
    
    if (ack) {
      // Device acknowledged - found!
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }
    
    delay(1); // Small delay between attempts
  }

  // Display results
  if (nDevices == 0) {
    Serial.println("\nNo I2C devices found");
    Serial.println("Troubleshooting tips:");
    Serial.print("  - Verify SDA is connected to D");
    Serial.println(SOFT_SDA_PIN);
    Serial.print("  - Verify SCL is connected to D");
    Serial.println(SOFT_SCL_PIN);
    Serial.println("  - Ensure pull-up resistors are present (2.2k-10k)");
    Serial.println("  - Check power supply to I2C devices");
    Serial.println("  - Try different pins if current ones don't work");
  }
  else {
    Serial.print("\nScan complete. Found ");
    Serial.print(nDevices);
    Serial.println(" device(s).\n");
  }

  // Wait 5 seconds before next scan
  delay(5000);
}

// ============================================
// Software I2C Implementation Functions
// ============================================

void i2c_init() {
  // Set both pins as inputs with pull-ups (open-drain simulation)
  pinMode(SOFT_SDA_PIN, INPUT_PULLUP);
  pinMode(SOFT_SCL_PIN, INPUT_PULLUP);
  delay(10);
}

void i2c_start() {
  // Start condition: SDA goes LOW while SCL is HIGH
  sda_high();
  scl_high();
  i2c_delay();
  sda_low();
  i2c_delay();
  scl_low();
  i2c_delay();
}

void i2c_stop() {
  // Stop condition: SDA goes HIGH while SCL is HIGH
  sda_low();
  i2c_delay();
  scl_high();
  i2c_delay();
  sda_high();
  i2c_delay();
}

bool i2c_write_byte(uint8_t byte) {
  // Send 8 bits, MSB first
  for (uint8_t i = 0; i < 8; i++) {
    if (byte & 0x80) {
      sda_high();
    } else {
      sda_low();
    }
    i2c_delay();
    
    scl_high();
    i2c_delay();
    scl_low();
    i2c_delay();
    
    byte <<= 1;
  }
  
  // Read ACK bit
  sda_high();  // Release SDA for slave to pull low
  i2c_delay();
  scl_high();
  i2c_delay();
  
  bool ack = !read_sda();  // ACK is active LOW
  
  scl_low();
  i2c_delay();
  
  return ack;
}

uint8_t i2c_read_byte(bool ack) {
  uint8_t byte = 0;
  
  sda_high();  // Release SDA line for slave to drive
  
  // Read 8 bits, MSB first
  for (uint8_t i = 0; i < 8; i++) {
    i2c_delay();
    scl_high();
    i2c_delay();
    
    byte <<= 1;
    if (read_sda()) {
      byte |= 1;
    }
    
    scl_low();
  }
  
  // Send ACK/NACK bit
  if (ack) {
    sda_low();  // ACK
  } else {
    sda_high(); // NACK
  }
  i2c_delay();
  
  scl_high();
  i2c_delay();
  scl_low();
  i2c_delay();
  
  sda_high();  // Release SDA
  
  return byte;
}

// Low-level pin control functions (open-drain simulation)
void sda_high() {
  pinMode(SOFT_SDA_PIN, INPUT_PULLUP);  // Release line (pulled high by resistor)
}

void sda_low() {
  pinMode(SOFT_SDA_PIN, OUTPUT);
  digitalWrite(SOFT_SDA_PIN, LOW);      // Pull line low
}

void scl_high() {
  pinMode(SOFT_SCL_PIN, INPUT_PULLUP);  // Release line (pulled high by resistor)
  // Clock stretching: wait for slave to release SCL
  uint16_t timeout = 1000;
  while (digitalRead(SOFT_SCL_PIN) == LOW && timeout > 0) {
    delayMicroseconds(1);
    timeout--;
  }
}

void scl_low() {
  pinMode(SOFT_SCL_PIN, OUTPUT);
  digitalWrite(SOFT_SCL_PIN, LOW);      // Pull line low
}

bool read_sda() {
  return digitalRead(SOFT_SDA_PIN);
}

void i2c_delay() {
  delayMicroseconds(I2C_DELAY);
}