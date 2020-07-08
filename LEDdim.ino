void LEDdim(bool up){

  if(up == true){
    Serial.println("hell dimmen");
    for(int a=brightness; a <= 1023; a++){
      LEDcontrol(a,temperature);
      delayMicroseconds(1200);
    }
  }
  else{
     Serial.println("dunkel dimmen");
     for(int a=brightness; a >= 0; a--){
      LEDcontrol(a,temperature);
      delayMicroseconds(1200);
    }
  }
}
