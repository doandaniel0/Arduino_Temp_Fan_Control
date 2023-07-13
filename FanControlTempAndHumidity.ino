#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2       // Pin connected to the DHT22 sensor
#define DHTTYPE DHT22  // DHT sensor type

#define FAN_PIN 3      // Pin connected to the fan's pwm pin

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(FAN_PIN, OUTPUT); //Setting fan pin as an output
  analogWrite(FAN_PIN, 0); // Turn fan off initially

  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Delay for 2 seconds between readings

  float temp = dht.readTemperature(true); // true returns temp in farenheit
  float humidity = dht.readHumidity();

  if(!isnan(temp) && !isnan(humidity)){   // checking if readings are valid
    Serial.print("Temperature: "); //Printing temp to serial monitor
    Serial.print(temp);
    Serial.println(" °F");

    Serial.print("Humidity: "); //Printing humidity to serial monitor
    Serial.print(humidity);
    Serial.println("%");

  }

  // Controlling fan based on specific temperature
  if(temp>81){                // Set temperature here
    analogWrite(FAN_PIN,175); // Controlling fan with PWM, you can change this number here to change fan speed (255 for max)
    Serial.println("Fan on");
  }else{
    analogWrite(FAN_PIN,0);// Setting pwm to 0 to turn fan off
    Serial.println("Fan off"); 

  }

}
