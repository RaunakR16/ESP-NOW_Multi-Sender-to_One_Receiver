# ESP-NOW Multi-Sender to One Receiver (Modified)

This repository contains **modified ESP-NOW communication code** using the **Consentium NOW library**, enabling multiple ESP32 devices to send sensor data to a single receiver.

## 🚀 Changes & Enhancements

### 🔹 1️⃣ Added Human-Readable Sender Identification
- Instead of using **MAC addresses or numbers**, each sender now has a **unique name** (e.g., `ESP_Lab`, `ESP_Home`).
- The receiver now prints **device-friendly names** instead of raw MAC addresses or sender numbers.

### 🔹 2️⃣ Updated `SensorData` Structure
- Previously, `SensorData` only contained **temperature** and **humidity**.
- Now, it also includes a `name` field to identify the sender.

#### **Before (Original Data Structure)**
```cpp
struct SensorData {
    float temperature;
    float humidity;
};
