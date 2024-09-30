#define btn_Up 15

bool btn_pressed_toggle = false;


void btn_Setup() {
  pinMode(btn_Up, INPUT_PULLUP);
}

void btnPressed(){
  delayMicroseconds(1);

  //Add ALL buttons here
  if (status_btn_Up()) {
    btn_pressed_toggle = false;
  }
}


bool status_btn_Up() {
  return (digitalRead(btn_Up));
}