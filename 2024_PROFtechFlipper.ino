/*
  PROFtech Flipper V2024.7.4
  Env: ESP32 Dev Module
  Date: Jul 4, 2024
*/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <U8g2lib.h>
#include "variables.h"
#include "PTWDBS_DataStructure.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);


RF24 NRF(4, 5);  // CE, CSN
const byte address[6] = "ZK001";

char SerialData[17] = " ";

bool RF_Avail = false;

void setup() {
  Serial.begin(115200);
  u8g2.begin();

  if (!NRF.begin()) {
    Serial.println("NRF24L01 is Broken or Hardware Not Installed");
  } else {
    Serial.println("NRF24L01 detected!");
  }

  NRF.setPALevel(RF24_PA_MAX);
  NRF.setDataRate(RF24_250KBPS);

  NRF.openReadingPipe(0, address);
  NRF.startListening();
}

void loop() {
  if (NRF.available()) {
    NRF.read(&payload, sizeof(Payload_Data));  // Read the whole data and store it into the 'data' structure
    TeamNameSetupMode = payload.TeamNameSetupMode;

    if (!TeamNameSetupMode) {
      HomeScore = payload.HomeScore;
      GuestScore = payload.GuestScore;

      HomeFoul = payload.HomeFoul;
      GuestFoul = payload.GuestFoul;

      HomeTOut = payload.HomeTOut;
      GuestTOut = payload.GuestTOut;

      GameTime_Minute = payload.GameTime_Minute;
      GameTime_Second = payload.GameTime_Second;
      GameTime_Millis = payload.GameTime_Millis;

      ShotClock_Second = payload.ShotClock_Second;
      ShotClock_Millis = payload.ShotClock_Millis;

      BallPoss = payload.BallPoss;

      period = payload.period;
      GT_SC_sync = payload.GT_SC_sync;

      SetupMode = payload.SetupMode;
      DataToSet = payload.DataToSet;

      TeamNameSetupMode = payload.TeamNameSetupMode;

      EndOfGame = payload.EndOfGame;
    } else {
      TeamNameSetupMode = payload.TeamNameSetupMode;
      SerialData[0] = 'a';
      SerialData[1] = 'b';
      for (int i = 2; i <= 11; i++) {
        SerialData[i] = payload.CurrentTeamName[i - 2];
      }
      SerialData[12] = payload.TeamNameSetupMode + 48;
      SerialData[13] = payload.TN_ID + 48;
      SerialData[14] = 'c';
      Serial.print(SerialData);
      //for (int a = 0; a < 16; a++) {Serial.print("SD["); Serial.print(a); Serial.print("]:"); Serial.println(SerialData[a],HEX);}
    }
    RF_Avail = true;
  } else {
    RF_Avail = false;
  }

  u8g2.clearBuffer();  // clear the internal memory
  if (!TeamNameSetupMode) {
    display_PROscore();
  } else {
    display_PROscore_TeamName();
  }

  u8g2.sendBuffer();  // transfer internal memory to the display
}
