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

