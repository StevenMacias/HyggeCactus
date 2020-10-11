
#include <LiquidCrystal.h>
#include <DHT.h>

const int RS = 8;
const int EN = 9;
const int d4 = 4;
const int d5 = 5;
const int d6 = 6;
const int d7 = 7;
const int pin_BL = 10; // arduino pin wired to LCD backlight circuit
LiquidCrystal lcd( RS,  EN,  d4,  d5,  d6,  d7);

#define DHTPIN 13     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

char lcd_buffer[17];
const int AirValue = 815;   //you need to replace this value with Value_1
const int WaterValue = 435;  //you need to replace this value with Value_2
const int WaterValue_a5 = 435;
int soilMoistureValue_a1 = 0;
int soilmoisturepercent_a1=0;
int soilMoistureValue_a2 = 0;
int soilmoisturepercent_a2=0;
int soilMoistureValue_a3 = 0;
int soilmoisturepercent_a3=0;
int soilMoistureValue_a4 = 0;
int soilmoisturepercent_a4=0;
int soilMoistureValue_a5 = 0;
int soilmoisturepercent_a5=0;

float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup() {
  
 Serial.begin(9600); // open serial port, set the baud rate to 9600 bps 

  lcd.begin(16, 2);
  dht.begin();
  
}

void loop() {
  soilMoistureValue_a1 = analogRead(A1);  //put Sensor insert into soil
  soilMoistureValue_a2 = analogRead(A2);
  soilMoistureValue_a3 = analogRead(A3);
  soilMoistureValue_a4 = analogRead(A4);
  soilMoistureValue_a5 = analogRead(A5);
  
  soilmoisturepercent_a1 = map(soilMoistureValue_a1, AirValue, WaterValue, 0, 100);
  soilmoisturepercent_a2 = map(soilMoistureValue_a2, AirValue, WaterValue, 0, 100);
  soilmoisturepercent_a3 = map(soilMoistureValue_a3, AirValue, WaterValue, 0, 100);
  soilmoisturepercent_a4 = map(soilMoistureValue_a4, AirValue, WaterValue, 0, 100);
  soilmoisturepercent_a5 = map(soilMoistureValue_a5, AirValue, WaterValue_a5, 0, 100);

  hum = dht.readHumidity();
  temp= dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(soilmoisturepercent_a1);
  lcd.print("-");
  lcd.print(soilmoisturepercent_a2);
  lcd.print("-");
  lcd.print(soilmoisturepercent_a3);
  lcd.print("-");
  lcd.print(soilmoisturepercent_a4);
  lcd.print("-");
  lcd.print(soilmoisturepercent_a5);
  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print(" ");
  lcd.print("H:");
  lcd.print(hum);
  delay(1000);
  Serial.println(soilMoistureValue_a5);
 
}
