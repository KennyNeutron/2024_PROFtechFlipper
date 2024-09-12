void display_PROscore() {
  u8g2.setFontPosTop();
  u8g2.setFont(u8g2_font_profont12_mr);

  char ch_GT[15] = "";
  sprintf(ch_GT, "GT: %02d:%02d.%1d", GameTime_Minute, GameTime_Second, GameTime_Millis);
  u8g2.drawStr(0, 0, ch_GT);

  char ch_SC[10] = "";
  sprintf(ch_SC, "SC: %02d.%1d", ShotClock_Second, ShotClock_Millis);
  u8g2.drawStr(0, 13, ch_SC);

  char ch_HS[8] = "";
  sprintf(ch_HS, "HS: %d", HomeScore);
  u8g2.drawStr(0, 26, ch_HS);

  char ch_HF[8] = "";
  sprintf(ch_HF, "HF: %d", HomeFoul);
  u8g2.drawStr(0, 39, ch_HF);

  char ch_HTO[8] = "";
  sprintf(ch_HTO, "HT: %d", HomeTOut);
  u8g2.drawStr(0, 52, ch_HTO);

  char ch_GS[8] = "";
  sprintf(ch_GS, "GS: %d", GuestScore);
  u8g2.drawStr(45, 26, ch_GS);

  char ch_GF[8] = "";
  sprintf(ch_GF, "GF: %d", GuestFoul);
  u8g2.drawStr(45, 39, ch_GF);

  char ch_GTO[8] = "";
  sprintf(ch_GTO, "GT: %d", GuestTOut);
  u8g2.drawStr(45, 52, ch_GTO);

  char ch_BP[8] = "";
  sprintf(ch_BP, "BP: %d", BallPoss);
  u8g2.drawStr(90, 26, ch_BP);

  char ch_QT[8] = "";
  sprintf(ch_QT, "QT: %d", period);
  u8g2.drawStr(90, 39, ch_QT);

  if (RF_Avail) {
    u8g2.drawStr(95, 0, "<<|>>");
  }
}

void display_PROscore_TeamName() {
  u8g2.setFontPosTop();
  u8g2.setFont(u8g2_font_profont12_mr);


  u8g2.drawStr(0, 0, "Team Name Setup");
  u8g2.drawStr(0, 26, payload.CurrentTeamName);
}