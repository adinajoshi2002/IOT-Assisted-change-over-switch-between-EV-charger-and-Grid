


#include "ESP8266WiFi.h"                                         
#include <FirebaseESP8266.h>
#include <WiFiUdp.h>
#define FIREBASE_HOST  "https://home-automation-cb3f4-default-rtdb.firebaseio.com"  
#define FIREBASE_AUTH  "HA1OqOYbBDRAxmPUyZnVm6iVoko4mGyLwGzrCD5j"  
#define WIFI_SSID "H"//wifi ssid
#define WIFI_PASSWORD "12345678"//your wifi password
#define a0 D0
#define a1 D1
#define ir1 D2
#define ir2 D3
String  cont1;


FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
pinMode(a0, OUTPUT);     
pinMode(a1, OUTPUT);

pinMode(ir1, OUTPUT);
pinMode(ir2, OUTPUT);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);


}
void loop() {
    Firebase.getString(ledData, "/FirebaseIOT/Cont");
    


  digitalRead(ir1);
  
  digitalRead(ir2);
    cont1 = ledData.stringData();
    Serial.print(cont1);
  if(cont1=="1")
  {
   if(ir1 ==0)
 {
  digitalWrite(a0,HIGH);
  digitalWrite(a1,LOW);
 }else{
  digitalWrite(a0,LOW);
  digitalWrite(a1,LOW);
  String t =  "reached to 32A side";
  Firebase.setString(firebaseData, "/FirebaseIOT/name", t);
   
  
 }

 
  }
  if( cont1=="2")
  {
     if(ir2==0)
 {
  digitalWrite(a0,LOW);
  digitalWrite(a1,HIGH);
 }else{
  digitalWrite(a0,LOW);
  digitalWrite(a1,LOW);
    String t =  "reached to 12A side";
  Firebase.setString(firebaseData, "/FirebaseIOT/name", t);
 }
     
    }


}
