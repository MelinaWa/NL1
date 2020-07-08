void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length){

  int f1 = 0;
  int f2 = 0;
  int f3 = 0;

  if(type == WStype_TEXT){
    if(payload[0] == 'b'){

        for(int i = 0; i < length; i++){   //set flags for delimiters
           if(payload[i] == 'b'){
              f1 = i;}
           else if(payload[i] == 't'){
              f2 = i;}
           else if(payload[i] == 'e'){
              f3 = i;}
        }

        int b_length = f2 - f1 - 1;       //calculate length of variables brightness and temperature
        int t_length = f3 - f2 - 1;
  

        char teststring[f3];              //convert payload data in char array
        for(int i = 0; i < f3; i++){
          teststring[i] = payload[i];
        }
        char s_brightness[b_length];             //divide data-char-array in two char-arrays
        for(int i = f1+1; i < f2; i++){
          s_brightness[i-1] = teststring[i];
        }
        char s_temperature[t_length];
        for(int i = f2+1; i < f3; i++){
          s_temperature[i-(f2+1)] = teststring[i];
        }

        String st_brightness = String(s_brightness);     //convert char array in string
        String st_temperature = String(s_temperature);
       
        
        st_brightness.remove(b_length);                   //cut strings after last digit to prevent zeros
        st_temperature.remove(t_length);
        

        brightness  = st_brightness.toInt();          //convert strings in integers
        temperature = st_temperature.toInt();
        
        Serial.println(st_brightness);
        Serial.println(brightness);
        Serial.println("______________");
        Serial.println(st_temperature);
        Serial.println(temperature);
        Serial.println("_____________________________________________");
        LEDcontrol(brightness,temperature);

    }
    else if(payload[0] == 't'){   //Schalter ON
      bool up = true;
      LEDdim(up);
      Serial.println("t");
    }
    else if(payload[0] == 'f'){   //Schalter OFF
      bool up = false;
      LEDdim(up);
      Serial.println("f");
    }
//
//    else{
//      for(int i = 0; i < length; i++)
//        Serial.print((char) payload[i]);
//      Serial.println();
//    }
  }

  
}
