/*
  Main Menu Display
  by: Kenny Neutron
  09-23-2024
*/
String str_menu[]{ "NRF24L01 Tester", "PSWDBS TX", "PSWDBS RX", "HC-05" };

void d_MainMenu() {
  u8g2.setFontPosTop();
  u8g2.setFont(u8g2_font_boutique_bitmap_7x7_t_all);
  u8g2.drawStr(90, 0, "Main Menu");

  u8g2.setFont(u8g2_font_7x13_tf);

  u8g2.drawStr(10, 15, str_menu[0].c_str());
  u8g2.drawStr(10, 33, str_menu[1].c_str());
  u8g2.drawStr(10, 51, str_menu[2].c_str());

  u8g2.drawRFrame(0, 29, 125, 18, 7);
}