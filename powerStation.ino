#include "Arduino.h"

int koth_cct_2=2;
int koth_cct_1=3;
int koth_unit_1=4;
int koth_unit_2=5;
int koth_unit_3=6;
int lak_unit_3=7;
int lak_unit_1=8;
int lax_unit_1=9;
int lax_unit_2=10;
int pol_unit_1=11;
int pol_unit_2=12;
int athu_thul=13;
int athu_thul_n=14;
int koth_anu=15;
int samanala_1=16;
int samanala_2=17;
int up_koth_1=18;
int up_koth_2=19;
int kol_kos=20;
int kol_seetha=21;
int stage_1=22;
int stage_2=23;
int stage_3=24;
int stage_4=25;
int stage_5=26;
int tot_black_out=27;


void setup() {
  Serial.begin(9600);
  setArduinoPinModes();
}

void loop() {
   if (Serial.available()) {
    String receivedString = Serial.readStringUntil('\n');
    Serial.println("Received: " + receivedString);
    controllingStations(receivedString);
   }
}

// This function sets the arduino pin modes
void setArduinoPinModes(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

// This function return the integer which is extracted from the String
int extractNumber(String str) {
  String numStr = "";
  int len = str.length();
  for (int i = 0; i < len; i++) {
    char c = str.charAt(i);
    if (isdigit(c)) {
      numStr += c;
    } else {
      break;
    }
  }
    int num = numStr.toInt();
    return num;
}

// This function set the powerStation to LOW if the state is 0, if the state is 1 then otherwise
void powerOnOffStation(int powerStation, int state){
    if(state==0){
        digitalWrite(powerStation, LOW);
    }else{
        digitalWrite(powerStation, HIGH);
    }
}

// This function shuts of all the powerstations
void powerOffAll(int state){
    powerOnOffStation(koth_unit_1, state);
    powerOnOffStation(koth_unit_2, state);
    powerOnOffStation(koth_unit_3, state);
    powerOnOffStation(lak_unit_3, state);
    powerOnOffStation(lak_unit_1, state);
    powerOnOffStation(lax_unit_1, state);
    powerOnOffStation(lax_unit_2, state);
    powerOnOffStation(pol_unit_1, state);
    powerOnOffStation(pol_unit_2, state);
    powerOnOffStation(athu_thul, state);
    powerOnOffStation(athu_thul_n, state);
    powerOnOffStation(koth_anu, state);
    powerOnOffStation(samanala_1, state);
    powerOnOffStation(samanala_2, state);
    powerOnOffStation(up_koth_1, state);
    powerOnOffStation(up_koth_2, state);
    powerOnOffStation(kol_kos, state);
    powerOnOffStation(kol_seetha, state);
    powerOnOffStation(stage_1, state);
    powerOnOffStation(stage_2, state);
    powerOnOffStation(stage_3, state);
    powerOnOffStation(stage_4, state);
    powerOnOffStation(stage_5, state);
}

// This function control all the powerstations accoridng to the input
void controllingStations(String receivedString){

    int extractedNum = extractNumber(receivedString);
    int state = 0;
    if (extractedNum%2==0){
        state = 1;
    }else{
        extractedNum = extractedNum - 1;
    }

  if(extractedNum == 100){
    powerOnOffStation(koth_cct_2, state);
  }else if(extractedNum == 102){
    powerOnOffStation(koth_cct_1, state);
  }else if(extractedNum == 104){
    powerOnOffStation(koth_unit_1, state);
  }else if(extractedNum == 106){
    powerOnOffStation(koth_unit_2, state);
  }else if(extractedNum == 108){
    powerOnOffStation(koth_unit_3, state);
  }else if(extractedNum == 110){
    powerOnOffStation(lak_unit_3, state);
  }else if(extractedNum == 112){
    powerOnOffStation(lak_unit_1, state);
  }else if(extractedNum == 114){
    powerOnOffStation(lax_unit_1, state);
  }else if(extractedNum == 116){
    powerOnOffStation(lax_unit_2, state);
  }else if(extractedNum == 118){
    powerOnOffStation(pol_unit_1, state);
  }else if(extractedNum == 120){
    powerOnOffStation(pol_unit_2, state);
  }else if(extractedNum == 122){
    powerOnOffStation(athu_thul, state);
  }else if(extractedNum == 124){
    powerOnOffStation(athu_thul_n, state);
  }else if(extractedNum == 126){
    powerOnOffStation(koth_anu, state);
  }else if(extractedNum == 128){
    powerOnOffStation(samanala_1, state);
  }else if(extractedNum == 130){
    powerOnOffStation(samanala_2, state);
  }else if(extractedNum == 132){
    powerOnOffStation(up_koth_1, state);
  }else if(extractedNum == 134){
    powerOnOffStation(up_koth_2, state);
  }else if(extractedNum == 136){
    powerOnOffStation(kol_kos, state);
  }else if(extractedNum == 138){
    powerOnOffStation(kol_seetha, state);
  }else if(extractedNum == 140){
    powerOnOffStation(stage_1, state);
  }else if(extractedNum == 142){
    powerOnOffStation(stage_2, state);
  }else if(extractedNum == 144){
    powerOnOffStation(stage_3, state);
  }else if(extractedNum == 146){
    powerOnOffStation(stage_4, state);
  }else if(extractedNum == 148){
    powerOnOffStation(stage_5, state);
  }else if(extractedNum == 150){
    powerOffAll(state);
  }
}