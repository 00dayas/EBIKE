#include<Wire.h>

int t1,t2,ss,hl,mr,ind,range;
String trial;
char* Data[7];
// order of data
//| Temperature 1 | Temperature 2 | Smoke Status | Head Lamp | Motor RPM | Indicators | Range |
void sendData(){
  measureT1();
  measureT2();
  measureSS();
  measureHLS();
  measureRPM();
  measureIS();
  measureRange();
}


void measureT1(){
  t1 = 1;
  Wire.write("22");
} // Data[0]
void measureT2(){
  t2 = 2;
  Wire.write("23");
}// Data[1]
void measureSS(){
  ss =  3;
  Wire.write("24");
}// Data[2]
void measureHLS(){
  hl = 4;
  Wire.write("25");
}// Data[3]
void measureRPM(){
  mr = "K";
  trial = "2";
  // const char* j = "k";

  int jj = analogRead(A0);
  // Serial.println(jj);
  String kk = String(jj);
  Serial.println(kk.length());
  // kk.length();
  if(kk.length()==3){
    kk = "0"+kk;
  }
  Serial.println(kk);


  int k = 95;
  int j = 32;
  // for(int i=0;i<mr.length();i++){
  //   Wire.write(mr.charAt(i));
  // }
  Wire.write(kk.c_str());
  // Wire.write(j);
  // Wire.write(mr);
}// Data[4]
void measureIS(){
  ind = 6;
  Wire.write("26");
}// Data[5]
void measureRange(){
  range = 7;
  Wire.write("27");
}// Data[6]

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(sendData);
  pinMode(A0,INPUT);
}

void loop() {
  
  // int jj = analogRead(A0);
  // // Serial.println(jj);
  // String kk = String(jj);
  // Serial.println(kk.length());
  // // kk.length();
  // if(kk.length()==3){
  //   kk = "0"+kk;
  // }
  // Serial.println(kk);
}
