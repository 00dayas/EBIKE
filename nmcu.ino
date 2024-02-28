#include<Wire.h>
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
String mg[7],rec[7];
int i =0;
String msg = "", rpm ="2300",beam_status="Hi";
String status = "OK!", battery ="56",beam="Hi";
String speed="32",temperature = "25",range="69";
int a =0;
const char* ssid ="AP-Node";
const char* password = "1234567890";

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

String html(){
  String k = String(a);
  String ptr = "<!DOCTYPE html>\n";
  ptr += "<html><head>\n";
  ptr +=" <meta http-equiv=\"refresh\" content=\"0\">\n";
  ptr += "<style>\n";
  ptr += "body { font-family: 'Courier New', monospace;\n";
  ptr += "color: rgb(0,155,155);font-size: ;}\n";
  ptr += "h1{font-size: 3em;}\n";
  ptr += "div{border: solid;}\n";
  ptr += ".flex-container{display: flex;flex-wrap: wrap;border: none;}\n";
  ptr += ".flex-container> .line1a1{width: 34%;height: 8em;\n";
  ptr += "margin: 10px;line-height: auto;}\n";
  ptr += ".flex-container > .line1a2{width: 19%;height: 8em;\n";
  ptr += "margin: 5px;line-height: auto;}\n";
  ptr += ".flex-container > .line2a1{width: 60%;height: 8em;\n";
  ptr += "margin: 5px;line-height: auto;}\n";
  ptr += ".flex-container >  .line2a2{width: 30%;height: 8em;\n";
  ptr += "margin: 5px;line-height: auto;}\n";
  ptr += ".flex-container> .line3a1{width: 40%;height: 8em;\n";
  ptr += "margin: 5px;line-height: auto;}\n";
  ptr += ".flex-container> .line3a2{width: 15%;height: 8em;\n";
  ptr += "margin: 5px;line-height: auto;}\n";
  ptr += "</style></head><body>\n";
	ptr += "<div class=\"flex-container\"><div class=\"line1a1\"><h3>RPM: </h3>\n";
  // RPM
  ptr += "<h1>"; ptr+= rpm; ptr+= "</h1>\n"; 
  ptr += "</div><div class=\"line1a1\"><h3>Health: </h3>\n";
  // Status
  ptr += "<h1>"; ptr += status; ptr += "</h1>\n"; 
  ptr += "</div><div class=\"line1a2\"><h3>Battery: </h3>\n";
  // Battery
  ptr += "<h1>"; ptr += battery; ptr+= "%</h1>\n"; 
  ptr += "</div></div><div class=\"flex-container\"><div class=\"line2a1\">\n";
  ptr += "<h3>Speed (Km/hr)</h3>\n";
  // Speed
  ptr += "<h1>\n"; ptr += speed; ptr += "</h1>\n"; 
  ptr += "</div><div class=\"line2a2\"><h3>Temperature: </h3>\n";
  // Temperature
  ptr += "<h1>"; ptr += temperature; ptr+= "°C</h1>\n";
  ptr += "</div></div><div class=\"flex-container\"><div class=\"line3a1\">\n";
  ptr += "<h3>Range: </h3>\n";
  // Range
  ptr +="<h1>";ptr+= range; ptr+= "Km </h1>\n";
  ptr +="</div><div class=\"line3a2\"><h4>Beam:</h4>\n";
  // Beam
  ptr +="<h1>";ptr+=beam;"</h1>\n"; 
  ptr += "</div><div class=\"line3a2\"><h4>Turn:</h4>\n";
  
  ptr += "<h1>";ptr+=beam_status;ptr+="</h1>\n";
  ptr += "</div><div class=\"line3a2\"><h4>Temp:</h4>\n";
  // Temp2 
  ptr += "<h1>"; ptr += temperature; ptr+= "°C</h1>\n";
  ptr += "</body></html>\n";
  return ptr;
}
ESP8266WebServer server(80);
void onConnect(){
  server.send(200,"text/html",html());
}
void showConsole(){}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(D1,D2);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  server.on("/",onConnect);
  server.on("/console",showConsole);
  server.begin();
  Serial.println("HTTP server started");

}

void loop() {
  // put your main code here, to run repeatedly:
  String recieve;
  server.handleClient();
  
  Wire.requestFrom(8,16);
  while(Wire.available()){
    recieve += (char)Wire.read();
  }
  i =0;
  msg = recieve;
  // mrec;
  // 2 4 8 2 5 5 2 5 5 2 5  5
  // // 0 1 2 3 4 5 6 7 8 9 10 11
  Serial.print("RECIEVED: ");Serial.println(msg); 
  recieve="";
  // Serial.println(msg);
  // rpm =msg[0];
  // beam_status=msg[1];
  // status = msg[2];
  // battery =msg[3];
  // beam=msg[4];
  // speed=msg[5];
  // temperature = msg[6];
  // range=msg[7];
  // for(i=0;i<7;i++){
  //   Serial.print("Data: ");Serial.println(rec[i]);
  // }
  
} 
