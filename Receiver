#include <ConsentiumNow.h>
#include <WiFi.h>
#include <esp_wifi.h>

// Define the data structure
struct SensorData 
{
    char name[100]; // give a name to the ESP Board
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
