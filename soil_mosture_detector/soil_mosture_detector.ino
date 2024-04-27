#include <DHT.h>

#define DHTPIN A5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int soilMoisturePin = A0;
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read soil moisture sensor
  soilMoistureValue = analogRead(soilMoisturePin);

  // Read temperature and humidity from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print soil moisture, temperature, and humidity values
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Delay for 2 seconds
}
