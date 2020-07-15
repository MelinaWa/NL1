void LEDcontrol(int bright, int temp){
  float color = temp/1023.0; // temp = zwischen 0 und 1023, Dezimalwerte 0 (blau) 1 (rot) 
  float blue = pwmtable[bright] * (1-color); 
  float red  = pwmtable[bright] *    color ; 

  int pwmblue = round(blue); // ganze Zahl für pwm, kein float 
  int pwmred  = round(red);

  analogWrite(LEDblue,pwmblue); // Wert senden an PIN 
  analogWrite(LEDred,pwmred);
}
