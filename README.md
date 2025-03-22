# ESP-NOW Multi-Sender to One Receiver (Modified)

This repository contains **modified ESP-NOW communication code** using the **Consentium NOW library**, enabling multiple ESP32 devices to send sensor data to a single receiver.

## 🚀 Changes & Enhancements

### 🔹 1️⃣ Added Human-Readable Sender Identification
- Instead of using **MAC addresses or numbers**, each sender now has a **unique name**.
- The receiver now prints **device-friendly names** instead of raw MAC addresses or sender numbers.

### 🔹 2️⃣ Added getMacAddress() Function in Receiver Code
 - A new function, 'getMacAddress()', has been added to retrieve and print the ESP32 MAC address.
 - This helps in getting the MAC address of the receiver.


### **The Modified Sender Code**
 - Modify the struct to add the name of the ESP Board.
 - This helps in getting the MAC address of the receiver.
```cpp
#include <ConsentiumNow.h>

// Define the data structure
struct SensorData 
{
    char name[100]; //Sending the name of the ESP
    float temperature;
    float humidity;
};

// Create an instance of ConsentiumNow for the custom structure
ConsentiumNow<SensorData> consentiumSender;

// Replace with the receiver's MAC address (Sending to this address)
uint8_t receiverMac[] = {0xA0, 0xB7, 0x65, 0x26, 0x88, 0xD0}; 

void setup() 
{
    Serial.begin(115200);
    consentiumSender.sendBegin(receiverMac);
    Serial.println("Sender initialized.");
}

void loop() {
    SensorData data;

    strcpy(data.name, "ESP_Test1");  // Give a name to the ESP Board
    data.temperature = random(200, 300) / 10.0; // Random temperature (20.0 - 30.0°C)
    data.humidity = random(400, 600) / 10.0;    // Random humidity (40.0 - 60.0%)

    consentiumSender.sendData(data);

    Serial.printf("Sending Data from : %s\n", data.name);
    Serial.printf("Sent Data - Temperature: %.2f, Humidity: %.2f\n", 
                  data.temperature, data.humidity);
    delay(2000);
} 
