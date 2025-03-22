# ESP-NOW Multi-Sender to One Receiver (Modified)

This repository contains modified ESP-NOW communication code using the Consentium NOW library, enabling multiple ESP32 devices to send sensor data to a single receiver.

# Changes & Enhancements
1️⃣ Added Human-Readable Sender Identification
🔹 Instead of using MAC addresses or numbers, each sender now has a unique name (e.g., ESP_Lab, ESP_Home).
🔹 This allows the receiver to print device-friendly names instead of raw MAC addresses or sender numbers.
