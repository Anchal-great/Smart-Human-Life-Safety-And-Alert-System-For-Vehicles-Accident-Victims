#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#include <SoftwareSerial.h>
SoftwareSerial sim800(2,3); 
SoftwareSerial GPS_SoftSerial(5, 4);
TinyGPSPlus gps;
volatile float minutes, seconds;
volatile int degree, secs, mins;
double latitude,longitude;
int impact_sensor = 8;
int impact_val = 1;
int buzzer = 10;
int push_btn = 7;
int push_val=1;
void setup() {
 Serial.begin(9600);
 lcd.init();
 lcd.backlight();
 sim800.begin(115200);
 delay(1000); 
 GPS_SoftSerial.begin(9600);
 pinMode(impact_sensor,INPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(push_btn,INPUT_PULLUP);
}
void loop() {
 lcd.setCursor(0, 0);
 lcd.print("System Started");
impact_val = digitalRead(impact_sensor);
if(impact_val == 0){
 digitalWrite(buzzer,HIGH);
Serial.println("impact");
 lcd.clear();
 lcd.print("Accident");
 lcd.setCursor(0, 1);
lcd.print("detected!!");
 delay(5000);
 lcd.clear();
 lcd.print("Are you safe??");
 delay(5000);
 lcd.clear();
 lcd.print("hold the button!!");
 digitalWrite(buzzer,LOW);
for(int i=0;i<2000;i++){
push_val = digitalRead(push_btn);
Serial.println(push_val);
}
if(push_val == 0){
 lcd.clear();
 lcd.print("You are safe!!");
 delay(5000);
 lcd.clear();
}else{
 lcd.clear();
 lcd.print("Unconsious");
 lcd.setCursor(0, 1);
 lcd.print("Victim Detected!!");
 delay(5000);
 lcd.clear();
 lcd.print("call and send");
 lcd.setCursor(0, 1);
 lcd.print("msg for help");
 delay(5000);
 location_func();
 callandmsg();
}
}
}
void makeCall(String phoneNumber) {
    Serial.println("Making a call...");
 lcd.clear();
 lcd.print("Making a call...");
sim800.println("ATD"+phoneNumber+";"); 
 delay(1000); 
 lcd.clear();
 lcd.print("Calling...");
 delay(30000);
sim800.println("ATH"); 
 delay(1000); 
 Serial.println("Call ended.");
 lcd.clear();
 lcd.print("Informed about");
 lcd.setCursor(0, 1);
 lcd.print("Accident");
 delay(5000);
}
void sendSMS(String message, String phoneNumber) {
 Serial.println("Sending SMS...");
 lcd.clear();
 lcd.print("Sending SMS...");
 sim800.println("AT+CMGF=1");
 delay(1000); 
 sim800.println("AT+CMGS=\"" + phoneNumber + "\"");
 delay(1000); 
 sim800.println(message);
 delay(1000); 
 sim800.write(26); 
 delay(1000); 
 Serial.println("Message sent!");
 lcd.clear();
 lcd.print("Message sent!");
 delay(5000);
}
void callandmsg(){
 String link = "https://www.google.com/maps?q="+ 
String(latitude,6)+","+String(longitude,6);
sendSMS(link,"+919039752050");
makeCall("+919039752050"); 
lcd.clear();
}
void DegMinSec( double tot_val)
{ 
degree = (int)tot_val;
 minutes = tot_val - degree;
 seconds = 60 * minutes;
 minutes = (int)seconds;
 mins = (int)minutes;
 seconds = seconds - minutes;
 seconds = 60 * seconds;
secs = (int)seconds;
}
static void smartDelay(unsigned long ms)
{
 unsigned long start = millis();
 do 
 {
 while (GPS_SoftSerial.available())
 gps.encode(GPS_SoftSerial.read());
 } while (millis() - start < ms);
}
void location_func(){
 smartDelay(1000);
 unsigned long start;
 double lat_val, lng_val;
 bool loc_valid;
 lat_val = gps.location.lat();
 loc_valid = gps.location.isValid();
 lng_val = gps.location.lng();
 if (!loc_valid)
 { 
 Serial.print("Latitude : ");
 Serial.println("*****");
 Serial.print("Longitude : ");
 Serial.println("*****");
 }
 else
 {
 DegMinSec(lat_val);
 Serial.print("Latitude in Decimal Degrees : ");
 Serial.println(lat_val, 6);
latitude = lat_val;
 DegMinSec(lng_val);
 Serial.print("Longitude in Decimal Degrees : "); 
 Serial.println(lng_val, 6);
 longitude = lng_val;
}
}