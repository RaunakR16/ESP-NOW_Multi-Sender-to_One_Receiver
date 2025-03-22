# ESP-NOW Multi-Sender to One Receiver (Modified)

This repository contains **modified ESP-NOW communication code** using the **Consentium NOW library**, enabling multiple ESP32 devices to send sensor data to a single receiver.

## 🚀 Changes & Enhancements

### 🔹 1️⃣ Added Human-Readable Sender Identification
- Instead of using **MAC addresses or numbers**, each sender now has a **unique name**.
- The receiver now prints **device-friendly names** instead of raw MAC addresses or sender numbers.

### 🔹 2️⃣ Added getMacAddress() Function in Receiver Code
 - A new function, `getMacAddress()`, has been added to retrieve and print the ESP32 MAC address.
 - This helps in getting the MAC address of the receiver.


### **1. The Modified Sender Code**
 - Modify the `struct` to add the `name` of the ESP Board.

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
```

### **2. The Modified Receiver Code**
 - Modify the `struct` to get the `name` of the ESP Board.
 -  Added two header files `WiFi.h` and `esp_wifi.h` to get the MAC Address.
 - `getMacAddress()`, has been added to retrieve and print the ESP32 MAC address, which helps get the MAC address of the receiver.
 

```cpp
#include <ConsentiumNow.h>
#include <WiFi.h>
#include <esp_wifi.h>

// Define the data structure
struct SensorData 
{
    char name[100]; // Give a name to the ESP Board
    float temperature;
    float humidity;
};

// Create an instance of ConsentiumNow for receiving data
ConsentiumNow<SensorData> consentiumReceiver;

void readMacAddress() {
    uint8_t baseMac[6];
    esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
    if (ret == ESP_OK) {
        Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                      baseMac[0], baseMac[1], baseMac[2],
                      baseMac[3], baseMac[4], baseMac[5]);
    } else {
        Serial.println("Failed to read MAC address");
    }
}

void setup() 
{
    Serial.begin(115200);
    consentiumReceiver.receiveBegin();
    //Add the MAC addresses of each sender
    uint8_t sender1Mac[] = {0xA0, 0xB7, 0x65, 0x25, 0x98, 0x5C}; 
    uint8_t sender2Mac[] = {0xA0, 0xB7, 0x65, 0x26, 0x36, 0x60}; 
    uint8_t sender3Mac[] = {0xC8, 0X2E, 0x18, 0xF7, 0x5F, 0xE0}; 
    consentiumReceiver.addPeer(sender1Mac);
    consentiumReceiver.addPeer(sender2Mac);
    consentiumReceiver.addPeer(sender3Mac);
    Serial.println("Ready to receive data from multiple senders.");
    
    WiFi.mode(WIFI_STA);
    WiFi.begin();
    Serial.print("ESP32 Board MAC Address: ");
    readMacAddress();
}

void loop() 
{
    if (consentiumReceiver.isDataAvailable()) 
    {
        SensorData data = consentiumReceiver.getReceivedData();
        Serial.printf("Getting Data from : %s\n", data.name);
        Serial.printf("Received Data - Temperature: %.2f, Humidity: %.2f\n", 
                      data.temperature, data.humidity);
    }
    delay(500);
}
