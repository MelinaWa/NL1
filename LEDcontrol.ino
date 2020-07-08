void LEDcontrol(int bright, int temp){
  float color = temp/1023.0;

  float blue = pwmtable[bright] * (1-color);
  float red  = pwmtable[bright] *    color ;

  int pwmblue = round(blue);
  int pwmred  = round(red);

  analogWrite(LEDblue,pwmblue);
  analogWrite(LEDred,pwmred);
}
