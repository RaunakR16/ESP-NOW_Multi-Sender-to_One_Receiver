# ESP-NOW Multi-Sender to One Receiver (Modified)

This repository contains **modified ESP-NOW communication code** using the **Consentium NOW library**, enabling multiple ESP32 devices to send sensor data to a single receiver.

## 🚀 Changes & Enhancements

### 🔹 1️⃣ Added Human-Readable Sender Identification
- Instead of using **MAC addresses or numbers**, each sender now has a **unique name**.
- The receiver now prints **device-friendly names** instead of raw MAC addresses or sender numbers.

### 🔹 2️⃣ Added getMacAddress() Function in Receiver Code
🔹 A new function, getMacAddress(), has been added to retrieve and print the ESP32 MAC address.
🔹 This helps in getting the MAC address of the receiver.


#### **Before (Original Data Structure)**
```cpp
struct SensorData {
    float temperature;
    float humidity;
};
